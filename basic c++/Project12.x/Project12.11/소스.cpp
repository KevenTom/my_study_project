//�������� ���ϰ� �������� ���������� ����쿡�� �������� ����Ҽ��� �����ϴ�.
//��ǥ���� ���� ��� �������ε��� ��� �����ڴ� �츮�� ���� �����ϰ� ����ϴ� ������ �Դϴ�. ������ �������̵��� �Ҽ� �����ϴ�.
//����Ŭ����(�ڽ�Ŭ����)���� ��¿����ڸ� �������� �Բ�����Ϸ��� ��� �ؾ��ϴ��� �˾ƺ��ô�.
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
	
	//���� ������ �ʿ� ����.


	return 0;
}