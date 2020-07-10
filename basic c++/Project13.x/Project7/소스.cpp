//���ø� �Ķ���Ͱ� �������� ��쿡���ؼ� ��� �Ǵ��� �˾ƺ��ô�.
#include<iostream>

using namespace std;

template<class T>
class A {
	T m_value;
public:
	A(const T & input)
		:m_value(input)
	{}

	void print() {
		cout << m_value << endl;
	}
};

template<class T>//2 ��������? ��
class A<T*> {
	T* m_value;
public:
	A(T* input)
		:m_value(input)
	{}

	void print() {
		cout << *m_value << endl;
	}
};


int main() {
	A<int> a_int(123);
	a_int.print();

	int b = 456;
	A<int*> a_int_ptr(&b);
	a_int_ptr.print(); //1 �翬�� �����͸� ������ ������ �ּҰ� ������? �ٵ� � ��쿡�� �������� ��쿡�� Ư���ϰ� �۵��ϱ� ���Ҽ��� �־��




	return 0;
}