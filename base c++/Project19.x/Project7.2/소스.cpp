//이번에는 무브시멘틱스와 연관지어서 예제를 만들어 봤습니다.
#include<iostream>

using namespace std;

class customVector { //1 전 강의에서의 스트럭쳐를 이번에는 클래스로 만들어 봤습니다.
public:
	unsigned n_data = 0;
	int* ptr = nullptr;
public:
	customVector(const unsigned& _n_data, const int& _init = 0) {
		cout << "Constructor" << endl;

		init(_n_data, _init); 
		//객체지향을 하시다보면 생성자에게 직접 이니셜라이저 해주는것 보다 초기화해주는 코드를 별도로 분리해주는 경우가 더 많습니다.
	}

	customVector(customVector& l_input) {
		cout << "copy constructor" << endl;

		init(l_input.n_data);
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}

	customVector(customVector&& r_input) {
		cout << "move constructor" << endl;
		
		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	~customVector() {
		delete[] ptr;
	}

	void init(const unsigned& _n_data, const int& _init = 0) {
		n_data = _n_data;
		ptr = new int[n_data];
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};

void doSomething(customVector& vec) {
	cout << "Pass by L-reference" << endl;
	customVector new_vec(vec);
}

void doSomething(customVector&& vec) {
	cout << "Pass by R-reference" << endl;
	customVector new_vec(move(vec));
}


template<typename T>
void doSomethingTemplate(T&& vec) {
	doSomething(forward<T>(vec));
}

int main() {
	customVector my_vec(10, 1024);	//2 평범한 생성자를 사용하고 있고
	customVector temp(my_vec);		//카피 생성자를 사용하고 있습니다.
	cout << my_vec.ptr << endl;
	cout << temp.ptr << endl;
	cout << endl;

	//3 이번에는 my_vec를 R벨류로 넣어보겠습니다.
	customVector temp2(move(my_vec));
	cout << my_vec.ptr << endl;
	cout << temp2.ptr << endl;
	cout << endl;
	//결과를 보면 정상적으로 R벨류로 넣어진것을 알수 있습니다.

	//4 dosomething 함수에서 R벨류, L벨류를 구분합니다.
	doSomething(my_vec);
	doSomething(customVector(10, 1024));
	cout << endl;
	//정상적으로 작동합니다.

	//5 템플릿을 사용해 봅시다.
	doSomethingTemplate(my_vec);
	doSomethingTemplate(customVector(10, 1024));
	cout << endl;
	//설명이 딱히..... 끝


	return 0;
}