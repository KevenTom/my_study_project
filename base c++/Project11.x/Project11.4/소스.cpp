//�հ��ǿ����� ������ Ŭ�������� ������ ȣ�� ������ ���� �ð��. �̹����� ������ �ʱ�ȭ�� �ʹ� ��ǥ����
#include <iostream>

using namespace std;

class Mother
{
public:
	int m_i;
public:
	Mother(const int& i_in = 0)
		:m_i(i_in)
	{
		cout << "Mothet construction" << endl;
	}
};

class Child : public Mother //2 �̋� ���ϵ�Ŭ������ �������� ����������� �����ϱ� int�� �ְ���?? ���� ���ϵ�� 8����Ʈ�� ������ �ִ�.
{
public:
	//3 2float m_d; //3 2 �ѹ� ����� �ٲ㺸��. ������ 8����Ʈ�ϱ� 8+4=12 ����?? ���� 16����Ʈ�� ����
	double m_d;
	int m_temp; //4 �̻��ϳ� �̹����� ��������� int�� �߰��� �ô�. 24�� ������? �̷��� ������ �е�(padding)�̶� �Ѵ�. ���������� ���� ����� �Ѵ�.
				//���⼭ �߿��Ѱ��� ���ϵ� Ŭ�������� �޸𸮸� �Ҵ� �ҋ��� ����Ŭ������ �ִ°͵� �� ���� ������ŭ ũ�� ��´�.
public:
	Child()
		:m_d(1.0f), Mother(1024)
	{
		cout << "Cgild construction" << endl;
	}
};


class A
{
public:
	A(int a)
	{
		cout << "A: " << a << endl;
	}
	~A()
	{
		cout << "Destructor A" << endl;
	}
};
class B : public A
{
public:
	B(int s,double b)
		:A(s)
	{
		cout << "B: " << b << endl;
	}
	~B()
	{
		cout << "Destructor B" << endl;
	}
};
class C : public B
{
public:
	C(int a, double b, char c)
		:B(a, b)
	{
		cout << "C: " << c << endl;
	}
	~C()
	{
		cout << "Destructor C" << endl;
	}
};

int main()
{
	Child c1;

	cout << sizeof(Mother) << endl; //1 �̹����� �ѹ� ���ϵ�� ������ ����� Ȯ���� ����.
	cout << sizeof(Child) << endl;
	cout << endl;

	C c(1024, 3.14, 'a');//5 �����ǿ��� �����ϰ� ����ߴ���ó�� ������ �Ҹ��� ������ Ȯ���ϴ� �ڵ��̴�. ��

	return 0;
}