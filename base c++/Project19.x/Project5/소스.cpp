//한번에 하나씩 순차적으로 실행하는것을 동기적 이라 부릅니다.
//반면, 실행이 한 갈래가 아니라 여러 갈래로 동시에 진행하는것을 비동기적이라 부릅니다.
//앞에서 쓰레드를 이용한 병렬처리에 대해 알아봤죠
//이번에는 task based, 작업 기반 비동기 프로그래밍을 async, future, promise의 사용법과 함께 살펴보겠습니다. 
#include<iostream>
#include<thread>
#include<future>

using namespace std;

int main() {
	//multi-threading
	if (false) {
		int result;
		thread t([&]() {result = 1 + 2; });
		t.join();
		cout << result << endl;
		//1 앞에서 사용해왔던 멀티쓰레딩의 정통적인 사용방법 입니다.
		//쓰레드에서 값을 주고 받으려면 스코프를 넓게 잡아서 스코프에 있는 변수를 여러 쓰레드들이 공유하는것이 일반적이라고 말씀드린적이 있습니다.
	}

	//task-based parallelism
	if (false) {
		auto fut = std::async([] {return 1 + 2; });
		cout << fut.get() << endl; 
		//2 쓰레드 대신 async를 사용하고 있습니다. async는 비 동기적이다 라는 단어의 약자입니다.
		//async 함수는 알아서 쓰레드를 만들고 비동기적으로 실행하고 결과를 future로 리턴합니다. (이번에도 람다함수를 사용해봤습니다)
		//fut에 커서를 갖다대면 auto로 자동으로 리탄타입인 future인걸 알 수 있습니다.
		//async에 특정한 인자를 주면 다르게 작동합니다. 궁금하면 https://modoocode.com/284#page-heading-6
		//그리고 여기서 fut.get은 fut에 값이 들어올때까지 기다립니다. 
		//간단하고 쉽게 쓰레드를 사용할수 있죠
		//실제로 일반적으로 멀티쓰레딩보다 테스크베이스드 패럴렐리즘을 더 애용한다고 합니다.
		//참고로 future는 예외도 받을수 있습니다.
	}

	if (false) {
		//3 쓰레드와 async의 중요한 차이점중 하나가 끝나는걸 알아서 대기해 해줍니다.
		//그러니까 쓰레드로 join하는것을 알아서 해줍니다.
		//근데 약간의 내부적으로 차이가 있습니다.

		auto f1 = async([] {
			cout << "async1 strat" << endl;
			this_thread::sleep_for(chrono::microseconds(2));
			cout << "async1 end" << endl;
			});

		auto f2 = async([] {
			cout << "async2 strat" << endl;
			this_thread::sleep_for(chrono::microseconds(1));
			cout << "async2 end" << endl;
			});

		cout << "main function" << endl;
		//출력의 순서를 보면 메인펑션이 먼저 나오고 f1 f2가 동시에 실행이 됩니다. 그리고 join없이도 종료되는것을 알 수 있습니다.
		//반면, async를 쓰레드로 바꿔서 실행하면 async1 start 출력되고 async2 start 출력되고 그 다음에 main function이 출력됩니다.

		//그러니까 async하고 쓰레드는 내부적으로 처리하는 방식이 조금 다릅니다.
		//지금보단 나중에 옵티마이저 작업을 들어가실때 두가지가 내부처리 방식이 다르다는것을 알고 가시면 됩니다.


		//그리고 위 코드에서 퓨처를 받아주는 f1, f2를 없애고 그냥 async만 있는 경우에는 (퓨처와 연결이 되어있지 않는 경우애는)
		//그냥 시퀀셜인것처럼(순차적으로) 작동하게 됩니다.
	}

	//future and promise
	if (true) {
		//3 복잡해 보이지만 차근차근 알아봅시다.

		std::promise<int> prom; //promise 객체를 정의할때 연산을 수행 후에 돌려줄 객체의 타입을 템플릿 인자로 받습니다. int 타입으로 만들었습니다.
								//연산이 끝난다면 promise 객체는 자신이 가지고 있는 값을 future 객체에 넣어주게 됩니다. 이때 값을 넣어줄 future 객체는
		auto fut = prom.get_future(); //get_futrue()으로 가져올수 있습니다.
									  //하지만 fut에 아직은 실제 연산 결과값을 가지고 있는게 아니죠
									  //fut에 실제 연사값을 얻으려면 prom에 연산이 끝나야 겠죠

		auto t = std::thread([](promise<int>&& pr) {pr.set_value(1 + 2); }, std::move(prom));
		//쓰레드가 실행할 람다함수를 보면 promise 객체를 R벨류로 받고 객체에 set_value로 값을 주고 잇습니다.
		//즉 move로 prom의 R벨류를 인자로 주고 set_value로 값을 입력 받으면 연산이 끝난거니까 prom의 future 객체인 fut에 넣어주게 됩니다.

		cout << fut.get() << endl;
		cout << fut.get() << endl;
		//방금 배운대로 fut.get은 fut가 값을 받을때까지 기다립니다.
		//get은 한번만 할수 있습니다. get을 호출하면 future 내부의 객체가 이동되기 때문입니다. 대신 shared_future가 있습니다. https://modoocode.com/284#page-heading-4

		t.join(); //쓰레드는 쓰레드기 때문에 메인함수가 t보다 먼저 끝나면 안되겠죠? 그래서 join으로 기다려주고 있습니다.
	}


	//multi-threading, task-based parallelism, future and promise 무엇을 사용할지는 프로그래밍 따라 다릅니다. 끝
	return 0;
}