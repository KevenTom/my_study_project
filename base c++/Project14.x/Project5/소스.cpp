//클래스의 생성자에서 발생하는 예외를 처리하는것도 중요하는데요
//이때 이니셜라이져 리스트에 발생하는 예외를 처리할때 많이 사용하는 "함수 try"에 대해 알아봅시다.
#include<iostream>

using namespace std;

class A {
	int m_x;
public:
	A(int x)
		:m_x{ x } {
		if (x <= 0)
			throw - 1;
	}
};
class B : public A {
public:
	//3 2B(int x)
	//	: A(x) //2 근데 어떤 경우에는 이니셜라이저리스트에서 바로 캐치를 하고싶을때가 있죠
	//{}
	B(int x) try :A(x) { //3 2이럴때 펑션try를 사용합니다.

	}
	catch (...) {
		cout << "catch in classB()" << endl;
		//4 throw; 참고로 throw가 없다고 해도 throw가 있는것처럼 작동합니다. 끝
	}
};

int main() {
	try{
		B b(0);
	}
	catch (...) {
		cout << "catch in main()" << endl; //1 문제없이 예외를 잡는것을 알 수 있다.
	}

	return 0;
}