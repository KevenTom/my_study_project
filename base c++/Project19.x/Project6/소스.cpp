//지금까지 멀티쓰레딩을 사용하는 여러가지 문법을 알아봤습니다.
//이번에는 멀티쓰레딩으로 백터내적계산하는 예제를 통해서 실제문법이 어떻게 사용되는지 알아봅시다.
#include<iostream>
#include<vector>
#include<random>
#include<numeric>
#include<chrono>
#include<thread>
#include<mutex>
#include<atomic>
#include<future>

using namespace std;

mutex mtx; 
//참고로 예제니까 전역변수입니다. 전역변수는 사용하지 않는게 좋습니다.
//속도를 확인하는거니까 release x64로 설정했습니다.



void dotProductNaive(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, unsigned long long& sum) {
	for (unsigned i = i_start; i < i_end; ++i)
		sum += v0[i] * v1[i];
}

void dotProductLockGuard(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, unsigned long long& sum) {
	for (unsigned i = i_start; i < i_end; ++i) {

		scoped_lock lock(mtx);

		sum += v0[i] * v1[i];
	}
}

void dotProductLockGuard2(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, unsigned long long& sum) {
	scoped_lock lock(mtx);

	for (unsigned i = i_start; i < i_end; ++i) {
		sum += v0[i] * v1[i];
	}
}

void dotProductatomic(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum) {
	for (unsigned i = i_start; i < i_end; ++i)
		sum += v0[i] * v1[i];
}

int dotProductFuture(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end) {
	int sumsum = 0;
	for (unsigned i = i_start; i < i_end; ++i)
		sumsum += v0[i] * v1[i];
	return sumsum;
}

auto dotProductPromise(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, promise<int>* vector) {
	int sumsum = 0;
	for (unsigned i = i_start; i < i_end; ++i)
		sumsum += v0[i] * v1[i];
	vector->set_value(sumsum);
}


