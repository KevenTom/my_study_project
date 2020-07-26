//드디어 객체지향에서 가장 중요한 상속에 대해 공부를 시작하게 되었습니다. 여기서는 상속에 대해 가장 기본적인 문법적인 측면에서 설명해 들이고
//이게 어디에서 사용하는지는 뒤에 반복하면서 설명해 드리겠습니다.
#include<iostream>

using namespace std;

class Mother //1 상속이라는거 자체가 부모가 자식에게 뭔가를 넘겨준다는 뜻이죠
{
//9 private: //9 이럴때 protected를 사용할 수 있습니다. 프로택티드는 프라이빗이면서 예외로 자식은 엑세스 할수 있게 할수 있다.
protected:
	int m_i;
public:
	Mother() //20 여러가지 방법이 있지만 그중 하나가 그냥 디폴트생성자를 만들어 주는거다.
		:m_i(0)
	{}
	Mother(const int& i_in)
		:m_i(i_in)
	{
		cout << "Mother constructor" << endl;
	}
	void setValue(const int& i_in)
	{
		m_i = i_in;
	}
	int getValue()
	{
		return m_i;
	}
};

//2 마더 클래스를 상속 받는 차일드 클래스를 만들어 보자
class Child : public Mother //5 차일드 클래스가 자신만의 변수나 함수를 가질수도 있습니다.
{
private:
	double m_d;
public:
	Child(const int& i_in, const double& d_in) //14 우리가 상속을 사용하는 이유는 보통 부모클래스의 정보와 자식클래스의 정보 이 두가지를 같이 사용하려고 할때 사용할때가 많다. 그래서 생성자도 보통 같이 만든다.
	//16	:m_i(i_in), m_d(d_in)//15 우리가 보통 클래스 생성자를 해줄때 초기화리스트를 사용하지만 이게 또 안된다.
							//칸스트럭쳐가 존재하는 이유는 메모리가 할당될때 그때 이니셜라이져를 이렇게 해주세요~ 하는거지 메모리가 먼저 할당되고 거기에다 복사해서 넣어주세요~ 할수는 없다.
							//즉 차일드 클래스르 만들때 m_i의 메모리가 없다는 거죠 이거는 생성자 순서를 이해하면 되는데 이건 뒤에 배운다.
							///거기다 m_i 의 권한은 일단 1차적으로 주인인 Mother에게 있다.
	//21 조금더 우아한 방법이 있는데 뭐냐면 차일드생성자가 들어온 i_in 값을 마더클래스에 넣어주면서 생성자를 호출하는 겁니다.
		:Mother(i_in), m_d(d_in) //15 이렇게 Mother의 생성자를 호출해서 하는 간접적인 방법이 있다.
	{
		//16 답은 간단하다. 이니셜라이저리스트를 안쓰고 이렇게 사용한다.
		//22 Mother::setValue(i_in); //22 필요없어서 지움 끝
		//m_d = d_in;
	}
	void setValue(const int& i_in, const double& d_in) //7 다양한 방법이 있지만 이번에는 받는 값을 두개로 해 보았다.
	{
		//8 m_i = i_in; //8 어 근데 i_in은 마더클래스의 프라이빗인 m_i에 넣어줘야 하는데 안되네
						//오류를 읽어보면 엑세스 할수 없다고 한다 -> 아 private은 자식한테도 엑세스 할수 없구나
		m_i = i_in;		//10그러면 프라이빗일때는 정말 사용할 수 없는건가? ㄴㄴ setValue 사용하면 되잖어
		Mother::setValue(i_in); //11 setValue 함수가 오버로딩 많이되어 있잖어? 이럴때 확실히 지정하고 싶으면 앞에 Mother:: 붙이면 됨
		m_d = d_in;
	}
	void setValue(const double& d_in)
	{
		m_d = d_in;
	}
	double getValue()
	{
		return m_d;
	}
};

class Son : public Mother //4 여러 클래스가 동시에 상속을 받을수 있다.
{
	
};

int main()
{
	//19 Mother mother;
	//mother.setValue(1024);
	//cout << mother.getValue() << endl;
	
	//17 Child child;
	//child.setValue(128);
	//cout << child.getValue() << endl; //3 차일드 클래스에는 아무것도 안적혀 있지만 실행해보면 마더클래스처럼 작동하는것을 알 수 있다.
	//									//그러니까 차일드 클래스는 상속받은 마더클래스로부터 받은걸 기본적으로 모두 사용할 수 있습니다.
	//									//6 실행하려고 보니까 어 setValue, getValue가 마더한테 상속 받은게 원래 있었네
	//									//이러면 어떻게 될까? 이러면 자기클래스에 있는걸 우선으로 부른다.
	//child.Mother::setValue(2048); //12 Mother::을 이렇게 사용할 수도 있다


	Child child(1024, 128);
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;

	//18 마더클래스에도 생성자를 사용할수 없냐? 한번 해보자.
	Mother mother(1028);
	cout << mother.getValue() << endl; //19 엉? 오류가 뜨네? 이게 뭐냐면 차일드클래스가 생성될때는 내부적으로 마더클래스 생성자를 같이 호출한다.
										//마더클래스에 생성자를 만들어주기 전까지는 Child 생성자가 알아서 마더의 디폴트 생성자를 호출해주고 있었는데
										//생성자가 생기니까 디폴트 생성자가 없어지고 안되네?



	return 0;
} 