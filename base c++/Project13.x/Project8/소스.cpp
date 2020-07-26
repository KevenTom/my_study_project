//어떤 클래스가 이미 템플릿이 되어 있어도 멤버함수에 추가적인 템플릿을 해줄수 있는 방법이 있습니다. 알아보시죠
#include<iostream>

using namespace std;

template<class T>
class A {
	T m_value;
public:
	A(const T& input)
		:m_value(input)
	{}

	template<class TT> //1 TT로 되어 있죠? 이렇게 하면 dosomething에만 작동하는 템플릿파라미터가 됩니다.
	void dosomething(const TT& input) {
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

	void print() {
		cout << m_value << endl;
	}
};

int main() {
	A<int> a_int(123);
	a_int.print();

	a_int.dosomething<float>(123.4); //2 TT가 어떤 타입인지 명확히 해줘야 하겠죠 실행하면 float가 나온다는것을 알 수 있다.
	//3 float에 대해서 인스턴시에이션 해줫는데 123.4인 double로 넣어주니까 오류가 난다는것을 알 수 있다.

	a_int.dosomething('a'); //3 매개변수를 받는다면 float를 적어줄 필요 없다. 끝


	return 0;
}