//�����е��� ������ c++������ ����Ͻôٺ��� std::forward �Լ��� �������⼭ ���ð� �˴ϴ�.
//std::forward�� �Ϻ��� ������ �����Ҷ� ����� �Ǵµ��� �� �ǹ̸� �𸣴� ���¿��� ���Ͻð� �Ǹ��� ��Ȳ�ϽǼ� �ֽ��ϴ�.
//���⼭�� �Ϻ��� ������ �ǹ̿� L���� ���۷���, R���� ���۷���, ����ø�ƽ���� ������� ��� ������ �ϰ� ����ϴ��� �˷��帮�ڽ��ϴ�.

//ù��° ���������� �� ������ �˷��帮��, �ι�° ���������� �������� �����Ǿ��ִ°͵��� �� �Ⱦ�鼭 �����ص帮�ڽ��ϴ�.
#include<iostream>


using namespace std;

struct MyStruct
{};


void func(MyStruct& s) {
	cout << "Pass by L-ref" << endl;
}
void func(MyStruct&& s) {
	cout << "Pass by R-ref" << endl;
}


template<typename T>
void func_wrapper(T t) {
	func(t);
}


template<typename T>
void func_wrapper2(T&& t) { //3 ������ �Ķ���͸� R���� ���۷����� �޾ƿ��°�ó�� ���ְ�
	func(forward<T>(t));	//�׸��� forward�� �̿��ؼ� ������ ���ָ� �˴ϴ�.
}							//forward�� �ϴ� ���� t�� ���ö� ���� L���� ���۷����� ���´ٸ� L���� ���۷����� �ְ� R���� ���۷����� ���´ٸ� R������ �������ݴϴ�.


int main() {
	MyStruct s;

	func(s);
	func(MyStruct());
	//Pass by L - ref
	//Pass by R - ref
	//1 ���������� L���� R������ ���°��� �˼� �ֽ��ϴ�.
	//�̷��� ���������� ����ϴ°��� �����Ϸ��� L�������� R�������� ������ ���ݴϴ�.
	//������ ����� ���� ���ø��� ����Ҷ��� ������ �����ݴϴ�.

	func_wrapper(s);
	func_wrapper(MyStruct());
	//Pass by L - ref
	//Pass by L - ref
	//���ø��� ����ϸ� ������ �����ֱ� ������ �Ѵ� L�������۷��� ó�� ������ �Ǿ�����ϴ�.

	//2 �̷��� �츮�� forward�� ����ϽǼ� �ֽ��ϴ�.
	func_wrapper2(s);
	func_wrapper2(MyStruct());
	//Pass by L - ref
	//Pass by R - ref
	//4 ��ó�� ������ �°� �Ķ���ͷ� ���۵Ǵ°��� Ȯ���� �� �ֽ��ϴ�.


	return 0;
}