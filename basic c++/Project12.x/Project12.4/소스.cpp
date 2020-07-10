//상속구조에서 생성자는 보통 자식클래스의 자신을 사용했죠 하지만 소멸자는 가상소멸자를 사용하는것이 좋습니다. 가상소멸자에 대해 알아봅시다.
#include <iostream>

using namespace std;

class Base
{
public:
	virtual ~Base() //3 해결법은 간단하다. 소멸자 앞에 버츄얼을 넣어주면 된다.
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;
public:
	Derived(int length)
	{
		m_array = new int[length];
	}
	~Derived() //5 여기에 오버라이드를 붙여줄수는 있지만 부모클래스의 소멸자가 버츄얼 이어야 한다. 끝
	{
		cout << "~Derived()" << endl;
		delete[] m_array;
	}
};

int main()
{
	//2 2Derived derived(5); //1 전 강의에서 말했지만 소멸자 호출순서를 보면 가장최근자식클래스 먼저 소멸한다.

	Derived* derived2 = new Derived(5);
	Base* base = derived2;
	delete base; //2 2derived2에 동적할당을 해주고 derived2의 포인터를 base포인터에 집어넣고 그다음에 base포인터를 지워주는 방식이다.
				//대부분의 경우 베이스클래스로부터 지우는것을 시도하는경우가 많다.
				//작동해보면 당연히 베이스만 delete 된다.
				//전 강의처럼 애니멀은 하나이고 캣,도그,타이거 등등 여러개 많기 때문에 다형성의 특성을 잘 활용하려면 이렇게 지울때도 다형성을 활용할때가 일반적이다.
	//4 소멸자에 버츄얼을 넣어주니까 최근 자식먼저 딜리트 해주고 다음에 부모클래스를 해주는 아주 좋은 방식으로 진행해준다.

	return 0;
}