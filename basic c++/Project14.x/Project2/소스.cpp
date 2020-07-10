//함수가 함수를 호출하고 그 함수가 다시 다른 함수를 호출한다면 스택에 호출구조가 착착착착 쌓여나가겠죠
//만약에 가장 마지막에 있는 함수가 예외를 던진다면 스택을 되감아 가면서 어디서 예외를 받을지 찾게됩니다.
//여기서는 예외처리와 스택 되감기(stack unwinding)에 대해 알아봅시다.
#include<iostream>

using namespace std;

//10 2void last() throw(int) { //10 2이런 문법도 존재한다. exception specifier 이라고 부르는데 함수 뒤에 hrow(int) 붙여주면 int타입의 예외를 쓰로우 할수도 있다라는 의미가 되는데 이 exception specifier는 거의 사용하지 않는다. 사실 int가 아니라 내부적으로 다 ... 으로 바꾼다고 한다 그냥 알아두라 한다 근데 필요없어보임
void last() {
	cout << "last" << endl;
	cout << "Throws exception" << endl;

	throw - 1; //4 throw 를 하면 다음코드들은 실행하지 않고 바로 날려버린다.

	cout << "End last" << endl;
}

void third() {
	cout << "third" << endl;

	last(); //5 그다음 third로 와도 endthird를 호출하지 않는다. 즉 못잡으면 계속 날라간다.

	cout << "End third" << endl;
}

void second() {
	cout << "second" << endl;

	try {
		third();
	}
	catch (double) {//6 캐치가 있음에도 불과하고 double이니까 날라감.
		cerr << "second caught int exception" << endl;
	}

	cout << "End second" << endl;
}

void first() {
	cout << "first" << endl;
	
	try {
		second();
	}
	catch (int) { //3 throw 하자마자 바로 first catch로 날라왔다. 어떻게 된 일이지?
		cerr << "first caught int exception" << endl;
	}//7 쭉 무시하고 오다가 맞는 catch가 있으니까 그 다음부터 실행하는 것을 알 수 있다.

	cout << "End first" << endl;
}

int main() {
	cout << "start" << endl;

	try { //2 디버그로 찍어서 보면
		first();
	}
	catch (int) {
		cerr << "main caught int exception" << endl;
	}

	//1 cerr이 생소할수 있는데 씨아웃(cout), 씨에러(cerr), 씨로그(clog) 3가지가 있는데 3가지의 차이는
	//기능상 차이는 없고 로그를 출력해주는 "채널"이 3가지가 있다. 정도만 아셔도 됩니다.
	//예를들어 뉴스를보다가 예능을 출력한다던지 같은 식으로 사용함
	//cout 같은 경우에는 출력을 버퍼에 담아놓고 바로바로 안할때도 있거든요 그래서 endl; 을 붙여주면 플러쉬도 바로 하고 줄바꿈도 해주는 두가지 기능을 동시에 수행해줍니다.
	//cerr 같은 경우에는 긴급하죠. 그래서 endl; 없어도 바로 출력을 한다고 합니다. 그냥 그럴수 있다정도만 알아도 된다.

	//8 근데 만약 아예 싹다 캐치를 못하는 경우에는 어떻게 될까? 당연히 런타임에러가 뜬다. 또다른 방법으로 모두 잡는 캡쳐를 만들면 된다. 최후의 보루 같은 느낌
	catch (...) { //9 ellipses(...)을 넣어주면 어떤타입이든 다 받아준다 라는 의미가 된다.
		cerr << "ellipses exception" << endl;
	}

	cout << "end main" << endl;



	return 0;
}