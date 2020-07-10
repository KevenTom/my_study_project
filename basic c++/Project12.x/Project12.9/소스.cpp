//상속의구조를 생각해봤을때 부모클래스보다는 자식클래스가 더 많은 정보를 가지고 있을 경우가 많겠죠 자식클래수에는 부모클래스의 일반적인 경우보다는
//더 구체하게 구현되기 때문에 추가적인 변수나 함수를 갖을수 있을 수 있습니다.또 함수 오버로딩이 되어있을수 있죠
//근데 만약에 보다 작은 부모의 객체에다가 보다 큰 자식 객체를 강제로 대입하면 어떻게 될까요?
//그러면 부모의 객체가 담을 수 있는 정보가 적기 때문에 자식클래스에만 있는 정보들은 모두 잘려서 사라지겠죠
//이러한 것을 객체잘림(object slicing) 이라 부릅니다.
//다형성을 구현할때 초보프로그래머들이 실수로 객체잘림현상을 만들어 내는 경우가 있습니다.
//이런것을 방지할수 있는 reference_wrapper 에 대해서도 알아봅시다.
#include<iostream>
#include<vector>
#include<functional>

using namespace std;

class Base {
public:
	int m_i = 0;

	virtual void print() {
		cout << "i'm Base" << endl;
	}
};

class Derived : public Base {
public:
	int m_j = 1;

	virtual void print() override {
		cout << "i'm derived" << endl;
	}
};

void dosomething(Base& b) {
	b.print();
}

int main() {
	Derived d;
	vector<std::reference_wrapper<Base>> my_vec;

	my_vec.push_back(d);
	my_vec[0].get().print();

	return 0;
}