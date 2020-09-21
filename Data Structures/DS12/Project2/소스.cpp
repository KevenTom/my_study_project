#include<iostream>

using namespace std;

class A {
protected:
	int num;
};

class B : public A {
private:
	A classA;
public:
	void test(int a) {
		this->num = a;
	}
};

int main() {
	B classb;
	
	classb.test(123);


	return 0;
}