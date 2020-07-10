//클래스에서 멤버변수를 외부,자식에서 접근할수 있냐 없냐를 지정해줄수 있었죠, 비슷하게 상속을 받을때 내가 가져온것들을 어떻게 접근할수 있는지 접근 범위에 대해서
//접근지정자를 사용할 수 있습니다. 상속과 접근지정자가 어떻게 작동하는지 알아봅시다.
#include <iostream>
//1 이번 강의는 접근이 어떻게 작동하는지 코드를 실험한다고 생각하면 됩니다.
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

//3 Derived 클래스를 만들어 봤다.
//8 2class Derived : public Base //5 우리가 지금까지 public 으로만 사용했지만 이걸 어떻게 사용하냐에 따라 더 접근이 제한을 조절할 수 있다.
								//마더클래스의 접근지정자와 여기의 접근 지정자와 비교해서 더 접근이 제한된 방향으로 간다.
//11 3class Derived : protected Base //8 2이번에는 protected로 바꿔 봤다.
class Derived : private Base //11 3이번에는 private로 바꿔 봤다.
{
public:
	Derived()
	{
		Base::m_public; //10 프로텍티드니까 접근 되네 //12 프로택티드니까 이게 되는게 맞나? //14 한마디로 프라이빗으로 막는다는 것은 Derived안에서는 m_public, m_protected가 모두 프라이빗처럼 "작동"한다는 뜻이다.(Derived 안에서는 작동함)
		Base::m_protected;// 당연히 프로택티드니까 접근 ㅇ
		//11 3Base::m_private;// 프라이빗이 더 엄격하니까 안되네!!
	}//Base:: 굳이 하는 이유는 버릇들기 위해서! 아주 유용함!
};

class GrandChild : public Derived
{
	GrandChild()
	{
		Derived::m_public; //13 Derived가 Base를 가져올때 프라이빗으로 가져왔으니까 프라이빗으로 변해서 그랜드차일드에서는 접근할 수 없다.
		Derived::m_protected; //당연히 안됨
	}//15 그래서 여기에서 작동이 안된다. 끝
};


int main()
{
	Base base;
	base.m_public = 123;
	//2 2base.m_protected = 123; //2 2당연히 안되지??
	//base.m_private = 123;

	Derived derived; //4 자 여러가지 조합으로 테스트를 해보자.
	//9 2derived.m_public = 1024; //6 당연히 되고 //9 2띠용 프로택티드로 바꾸니까 안되네?? 퍼블릭과 프로택티드중에 프로택티드가 더 제한되어 있으니까 그걸로 바뀐거다.
	//7 2derived.m_protected = 1024;//7 2안되고
	//derived.m_private = 1024;     //안된다.

	return 0;
}