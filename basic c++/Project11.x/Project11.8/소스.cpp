//����̶�°��� �⺻������ �޾ƿ��� ���̴� �׷��� ���� ������ ������ ������ �θ�κ��� ���� �ͼ� ����ϴ°� ���ַ� ������ ��Ƚ��ϴ�.
//�̹����� �ݴ�� ��� �޴°� ������� ���ϵ��� ���¹���� �˾ƺ��ô�.
#include<iostream>

using namespace std;

class Base
{
protected:
	int m_i;
public:
	Base(int value)
		:m_i(value)
	{}
	void print()
	{
		cout << "i'm base" << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;
public:
	Derived(int value)
		:Base(value)
	{}
	using Base::m_i; //2 �ۺ� �Ʒ��� using�� ����ϸ� �� m_i�� Derived �ȿ����� �ۺ��� �ȴ�.

	void print() = delete; //8 �Ǵ� delete�� ����ؼ� �ڽ�Ŭ���������� ����������ϰ� ������ ����. ��
private:
	using Base::print;//��ȣ ġ�� ���� //5 �����̺� �Ʒ����� �ϸ��
};

int main()
{
	Derived derived(7);
	//1 2derived.m_i = 1024; //1 2�翬�� ������Ƽ��ϱ� �ȵȴ�. �׷��� �̰� �ٲ� �� �ִ�.
	derived.m_i = 1024; //3 �̹����� ����
	derived.print(); //4 derived�� ��ӹ��� Base�� print�� �翬�� ����� �� �ִ�. �̹����� �̰� �ۿ��� �������� ���ϵ��� ���ƺ���.
					//6 �۵� �ȵ���?
	Base base(5);
	base.print(); //7 �θ𿡼��� print�� �����ϴ�.
					//���⿡�� ���°����� ��������� �ٸ����� using�� ���� ���Ƴְų� �ƹ�ư ����Ҳ��� �����ϴ°� ��õ��

	return 0;
}