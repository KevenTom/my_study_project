//앞강의에서는 유도된 클래스들의 생성자 호출 순서를 살펴 봤고요. 이번에는 생성과 초기화에 쫌더 살표보자
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

class Child : public Mother //2 이떄 차일드클래스는 마더한테 상속을받은게 있으니까 int가 있겠지?? ㅇㅇ 차일드는 8바이트를 가지고 있다.
{
public:
	//3 2float m_d; //3 2 한번 더블로 바꿔보자. 더블은 8바이트니까 8+4=12 겠지?? ㄴㄴ 16바이트가 나옴
	double m_d;
	int m_temp; //4 이상하네 이번에는 멤버변수로 int를 추가해 봤다. 24가 나오네? 이러한 현상을 패딩(padding)이라 한다. 관심있으면 따로 배우라고 한다.
				//여기서 중요한것은 차일드 클래스에서 메모리를 할당 할떄는 마더클래스에 있는것도 다 같이 담을만큼 크게 담는다.
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

	cout << sizeof(Mother) << endl; //1 이번에는 한번 차일드와 마더의 사이즈를 확인해 보자.
	cout << sizeof(Child) << endl;
	cout << endl;

	C c(1024, 3.14, 'a');//5 전강의에서 간단하게 얘기했던것처럼 생성과 소멸의 순서를 확인하는 코드이다. 끝

	return 0;
}