//Ŭ�������� ��������� �ܺ�,�ڽĿ��� �����Ҽ� �ֳ� ���ĸ� �������ټ� �־���, ����ϰ� ����� ������ ���� �����°͵��� ��� �����Ҽ� �ִ��� ���� ������ ���ؼ�
//���������ڸ� ����� �� �ֽ��ϴ�. ��Ӱ� ���������ڰ� ��� �۵��ϴ��� �˾ƺ��ô�.
#include <iostream>
//1 �̹� ���Ǵ� ������ ��� �۵��ϴ��� �ڵ带 �����Ѵٰ� �����ϸ� �˴ϴ�.
using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

//3 Derived Ŭ������ ����� �ô�.
//8 2class Derived : public Base //5 �츮�� ���ݱ��� public ���θ� ��������� �̰� ��� ����ϳĿ� ���� �� ������ ������ ������ �� �ִ�.
								//����Ŭ������ ���������ڿ� ������ ���� �����ڿ� ���ؼ� �� ������ ���ѵ� �������� ����.
//11 3class Derived : protected Base //8 2�̹����� protected�� �ٲ� �ô�.
class Derived : private Base //11 3�̹����� private�� �ٲ� �ô�.
{
public:
	Derived()
	{
		Base::m_public; //10 ������Ƽ��ϱ� ���� �ǳ� //12 ������Ƽ��ϱ� �̰� �Ǵ°� �³�? //14 �Ѹ���� �����̺����� ���´ٴ� ���� Derived�ȿ����� m_public, m_protected�� ��� �����̺�ó�� "�۵�"�Ѵٴ� ���̴�.(Derived �ȿ����� �۵���)
		Base::m_protected;// �翬�� ������Ƽ��ϱ� ���� ��
		//11 3Base::m_private;// �����̺��� �� �����ϴϱ� �ȵǳ�!!
	}//Base:: ���� �ϴ� ������ ������� ���ؼ�! ���� ������!
};

class GrandChild : public Derived
{
	GrandChild()
	{
		Derived::m_public; //13 Derived�� Base�� �����ö� �����̺����� ���������ϱ� �����̺����� ���ؼ� �׷������ϵ忡���� ������ �� ����.
		Derived::m_protected; //�翬�� �ȵ�
	}//15 �׷��� ���⿡�� �۵��� �ȵȴ�. ��
};


int main()
{
	Base base;
	base.m_public = 123;
	//2 2base.m_protected = 123; //2 2�翬�� �ȵ���??
	//base.m_private = 123;

	Derived derived; //4 �� �������� �������� �׽�Ʈ�� �غ���.
	//9 2derived.m_public = 1024; //6 �翬�� �ǰ� //9 2��� ������Ƽ��� �ٲٴϱ� �ȵǳ�?? �ۺ��� ������Ƽ���߿� ������Ƽ�尡 �� ���ѵǾ� �����ϱ� �װɷ� �ٲ�Ŵ�.
	//7 2derived.m_protected = 1024;//7 2�ȵǰ�
	//derived.m_private = 1024;     //�ȵȴ�.

	return 0;
}