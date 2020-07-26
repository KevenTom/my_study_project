//이번에는 유도된 클래스에 (자식클래스에)새로운 기능을 추가할떄 생각해둬야할점 몇가지를 소개해 드리겠습니다.
#include <iostream>

using namespace std;

class Base
{
//4 2private: //4 2해결방법중 하나는 프로택티드로 바꾸자
protected:
	int m_value;
public:
	Base(int value)
		:m_value(value)
	{

	}
	void access(); //5 또는 접근함수를 만드는 방법도 있지만 귀찮아서 구현 안함 대신 상위클래스의 함수를 한번 거쳐가기 때문에 퍼포먼스가 떨어질수 있다.
					//차라리 프로택티드로 해서 하는게 좋다. 물론 그때그때따라 다르지만, 끝
};

class Derived : public Base
{
public:
	Derived(int value)
		:Base(value)
	{//1 베이스에 있는 m_value의 값을 바꾸는 함수를 Derived에 구현하는 방법을 간단하게 설명해 드릴께요
	 //2 베이스에 있는걸 건드리지 않고 자기가 derived에 갖고 있는것만 구현 한다면 이건 그냥 구현하면 된다 아무 걱정이 없다.

	}
	void setValue(int value)
	{
		Base::m_value = value; //3 당연히  프라이빗이니까 안된다.
	}
};

int main()
{


	return 0;
}