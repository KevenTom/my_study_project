//템플릿 파라미터가 포인터인 경우에대해서 어떻게 되는지 알아봅시다.
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

template<class T>//2 간단하죠? 끝
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
	a_int_ptr.print(); //1 당연히 포인터를 넣으면 포인터 주소가 나오죠? 근데 어떤 경우에는 포인터인 경우에만 특별하게 작동하길 원할수도 있어요




	return 0;
}