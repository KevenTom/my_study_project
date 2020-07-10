//이번에는 다형성을 구현할때 유용하게 사용하는 override, final, 공변 반환형(covariant)을 알아봅시다.
#include <iostream>

using namespace std;

class A
{
public:
	//5 3virtual void print(int x) { cout << "A" << endl; }
	void print() { cout << "A" << endl; }
	virtual A* getThis() { return this; } //5 3covariant이란 일반적으로 리턴타입이 다르면 안되는 오버라이딩을 안되지만 마더클래스. 자식클래스 이기 때문에 오버라이딩이 됩니다.
};

class B : public A
{
public:
	//3 3void print(short x) { cout << "B" << endl; } //1 같은프린트지만 매개변수가 다르다.
	//3 3void print(short x) override { cout << "B" << endl; } //3 3이럴때 오버라이드를 적어준다. 자식클래스에서 함수를 구현할때 상위클래스에 있는 버츄얼펑션을 무조건 오버라이딩 하고 싶다면 
	//override을 적어준다. 그러면 이 함수는 무조건 오버라이드 해야한다고 컴파일라거 이해를 한다. 그래서 지금 컴파일러가 오류가 발생한다. (컴파일러로 먼저 오류를 잡아준다고 생각하면 편하다.)
	//4 2void print() final { cout << "B" << endl; //4 2final 키워드는 간단하다. 적어주면 그 아래함수들을 오버라이딩을 할수 없게 막아준다.
	void print() { cout << "B" << endl; }
	virtual B* getThis() { return this; }
};

class C : public B
{
public:
	virtual void print() { cout << "C" << endl; }
};

int main()
{
	A a;
	B b;

	//5 3A& ref = b;
	//ref.print(1); //2 매개변수가 다르니까 당연히 B가 안나온다. 알다시피 함수가 파라미터가 다르면 오버라이딩을 할수 없다. 
				//컴파일러 자체는 그냥 다른 함수인가보다 할수 있지만 만약 이 함수는 무조건 오버라이드 해야한다고 하면 어떻게 해야할까?
	A& ref = b;
	b.getThis()->print();
	ref.getThis()->print();
	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl; //6 마지막 설명은 이해하기 어려우니까 동영상 7분 끝


	return 0;
}