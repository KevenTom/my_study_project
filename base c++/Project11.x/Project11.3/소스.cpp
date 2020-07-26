//앞의 두 강의에서 상속의 전반적인 문법에 대해 훑어 봤습니다. 그러나 우리가 몇가지 살펴봐야할게 있습니다.
//이번에는 유도된 클래스들의 생성 순서가 어떻게 되는지 깊이있게 살펴보겠습니다.
#include <iostream>

using namespace std;

class Mother
{
public:
	int m_i;
public:
	//8 Mother() //8 옜날에는 디폴트매개변수가 없었을때는 다른 생성자를 만들고 디폴트생성자도 있길 원했다면 이렇게 따로 만들어줘야 했지만
	//	:m_i(1)
	//{
	//	cout << "mother construction" << endl;
	//}
	Mother(const int& i_in = 0) //9 디폴트매개변수가 생기면서 디폴트매개변수를 넣어주면 디폴트생성자 역할도 동시에 할수 있다.
		:m_i(i_in)
	{
		cout << "mother construction" << endl;
	}
};

class Child : public Mother //1 차일드클래스로 마더클래스를 상속받았다 -> 이떄 차일드클래스는 마더클래스로부터 유도받았다고 할수도 있다.
{
public:
	double m_d;
public:
	Child()//4 형태는 디폴트 생성자랑 같다. 디폴트생성자는 우리가 의도적으로 생성하지 않더라도 내부적으로 자동으로 호출된다. 하다못해 없으면 만들어서 호출한다.
		//3 2:m_i(1024) //3 2근데 이렇게는 안된다. 내부구조를 자세히 확인해 보자. 지금부터 유도된 클래스가 생성되는 순서를 살펴보자
		//6 2:m_d(1.0)
		//6 2:Mother(), m_d(1.0) //6 2사실 이렇게 마더가 숨어져 있었다!!
		:Mother(1024), m_d(1.0) //7 그럼 저기 마더에다가 직접 값을 넣어줄수 있냐 ? ? 당연히 있다!대신 마더 생성자가 값을 받을수 있어야 겠지 ?
		//10 2:m_d(1.0), Mother(1024) //10 2이렇게 순서를 바꾼다고해도 컴파일러는 무조건 마더생성자 먼저 한다.
	{
		m_i = 10;
		this->m_i = 20; //2 이렇게 사용할 수도 있다.
		Mother::m_i = 1024;

		cout << "child construction" << endl;
	}
};

class A //11 요런식으로 깊이있게 사용할 수 있다.
{
public:
	A()
	{
		cout << "A constructor" << endl;
	}
};
class B : public A
{
public:
	B()
	{
		cout << "B constructor" << endl;
	}
};
class C : public B
{
public:
	C()
	{
		cout << "C constructor" << endl;
	}
};

int main()
{
	Child c1; //5 실행해보면 마더생성자가 먼저 만들어지고 차일드생성자가 그 다음으로 출력된다. 디버그로 찍어보셈
			//찍어보면 우리가 의도적으로 마더클래스의 생성자를 호출하지 않아도 컴퓨터가 자동으로 디폴트생성자 호출을 한다.
			//마더에 있는걸 초기화를 하고 그 다음에 차일드를 초기화 한다. 마더클래스라 일종의 상위클래스인 샘이다.
			//그렇기때문에 차일드생성자리스트로 초기화할수 없고 마더클래스생성자리스트에서 초기화한 후에야 수정할 수 있다. 
	        //그래서 이니셜라이져리스트에서는 초기화할수는 없지만 마더초기화리스트에서 끝난 다음에 돌아온 후에 수정할 수 있다. (m_i = 10;)

	C c;
	cout << endl;
	B b;
	cout << endl;
	A a;//12 그러면 소멸자는?? 당연히 순서 반대로 작동한다. 끝

	return 0;
}