//� Ŭ������ �̹� ���ø��� �Ǿ� �־ ����Լ��� �߰����� ���ø��� ���ټ� �ִ� ����� �ֽ��ϴ�. �˾ƺ�����
#include<iostream>

using namespace std;

template<class T>
class A {
	T m_value;
public:
	A(const T& input)
		:m_value(input)
	{}

	template<class TT> //1 TT�� �Ǿ� ����? �̷��� �ϸ� dosomething���� �۵��ϴ� ���ø��Ķ���Ͱ� �˴ϴ�.
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

	a_int.dosomething<float>(123.4); //2 TT�� � Ÿ������ ��Ȯ�� ����� �ϰ��� �����ϸ� float�� ���´ٴ°��� �� �� �ִ�.
	//3 float�� ���ؼ� �ν��Ͻÿ��̼� �آZ�µ� 123.4�� double�� �־��ִϱ� ������ ���ٴ°��� �� �� �ִ�.

	a_int.dosomething('a'); //3 �Ű������� �޴´ٸ� float�� ������ �ʿ� ����. ��


	return 0;
}