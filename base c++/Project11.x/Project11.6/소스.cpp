//�̹����� ������ Ŭ������ (�ڽ�Ŭ������)���ο� ����� �߰��ҋ� �����ص־����� ����� �Ұ��� �帮�ڽ��ϴ�.
#include <iostream>

using namespace std;

class Base
{
//4 2private: //4 2�ذ����� �ϳ��� ������Ƽ��� �ٲ���
protected:
	int m_value;
public:
	Base(int value)
		:m_value(value)
	{

	}
	void access(); //5 �Ǵ� �����Լ��� ����� ����� ������ �����Ƽ� ���� ���� ��� ����Ŭ������ �Լ��� �ѹ� ���İ��� ������ �����ս��� �������� �ִ�.
					//���� ������Ƽ��� �ؼ� �ϴ°� ����. ���� �׶��׶����� �ٸ�����, ��
};

class Derived : public Base
{
public:
	Derived(int value)
		:Base(value)
	{//1 ���̽��� �ִ� m_value�� ���� �ٲٴ� �Լ��� Derived�� �����ϴ� ����� �����ϰ� ������ �帱����
	 //2 ���̽��� �ִ°� �ǵ帮�� �ʰ� �ڱⰡ derived�� ���� �ִ°͸� ���� �Ѵٸ� �̰� �׳� �����ϸ� �ȴ� �ƹ� ������ ����.

	}
	void setValue(int value)
	{
		Base::m_value = value; //3 �翬��  �����̺��̴ϱ� �ȵȴ�.
	}
};

int main()
{


	return 0;
}