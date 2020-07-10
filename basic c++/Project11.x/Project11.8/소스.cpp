//상속이라는것은 기본적으로 받아오는 것이다 그래서 내가 가지고 있지는 않지만 부모로부터 가져 와서 사용하는것 위주로 설명해 드렸습니다.
//이번에는 반대로 상속 받는걸 사용하지 못하도록 막는방법을 알아봅시다.
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
	using Base::m_i; //2 퍼블릭 아래에 using을 사용하면 이 m_i가 Derived 안에서는 퍼블릭이 된다.

	void print() = delete; //8 또는 delete를 사용해서 자식클래스에서는 사용하지못하게 막을수 있음. 끝
private:
	using Base::print;//괄호 치지 마셈 //5 프라이빗 아래에서 하면됨
};

int main()
{
	Derived derived(7);
	//1 2derived.m_i = 1024; //1 2당연히 프로택티드니까 안된다. 그러나 이걸 바꿀 수 있다.
	derived.m_i = 1024; //3 이번에는 사용됨
	derived.print(); //4 derived는 상속받은 Base의 print를 당연히 사용할 수 있다. 이번에는 이걸 밖에서 접근하지 못하도록 막아보자.
					//6 작동 안되지?
	Base base(5);
	base.print(); //7 부모에서는 print가 가능하다.
					//여기에다 적는거지만 사람에따라 다르지만 using을 위에 몰아넣거나 아무튼 사용할꺼면 정리하는걸 추천함

	return 0;
}