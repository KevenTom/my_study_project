//이번에는 상속과 포인터를 연관지어서 자식 클래스의 객체에 부모 클래스의 포인터를 사용한다면 어떻게 될까?
//수많은 포인터 질문중에 이 질문이 왜 중요한지는 "다형성"과 관련이 있기 때문입니다. 한번 알아봅시다.
#include <iostream>
#include <string>

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
	//5 2void speak() const
	virtual void speak() const //5 2앞에 virtual 키워드를 붙여보자
	{
		cout << m_name << " ??? " << endl;
	}
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

int main()
{
	Animal animall("my animal");
	Cat catt("my cat");
	Dog dogg("my dog");

	animall.speak();
	catt.speak();
	dogg.speak();

	Animal* ptr_animal1 = &catt; //1 부모클래스의 포인터에 자식 클래스의 주소를 넣어보자
	Animal* ptr_animal2 = &dogg;

	ptr_animal1->speak();
	ptr_animal2->speak(); //2 캣하고 도그인데 물음표가 나오네?? 자식클래스를 부모클래스의 포인터를 캐스팅 시키고 호출하면 자기가 부모클래스인줄 알고 작동한다.
						//좋은건가 안좋은건가?? 확인해보자
	cout << endl;


	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for (int i = 0; i < 5; ++i)
		cats[i].speak();
	for (int i = 0; i < 2; ++i)
		dogs[i].speak();
	
	//3 만약 여러개의 동물 숫자와 종류가 많아진다면 당연히 for문도 그에따라 만들어야하고 고생하겠죠?
	//혹시 이럴때 애니멀클래스로 상속이 된거니까 애니멀클래스로 어떻게 활용하면 편하지 않을까?? 위 포인터 처럼

	Animal* my_animals3[] = { &cats[0], &cats[1], &cats[2], &cats[3],&cats[4],
		&dogs[0],&dogs[1]
	};

	for (int i = 0; i < 7; ++i)
		my_animals3[i]->speak(); //4 오 한번에 출력하기는 하지만 역시 ???로 뜨네
	//6 이번에는 각자 자식 클래스인 것처럼 나온다.
	//앞에 버츄얼 키워드만 넣어줬을 뿐인데 포인터는 부모클래스인데 자식클래스인것처럼 행동한다. 아주 유용하다고 할 수 있다.
	//이러한 성질을 "다형성" 이라고 한다. 끝

	return 0;
}