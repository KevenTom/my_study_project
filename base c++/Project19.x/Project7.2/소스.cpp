//�̹����� ����ø�ƽ���� ������� ������ ����� �ý��ϴ�.
#include<iostream>

using namespace std;

class customVector { //1 �� ���ǿ����� ��Ʈ���ĸ� �̹����� Ŭ������ ����� �ý��ϴ�.
public:
	unsigned n_data = 0;
	int* ptr = nullptr;
public:
	customVector(const unsigned& _n_data, const int& _init = 0) {
		cout << "Constructor" << endl;

		init(_n_data, _init); 
		//��ü������ �Ͻôٺ��� �����ڿ��� ���� �̴ϼȶ����� ���ִ°� ���� �ʱ�ȭ���ִ� �ڵ带 ������ �и����ִ� ��찡 �� �����ϴ�.
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
	customVector my_vec(10, 1024);	//2 ����� �����ڸ� ����ϰ� �ְ�
	customVector temp(my_vec);		//ī�� �����ڸ� ����ϰ� �ֽ��ϴ�.
	cout << my_vec.ptr << endl;
	cout << temp.ptr << endl;
	cout << endl;

	//3 �̹����� my_vec�� R������ �־�ڽ��ϴ�.
	customVector temp2(move(my_vec));
	cout << my_vec.ptr << endl;
	cout << temp2.ptr << endl;
	cout << endl;
	//����� ���� ���������� R������ �־������� �˼� �ֽ��ϴ�.

	//4 dosomething �Լ����� R����, L������ �����մϴ�.
	doSomething(my_vec);
	doSomething(customVector(10, 1024));
	cout << endl;
	//���������� �۵��մϴ�.

	//5 ���ø��� ����� ���ô�.
	doSomethingTemplate(my_vec);
	doSomethingTemplate(customVector(10, 1024));
	cout << endl;
	//������ ����..... ��


	return 0;
}