int main() {
	//1 내적이 뭔지 간단하게 알아봅시다.
	//v0 = {1, 2, 3}
	//v1 = {4, 5, 6}
	//vo_dot_v1 = 1*4 + 2*5 + 3*6;
	//대강 이해가죠?


	const long long n_data = 100'000'000;
	const unsigned n_threads = 4;
	//n_data는 내적의 수 입니다.
	//n_threads는 사용할 쓰레드 갯수입니다.

	std::vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);
	//테스트할 백터 2개를 만들었습니다. reserve로 미리 데이터를 할당해 놨습니다.

	random_device seed;
	mt19937 engine(seed()); 
	uniform_int_distribution<> uniformDist(1, 10);
	//난수생성기를 준비했습니다. (템플릿에 아무것도 안넣으면 int가 됩니다)

	for (long long i = 0; i < n_data; ++i) {
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}
	//그리고 난수를 각 백터에 n_data만큼 push_back 해줍니다.
	 





	//4 처음에는 쓰레드를 사용하지 않고 그냥 계산해 봤습니다.
	cout << "std::inner_product" << endl;
	{
		const auto sta = chrono::high_resolution_clock::now();
		//chrono의 clock들은 시작된 시점으로 부터 몇번의 틱이 발생하는지 알수 있습니다.

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);
		//inner_product은 두 내적을 계산하는 알고리즘 입니다.
		// 4번째 인자는 초기값인데 0ull은 unsigned long long을 뜻하기 때문에 auto가 언사인드 롱롱 타입으로 잡아줬습니다.(0만 넣어주면 int로 잡아줌)

		const chrono::duration<double> dur = chrono::high_resolution_clock::now() - sta;
		//시작 시점으로 부터 알고리즘수행 후 몇시간 걸렸는지 확인하게 해줍니다.

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}





	//5 이번에는 멀티쓰레딩으로 작동하게 만들어 봅시다.
	//참고로 병렬처리 프로그래밍을 할때는 정말 자주 실수하실 수 있습니다.
	//그래서 멀티쓰레딩 프로그램을 만든다면 위처럼 먼저 정답을 만들고 만든 프로그램과 비교를 하고 또 퍼포먼스를 비교하는 방식으로 작업하는것이 좋습니다.
	//코드가 쓰레드 개수를 임의의 개수를 사용할수 있게 하기 위해서 조금 코드가 복잡할수 있습니다.
	cout << "native" << endl;
	{
		const auto sta = chrono::high_resolution_clock::now();

		unsigned long long sum = 0;
		//결과값을 넣어줄 변수 sum입니다.

		vector<thread> vector_threade(n_threads);
		//쓰레드의 백터를 n_threads만큼 만들었습니다.

		const unsigned n_per_thread = n_data / n_threads;
		//그리고 각각의 쓰레드에게 일을 나눠줘야겠죠
		//참고로 나머지가 0인 경우를 가정했습니다. 만약 n_data와 쓰레드개수와 나눌때 나머지가 있다면 코드도 그에맞게 분배해야겠죠?

		for (int t = 0; t < n_threads; ++t)
			vector_threade[t] = thread(dotProductNaive, ref(v0), ref(v1), t * n_per_thread, (t + 1) * n_per_thread, ref(sum));
		//쓰레드_백터에 쓰레드를 주고 있습니다.
		//함수에서 파라미터를 레퍼런스로 받으니까 ref로 명시를 해주고 있고 수행할 범위를 주고 계산된 값을 받을 sum 변수를 레퍼런스로 주고 있습니다.

		for (int t = 0; t < n_threads; ++t)
			vector_threade[t].join();
		//쓰레드를 기다려 주고 있습니다.


		const chrono::duration<double> dur = chrono::high_resolution_clock::now() - sta;
		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
		//그런데 실행하면 답이 안맞죠??
		//저번에 배운 race condition 때문에 그런겁니다. 각각 쓰레드가 sum을 동시에 건드니까 그런겁니다.
		//해결방법이 있었죠? atomic과 lock_guard과 future가 있습니다.
	}
	




	//6 첫번째로 락가드를 이용하는 방법입니다.
	cout << "lock_guard" << endl;
	{
		const auto sta = chrono::high_resolution_clock::now();

		unsigned long long sum = 0;

		vector<thread> vector_threade(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (int t = 0; t < n_threads; ++t)
			//7 2vector_threade[t] = thread(dotProductLockGuard, ref(v0), ref(v1), t * n_per_thread, (t + 1) * n_per_thread, ref(sum));
			vector_threade[t] = thread(dotProductLockGuard2, ref(v0), ref(v1), t * n_per_thread, (t + 1) * n_per_thread, ref(sum));

		for (int t = 0; t < n_threads; ++t)
			vector_threade[t].join();

		const chrono::duration<double> dur = chrono::high_resolution_clock::now() - sta;
		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
		//락가드를 하니까 natuve보다 속도가 엄청 느립니다.
		//락가드는 스코프가 적은곳에 있는곳이 좋지만 for문처럼 빈먼하게 있는곳에 있으면 느려집니다. 

		//7 2그러면 락가드를 for문 밖에 놓아봤습니다.
		//이번에는 락가드가 없는 native보다 오히려 훨씬 빨라졌습니다.
		//근데 이러면 멀티쓰레딩을 해주는 의미가 없어집니다. 
		//왜냐면 쓰레드1이 끝나면 쓰레드2가 하고 쓰레드2가 끝나면 쓰레드3이 하고, 결국 순차적으로 진행하게 됩니다.

		//그래서 이 예제에서는 오히려 멀티쓰레딩이 의미가 없어집니다.
		//그래서 멀티쓰레딩을 한다고 해서 전부다 빨라지는것은 아닙니다.
	}





	//8 두번째로 atomic을 사용하는 방법입니다.
	cout << "atomic" << endl;
	{
		const auto sta = chrono::high_resolution_clock::now();

		atomic<unsigned long long> sum = 0;

		vector<thread> vector_threade(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (int t = 0; t < n_threads; ++t)
			vector_threade[t] = thread(dotProductatomic, ref(v0), ref(v1), t * n_per_thread, (t + 1) * n_per_thread, ref(sum));

		for (int t = 0; t < n_threads; ++t)
			vector_threade[t].join();

		const chrono::duration<double> dur = chrono::high_resolution_clock::now() - sta;
		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
		//결과는 잘 나왔는데 느립니다.
		//아토믹 연산이 일반 연산에 비해 느립니다.
		//그런데 아토믹연산이 아주 빈번하게 작동하고 있기 때문에 느릴수밖에 없습니다.
	}





	//9 세번째로 future가 있습니다.
	cout << "future" << endl;
	{
		const auto sta = chrono::high_resolution_clock::now();

		unsigned long long sum = 0;

		vector<future<int>> vector_futures(n_threads);

		const unsigned n_per_thread = n_data / n_threads;
		for (int t = 0; t < n_threads; ++t)
			vector_futures[t] = std::async(dotProductFuture, ref(v0), ref(v1), t * n_per_thread, (t + 1) * n_per_thread);

		for (int t = 0; t < n_threads; ++t)
			sum += vector_futures[t].get();

		const chrono::duration<double> dur = chrono::high_resolution_clock::now() - sta;
		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
		//future<int>로 하는 이유는 수행할 부분의 합은 int 범위 안이기 때문에 그냥 int로 했습니다.
		//future에 리턴을 해줘야 하니까 dotProductFuture의 리턴타입은 int 입니다. 함수 작동 방식은 전역변수 sumsum에 더하기를 해주고 그 값을 리턴해주는 방식입니다.
		//그리고 sum에 future에 계산된 값들을 더하면 끝입니다. vector_future의 수는 쓰레드수 만큼이니까 6개밖에 안되죠
		//결과도 잘 나오고 속도도 빠릅니다.

		//다른 멀티쓰레딩에 비해 작동 방식이 약간 다르죠
		//다른 멀티쓰레딩은 sum이라는 변수에 모든 쓰레딩이 달려들었다면
		//여기서는 함수에서 부분적인 합을 구하고 그 합을 최종적으로 더하는 방식입니다.

		//그렇다고 퓨처를 쓰는게 무조건좋다고 생각하실수 있는데 꼭 그렇지는 않습니다. 결국 상황에 따라 다릅니다.
	}

	//10 근데 사실 inner_product는 c++에서는 병렬버전인 transform_reduce가 있습니다. (굳이 넣지는 않음 동영상 끝부분)
	//그 외에도 기본적인 sort같은 함수들이 전부 병렬처리를 지원해 해줍니다.
	//그래서 기본적인것들을 구현하실때는 병렬처리를 직접 구현해줄 필요는 없습니다.

	//하지만 std에서 만들어준 병렬처리코드들이 모든문제들을 병렬처리해주지는 않습니다.


	//문제 :: 그외에도 여러가지 조합으로 멀티쓰레딩을 수행할 수 있습니다. 끝

	cout << "test" << endl;
	{
		const auto sta = chrono::high_resolution_clock::now();

		unsigned long long sum = 0;

		vector<promise<int>> vector_futures(n_threads);
		vector<future<int>> fut(n_threads);
		vector<thread> vector_thread(n_threads);

		for (int t = 0; t < n_threads; ++t)
			fut[t] = vector_futures[t].get_future();

		const unsigned n_per_thread = n_data / n_threads;
		for (int t = 0; t < n_threads; ++t)
			vector_thread[t] = thread(dotProductPromise, ref(v0), ref(v1), t * n_per_thread, (t + 1) * n_per_thread, &vector_futures[t]);


		for (int t = 0; t < n_threads; ++t)
			sum += fut[t].get();

		const chrono::duration<double> dur = chrono::high_resolution_clock::now() - sta;
		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;

		for (int t = 0; t < n_threads; ++t)
			vector_thread[t].join();
	}

	return 0;
}