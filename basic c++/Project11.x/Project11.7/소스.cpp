//����� ����ϴ� �Ϲ����� ������ ��� �θ�, �ڽ� Ŭ�������� ������̰� �׷��� �����ʰ� ��ġ�� ��찡 ������ �ִ� 
//�̷��� �������ó�� ��ӹ��� �Լ� �����ε��ϴ� ����� ���� �˾ƺ���.
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
	friend ostream& operator<<(ostream& out, const Base& b)//2 �̹����� ����� ���۷����ʹ�
	{
		out << "this is base output" << endl;
		return out;
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
	void print()
	{
		Base::print(); //1 ��ó�� � ��쿡�� �ڽ�Ŭ�������� � ����� �����ϴµ� �θ�Ŭ������ �ִ°� �����ϰ� �߰��� �ڱ��� ����� �����Ϸ��� ��찡 �ִ�. 
		cout << "i'm derived" << endl;
	}
	friend ostream& operator<<(ostream& out, const Derived& b)
	{
		//3 2Base::operator<<????//3 2��� ����??
		cout << static_cast<Base>(b); //4 �̷��� �ϸ� �ȴ�. �׷��� �Ű������� Derived& b �ε� �ٸ� ����� ������ Base�� ����ƽĳ��Ʈ�� �۵��Ҽ� ������?
										//�츮�� ���� �޸� ����� Ȯ���� ������ �պκ��� �θ�Ŭ������ �������̰� �ڿ� �߰��� �ڽ�Ŭ������ ������ �߰��Ǵ� ���¿���.
										//�׷��ϱ� �ڽ�Ŭ������ �θ�Ŭ������ �޸𸮸� ������ �ִ�. �׷��� ĳ��Ʈ�� �����ϴ�. ��
		out << "this is Derived output" << endl;
		return out;
	}
};

int main()
{
	Base base(5);
	base.print();
	Derived derived(7);
	derived.print();

	cout << base << endl;
	cout << derived << endl;

	return 0;
}