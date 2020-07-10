//다형성은 편리하고 유연성을 제공하지만 모든경우에서 다형성을 사용할수는 없습니다.
//대표적은 예가 출력 연산자인데요 출력 연산자는 우리가 아주 유용하게 사용하는 연산자 입니다. 하지만 오버라이딩을 할수 없습니다.
//유도클래스(자식클래스)에서 출력연산자를 다형성과 함께사용하려면 어떻개 해야하는지 알아봅시다.
#include<iostream>

using namespace std;

class Base {
public:
	Base() {}

	friend ostream& operator << (ostream& out, const Base& b) {
		return b.print(out);
	}

	virtual ostream& print(ostream& out) const {
		out << "Base";
		return out;
	}
};

class Derived : public Base {
public:
	Derived() {}

	virtual ostream& print(ostream& out) const override {
		out << "Derived";
		return out;
	}
};

int main() {
	Base b;
	cout << b << '\n';

	Derived d;
	cout << d << '\n';

	Base& bref = d;
	cout << bref << '\n';
	
	//딱히 설명이 필요 없다.


	return 0;
}