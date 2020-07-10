//지금까지는 다형성에서 버츄얼 펑션을 구현할때 자식클래스에서 자기에게 적합한 함수를 오버라이딩 하는 관점에서 설명해 드렸죠
//이번에는 설계를 하는 관점에서 베이스클래스를 만들때 자식클래스에게 이러이러한 것을 반드시 해야한다는 제약을 걸어두는 방법을 설명해 드리겠습니다
//이번에는 "순수 가상 함수"(바디가 없기 때문에 자식클래스에서 반드시 오버라이딩을 해줘야만 한다),
//순수 가상 함수가 포함이 된 클래스를 "추상 기본 클래스",
//순수 가상 함수로만 이루어진 클래스를 "인터페이스 클래스", 이렇게 3가지를 설명해 드리겠습니다.
#include<iostream>
#include<string>
using namespace std;

class Animal
{
protected:
	string m_name;
public:
	Animal(string name)
		:m_name(name)
	{}
	string getname() { return m_name; }
	//1 2virtual void speak() const
	//{
	//	cout << m_name << " ??? " << endl;
	//}
	virtual void speak() const = 0; //1 2첫 강의에 사용한 클래스 입니다. 애니멀클래스에서 스피크할떄 ??? 뜨는게 이상하니까 펑션의 바디를 없앨 수 있다.
	//이렇게 바디가 없고 버츄얼 펑션이고 뒤에 =0 이렇게 되어있는 함수를 pure virtual function(순수 가상 함수) 라고 부른다.

	//3 즉, 부모클래스에서 구현할때 "나는 모르겠다", 나는 모르겠지만 자식클래스에서는 반드시 speak을 구현해라 라는 의미를 가진다.
	//지금까지는 버츄얼을 사용할때 일반적인 것들은 부모 클래스에 모아놓고 재활용 할수 있다면 하고, 또는 자식클래스에 특화된 뭔가 있을 경우에는 오버라이딩을 하는 관점에서 말씀해 드렸죠
	//여기서는 관점이 조금더 달라진거다. 애니멀클래스를 설계할때 자식클래스는 무조건 퓨어버츄얼펑션을 만들어야 한다. 라는 관점으로 바뀐거다.
};

class Cat : public Animal
{
public:
	Cat(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		:Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

class Cow : public Animal //4 한번 퓨어버츄얼펑션인 speak가 없는 자식 클래스 Cow 를 만들어 봤다.
{
public:
	Cow(string name)
		:Animal(name)
	{}
};


//-----------------인터페이스 클래스를 설명하기 위한 클래스-----------------------
class IErrorLog //7 인터페이스클래스면 이름 앞에 대문자 I를 붙여주는게 관습이다.
	//내부에 들어있는 함수들이 모두 순수 가상 함수로만 이루어진 클래스를 인터페이스 클래스라고 부른다.
	//자기가 뭘 할지는 아무것도 정의를 하지 않았기 때문에 얘는 뭐뭐를 해야한다만 가지고 있는 구조가 된다.
	//인터페이스클래스는 한마디로 외부에서 사용할때 이러이러한 기능들이 있을거다 라고 예측을 할수 있는 중계기 역할을 해준다.
	//그러니까 인터페이스 클래스를 상속 받은 클래스는 퓨어버츄얼펑션을 할줄 안다만 알고 있다.
{
public:
	virtual bool reportError(const char* errorMessage) = 0;
	virtual ~IErrorLog(){}
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log) //8 매개변수로 인터페이스 클래스를 받네? 근데 인터페이스 클래스는 인스턴스를 만들수 없고 클래스 내용도 하나도 없는데
								//그러니까 인터페이스 클래스를 상속 받은 클래스는 퓨어버츄얼펑션을 할줄 안다만 알고 있다. 
{
	log.reportError("Runtime error!!"); //9 실제로도 퓨어버츄얼펑션만 가지고 있다.
}

int main()
{
	Animal ani("H1"); //2 순수가상함수가 있는 상태에서 애니멀클래스를 호출해 보았다.
					//만들어지지가 않는다. 퓨어버츄얼펑션이 하나라도 들어가있는 클래스인 abstract class(추상 기본 클래스)는 객체를 만들수 없다.
	Cow cow("hello"); //5 안만들어 진다. 오류를 보면 퓨어버츄얼펑션인 speak함수가 없다고 한다.
					//한마디로 퓨어버츄얼펑션은 클래스를 설계할때 상속구조자체를 한꺼번에 설계할수 있도록 도와주는 용법이라고 생각하면 된다.





	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log); //10 매개변수는 IErrorLog을 받지만 인수는 FileErrorLog을 줄수 있다. 상속을 받는 구조로 되어있으니까
							//실행해보면 넣어준 대로 출력해준다는것을 알 수 있다. 아주 유용한 기능이니 기억하자. 끝
	doSomething(console_log);


	return 0;
}