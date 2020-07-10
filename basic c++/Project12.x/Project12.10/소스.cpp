//다형성을 사용하다보면 종종 자식클래스의 포인터를 부모클래스의 포인터로 바꿔줬다가 다시 자식클래스의 포인터로 바꿔줘야 하는 경우도 생깁니다.
//이때 사용하는 동적 형변환에 대해 설명해 드리겠습니다.
#include<iostream>

using namespace std;

class Base {
public:
	int m_i = 0;

	virtual void print() {
		cout << "i'm Base" << endl;
	}
};

class Derived1 : public Base {
public:
	int m_k = 1024;

	virtual void print() override {
		cout << "i'm Derived" << endl;
	}
};

class Derived2 : public Base {
public:
	string m_name = "Dr. Two";
	
	virtual void print() override{
		cout << "i'm derived2" << endl;
	}
};

int main() {
	Derived1 d1;
	Base* base = &d1;

	base->print();

	return 0;
}