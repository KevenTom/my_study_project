//Ŭ������ �����ڿ��� �߻��ϴ� ���ܸ� ó���ϴ°͵� �߿��ϴµ���
//�̶� �̴ϼȶ����� ����Ʈ�� �߻��ϴ� ���ܸ� ó���Ҷ� ���� ����ϴ� "�Լ� try"�� ���� �˾ƺ��ô�.
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
	//	: A(x) //2 �ٵ� � ��쿡�� �̴ϼȶ���������Ʈ���� �ٷ� ĳġ�� �ϰ�������� ����
	//{}
	B(int x) try :A(x) { //3 2�̷��� ���try�� ����մϴ�.

	}
	catch (...) {
		cout << "catch in classB()" << endl;
		//4 throw; ����� throw�� ���ٰ� �ص� throw�� �ִ°�ó�� �۵��մϴ�. ��
	}
};

int main() {
	try{
		B b(0);
	}
	catch (...) {
		cout << "catch in main()" << endl; //1 �������� ���ܸ� ��°��� �� �� �ִ�.
	}

	return 0;
}