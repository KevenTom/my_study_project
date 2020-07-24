//���ݱ��� ��Ƽ�������� ����ϴ� �������� ������ �˾ƺý��ϴ�.
//�̹����� ��Ƽ���������� ���ͳ�������ϴ� ������ ���ؼ� ���������� ��� ���Ǵ��� �˾ƺ��ô�.
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
//����� �����ϱ� ���������Դϴ�. ���������� ������� �ʴ°� �����ϴ�.
//�ӵ��� Ȯ���ϴ°Ŵϱ� release x64�� �����߽��ϴ�.



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
	//1 ������ ���� �����ϰ� �˾ƺ��ô�.
	//v0 = {1, 2, 3}
	//v1 = {4, 5, 6}
	//vo_dot_v1 = 1*4 + 2*5 + 3*6;
	//�밭 ���ذ���?


	const long long n_data = 100'000'000;
	const unsigned n_threads = 4;
	//n_data�� ������ �� �Դϴ�.
	//n_threads�� ����� ������ �����Դϴ�.

	std::vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);
	//�׽�Ʈ�� ���� 2���� ��������ϴ�. reserve�� �̸� �����͸� �Ҵ��� �����ϴ�.

	random_device seed;
	mt19937 engine(seed()); 
	uniform_int_distribution<> uniformDist(1, 10);
	//���������⸦ �غ��߽��ϴ�. (���ø��� �ƹ��͵� �ȳ����� int�� �˴ϴ�)

	for (long long i = 0; i < n_data; ++i) {
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}
	//�׸��� ������ �� ���Ϳ� n_data��ŭ push_back ���ݴϴ�.
	 





	//4 ó������ �����带 ������� �ʰ� �׳� ����� �ý��ϴ�.
	cout << "std::inner_product" << endl;
	{
		const auto sta = chrono::high_resolution_clock::now();
		//chrono�� clock���� ���۵� �������� ���� ����� ƽ�� �߻��ϴ��� �˼� �ֽ��ϴ�.

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);
		//inner_product�� �� ������ ����ϴ� �˰��� �Դϴ�.
		// 4��° ���ڴ� �ʱⰪ�ε� 0ull�� unsigned long long�� ���ϱ� ������ auto�� ����ε� �շ� Ÿ������ �������ϴ�.(0�� �־��ָ� int�� �����)

		const chrono::duration<double> dur = chrono::high_resolution_clock::now() - sta;
		//���� �������� ���� �˰������ �� ��ð� �ɷȴ��� Ȯ���ϰ� ���ݴϴ�.

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}





	//5 �̹����� ��Ƽ���������� �۵��ϰ� ����� ���ô�.
	//����� ����ó�� ���α׷����� �Ҷ��� ���� ���� �Ǽ��Ͻ� �� �ֽ��ϴ�.
	//�׷��� ��Ƽ������ ���α׷��� ����ٸ� ��ó�� ���� ������ ����� ���� ���α׷��� �񱳸� �ϰ� �� �����ս��� ���ϴ� ������� �۾��ϴ°��� �����ϴ�.
	//�ڵ尡 ������ ������ ������ ������ ����Ҽ� �ְ� �ϱ� ���ؼ� ���� �ڵ尡 �����Ҽ� �ֽ��ϴ�.
	cout << "native" << endl;
	{
		const auto sta = chrono::high_resolution_clock::now();

		unsigned long long sum = 0;
		//������� �־��� ���� sum�Դϴ�.

		vector<thread> vector_threade(n_threads);
		//�������� ���͸� n_threads��ŭ ��������ϴ�.

		const unsigned n_per_thread = n_data / n_threads;
		//�׸��� ������ �����忡�� ���� ������߰���
		//����� �������� 0�� ��츦 �����߽��ϴ�. ���� n_data�� �����尳���� ������ �������� �ִٸ� �ڵ嵵 �׿��°� �й��ؾ߰���?

		for (int t = 0; t < n_threads; ++t)
			vector_threade[t] = thread(dotProductNaive, ref(v0), ref(v1), t * n_per_thread, (t + 1) * n_per_thread, ref(sum));
		//������_���Ϳ� �����带 �ְ� �ֽ��ϴ�.
		//�Լ����� �Ķ���͸� ���۷����� �����ϱ� ref�� ��ø� ���ְ� �ְ� ������ ������ �ְ� ���� ���� ���� sum ������ ���۷����� �ְ� �ֽ��ϴ�.

		for (int t = 0; t < n_threads; ++t)
			vector_threade[t].join();
		//�����带 ��ٷ� �ְ� �ֽ��ϴ�.


		const chrono::duration<double> dur = chrono::high_resolution_clock::now() - sta;
		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
		//�׷��� �����ϸ� ���� �ȸ���??
		//������ ��� race condition ������ �׷��̴ϴ�. ���� �����尡 sum�� ���ÿ� �ǵ�ϱ� �׷��̴ϴ�.
		//�ذ����� �־���? atomic�� lock_guard�� future�� �ֽ��ϴ�.
	}
	




	//6 ù��°�� �����带 �̿��ϴ� ����Դϴ�.
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
		//�����带 �ϴϱ� natuve���� �ӵ��� ��û �����ϴ�.
		//������� �������� �������� �ִ°��� ������ for��ó�� ����ϰ� �ִ°��� ������ �������ϴ�. 

		//7 2�׷��� �����带 for�� �ۿ� ���ƺý��ϴ�.
		//�̹����� �����尡 ���� native���� ������ �ξ� ���������ϴ�.
		//�ٵ� �̷��� ��Ƽ�������� ���ִ� �ǹ̰� �������ϴ�. 
		//�ֳĸ� ������1�� ������ ������2�� �ϰ� ������2�� ������ ������3�� �ϰ�, �ᱹ ���������� �����ϰ� �˴ϴ�.

		//�׷��� �� ���������� ������ ��Ƽ�������� �ǹ̰� �������ϴ�.
		//�׷��� ��Ƽ�������� �Ѵٰ� �ؼ� ���δ� �������°��� �ƴմϴ�.
	}





	//8 �ι�°�� atomic�� ����ϴ� ����Դϴ�.
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
		//����� �� ���Դµ� �����ϴ�.
		//����� ������ �Ϲ� ���꿡 ���� �����ϴ�.
		//�׷��� ����Ϳ����� ���� ����ϰ� �۵��ϰ� �ֱ� ������ �������ۿ� �����ϴ�.
	}





	//9 ����°�� future�� �ֽ��ϴ�.
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
		//future<int>�� �ϴ� ������ ������ �κ��� ���� int ���� ���̱� ������ �׳� int�� �߽��ϴ�.
		//future�� ������ ����� �ϴϱ� dotProductFuture�� ����Ÿ���� int �Դϴ�. �Լ� �۵� ����� �������� sumsum�� ���ϱ⸦ ���ְ� �� ���� �������ִ� ����Դϴ�.
		//�׸��� sum�� future�� ���� ������ ���ϸ� ���Դϴ�. vector_future�� ���� ������� ��ŭ�̴ϱ� 6���ۿ� �ȵ���
		//����� �� ������ �ӵ��� �����ϴ�.

		//�ٸ� ��Ƽ�������� ���� �۵� ����� �ణ �ٸ���
		//�ٸ� ��Ƽ�������� sum�̶�� ������ ��� �������� �޷�����ٸ�
		//���⼭�� �Լ����� �κ����� ���� ���ϰ� �� ���� ���������� ���ϴ� ����Դϴ�.

		//�׷��ٰ� ǻó�� ���°� ���������ٰ� �����ϽǼ� �ִµ� �� �׷����� �ʽ��ϴ�. �ᱹ ��Ȳ�� ���� �ٸ��ϴ�.
	}

	//10 �ٵ� ��� inner_product�� c++������ ���Ĺ����� transform_reduce�� �ֽ��ϴ�. (���� ������ ���� ������ ���κ�)
	//�� �ܿ��� �⺻���� sort���� �Լ����� ���� ����ó���� ������ ���ݴϴ�.
	//�׷��� �⺻���ΰ͵��� �����ϽǶ��� ����ó���� ���� �������� �ʿ�� �����ϴ�.

	//������ std���� ������� ����ó���ڵ���� ��繮������ ����ó���������� �ʽ��ϴ�.


	//���� :: �׿ܿ��� �������� �������� ��Ƽ�������� ������ �� �ֽ��ϴ�. ��

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