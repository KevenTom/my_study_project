//최근에 cpu들은 거의다 멀티코어를 가지고 있습니다.
//우리가 교과서에 배우는 프로그래밍 기술들은 단일코어로 가정하고 하나의 프로세스에서 순차적으로 작업하는것을 위주로 가르칩니다.
//하지만 최근에는 당연히 멀티코어를 충분히 적절히 사용할수 있는 프로그래밍 능력을 갖춰주고 있어야 합니다.
//여기서는 std::thread와 멀티쓰레딩의 기초적인 개념에 대해서 설명해 드리겠습니다
//개념설명 ~10:53
//개념설명2 https://modoocode.com/269
#include<iostream>
#include<thread>
#include<vector>
#include<mutex> //mutex는 mutual exclusion(상호 배제)의 약자입니다.

using namespace std;


mutex mtx;


int main() {
	if (false) {
		cout << std::thread::hardware_concurrency() << endl;
		//1 컴퓨터에 코어가 몇개있는지 확인해봄 -> 코어 6개, 논리 프로세서 6개
		
		while (true) {} 
		//지금까지 프로그래밍한 방식은 main의 한 줄기만을 쭉 따라가는 겁니다.
		//즉, 우리가 메인을 실행한다는 것은 하나의 프로세서를 사용한다는 겁니다.
		//그리고 프로세서 하나를 차지한다는 것은 논리 프로세서 하나를 사용한다고 보시면됩니다.


		//그렇다면 하나의 프로세서에 논리프로세서를 6개 다 활용한다면 어느 작업이든 빠르게 작동하지 않을까?
		//이것이 멀티쓰레딩의 기본 취제입니다.
	}


	if (true) {
		const int num_pro = std::thread::hardware_concurrency();
		//2 컴퓨터마다 논리프로세서가 다르니까 직접 변수로 받아서 어떻게 사용할지 조정할수도 있습니다.


		//3 멀티쓰레딩을 간단하게 만들어 봅시다.
		//할 일을 함수로 넣어주면 됩니다. 전에 배운 람다함수를 넣어봤습니다.
		std::thread t1 = std::thread([]() {
			cout << "thread id : " << std::this_thread::get_id() << endl; //7 멀티쓰레딩 된 곳에도 넣어줬습니다.
			while (true) {}});
		//4 그런데 이상태에서 실행해보면 작동하다 에러가 납니다.
		//작동되는 과정을 보면 메인 함수가 어떤 쓰레드에서 작동합니다. 
		//그리고 위 코드로 그 쓰레드에서 다른 쓰레드를 실행시킵니다.
		//그러면 새로 생긴 쓰레드는 원래 자기를 실행시킨 쓰레드와 상관없이 작동합니다.
		//그런데 문제가 뭐냐면 새로 만든 쓰레드가 작동중인데 메인함수가 끝나버린겁니다. 그래서 에러가 발생합니다.
		//C++ 표준에 따르면, join 되거나 detach 되지 않는 쓰레드들의 소멸자가 호출된다면 예외를 발생시키도록 명시되어 있습니다.


		//6 확인해보기 위해 쓰레드의 아이디를 출력해 봅시다.
		//아래는 메인함수가 실행되고있는 쓰레드의 아이디를 출력해주고 있습니다.
		cout << "main id : " << std::this_thread::get_id() << endl;
		//8 서로 다른 아이디를 가지고 있다는것을 확인할 수 있습니다.
		//쓰레드가 어떤 코어에 배정할지는 상황에 맞게 바뀌기 때문에 정확히 알수 없습니다. 


		//5 join으로 t1이 끝날때까지 기다려주면 메인함수가 끝나기 않고 정상적으로 작동 합니다.
		t1.join();
		//detach는 thread 오브젝트에 연결된 스레드를 떼어냅니다.
		//t1.detach();
	}

	
	if (false) {
		//9 이번에는 쓰레드를 여러개 만들어 보겠습니다.
		//출력이 겹치는걸 볼수 있는데 이는 동시에 실행되고 있기 때문에 그런겁니다. 
		//출력이 겹치는걸 해결하기 위해 mutex를 사용했습니다. 자세한 원인은 다음강의에서 말씀드리겠습니다.

		std::thread t1 = std::thread([]() {
			mtx.lock(); //10 mtx를 넣어봤습니다. lock한 부분에서 작업을 멈췄다가
			cout << "thread id : " << std::this_thread::get_id() << endl;
			mtx.unlock(); //11 unlock으로 다시 작동하게 하고
			while (true) {}});

		std::thread t2 = std::thread([]() {
			mtx.lock(); //다시 잠구고
			cout << "thread id : " << std::this_thread::get_id() << endl;
			mtx.unlock(); //다시 푸는 과정을 거칩니다. 이럼으로써 lock한 부분은 순차적으로 나올수 있게 할수 있습니다.
			while (true) {}});

		std::thread t3 = std::thread([]() {
			mtx.lock();
			cout << "thread id : " << std::this_thread::get_id() << endl;
			mtx.unlock();
			while (true) {}});

		std::thread t4 = std::thread([]() {
			mtx.lock();
			cout << "thread id : " << std::this_thread::get_id() << endl;
			mtx.unlock();
			while (true) {}});

		//12 쓰레드로 여러개 시키고 있으니까 cpu 사용량이 높은것을 알수 있습니다.
		//이렇게 사용하는 방법도 있고 백터를 이용하는 방법도 있습니다.

		t1.join();
		t2.join();
		t3.join();
		t4.join();
	}

	if (false) {
		//13 멀티쓰레드에 벡터를 이용하는 방법도 있습니다.
		const int num_pro = std::thread::hardware_concurrency();
		vector<thread> my_threads;
		my_threads.resize(num_pro);

		for (auto& e : my_threads)
			e = thread([]() { while (true) {} });

		for (auto& e : my_threads)
			e.join();

		//일반적으로는 멀티 쓰레딩을 할때 우리가 실행시키는 쓰레드 개수하고 하드웨어가 가지고 있는 프로세서의 개수를 맞추는게 일반적인데 
		//절대라는건 없듯이 가끔 다르게 해줄때도 있습니다. 그냥 알아만 두라고 끝
	}


	return 0;
}