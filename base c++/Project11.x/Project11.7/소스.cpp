//상속을 사용하는 일반적인 구현의 경우 부모, 자식 클래스간의 기능차이가 그렇게 많지않고 겹치는 경우가 있을때 있다 
//이럴때 배웠던것처럼 상속받은 함수 오버로딩하는 방법에 대해 알아보자.
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
	friend ostream& operator<<(ostream& out, const Base& b)//2 이번에는 입출력 오퍼레이터다
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
		Base::print(); //1 이처럼 어떤 경우에는 자식클래스에서 어떤 기능을 수행하는데 부모클래스에 있는걸 수행하고 추가로 자기의 기능을 수행하려는 경우가 있다. 
		cout << "i'm derived" << endl;
	}
	friend ostream& operator<<(ostream& out, const Derived& b)
	{
		//3 2Base::operator<<????//3 2어떻게 하지??
		cout << static_cast<Base>(b); //4 이렇게 하면 된다. 그런데 매개변수는 Derived& b 인데 다른 사용자 정의인 Base를 스태틱캐스트로 작동할수 있을까?
										//우리가 전에 메모리 사이즈를 확인해 봤을때 앞부분은 부모클래스의 정보들이고 뒤에 추가로 자식클래스의 정보가 추가되는 형태였다.
										//그러니까 자식클래스는 부모클래스의 메모리를 가지고 있다. 그래서 캐스트가 가능하다. 끝
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