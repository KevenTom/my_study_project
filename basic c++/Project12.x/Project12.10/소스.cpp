//�������� ����ϴٺ��� ���� �ڽ�Ŭ������ �����͸� �θ�Ŭ������ �����ͷ� �ٲ���ٰ� �ٽ� �ڽ�Ŭ������ �����ͷ� �ٲ���� �ϴ� ��쵵 ����ϴ�.
//�̶� ����ϴ� ���� ����ȯ�� ���� ������ �帮�ڽ��ϴ�.
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