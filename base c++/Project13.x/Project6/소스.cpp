//���� �� ���Ǵ� ���ø��� Ư��ȭ �ϴ� ����� ���� ������ �����
//�̹����� ���ø��� Ư��ȭ �ϱ� �ϴµ� �κ������θ� Ư��ȭ�ϴ� ����� ���� �˾ƺ��ô�.
#include<iostream>

using namespace std;

template<class T, int size> //1 �� Ŭ�������� ���� Ŭ����t�� ���ؼ� ���ø�Ÿ���� �Ǿ� �ְ� int size�� ���ؼ� �Ķ���Ͷ����� �Ǿ� �ֽ��ϴ�
class StaticArray {
	T m_array[size];
public:
	T* getArray() {
		return m_array;
	}

	T& operator[](int index) {
		return m_array[index];
	}

	void print() {//6 2 ����Լ��� print �߰���
		for (int c = 0; c < size; ++c)
			cout << m_array[c] << ' ';
		cout << endl;//7 �ٵ� �������� ����ȶ����� ���ֱⰡ ���ŷӴ�.
		//�� ���ѹ���� �ִµ� Ŭ������ ��� �޴� ����� �ִ�.
	}
};

template<class T, int size>
class StaticArrayy : public StaticArray<T, size> { //8 ������� ���ִ� ������ ���ĸ� ���ø��� ��°�� �ϴ� �����ؼ� ����ȶ����� �ϴ°ͺ��� �̰� �ξ� ������ �׷���
};//10 ��� ���� �� ������ �ʿ䰡 ����? ������ ����Ŭ������ �۵��� ���ϱ� 

template<int size>
class StaticArrayy<char, size> : public StaticArray<char, size> {
public:
	void print() {
		for (int c = 0; c < size; ++c)
			cout << (*this)[c];
		cout << endl;
	}
};

//4 3template<class T, int size>
//void print(StaticArray<T, size>& array) {
//	for (int c = 0; c < size; ++c)
//		cout << array[c] << ' ';
//	cout << endl;
//}

//4 3template<int size>//3 T�� ���ָ� �Ǵϱ� int size�� ���ܵ�, �����ϸ� �� �۵��ȴ�
//void print(StaticArray<char, size>& array) {
//	for (int c = 0; c < size; ++c)
//		cout << array[c];
//	cout << endl;
//}
//4 3�̹����� �� �Լ����� ����Լ��� �־��


int main() {
	//9 2StaticArray<int, 4> int4;
	StaticArrayy<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	//5 2print(int4);

	//9 2StaticArray<char, 14> char14;
	StaticArrayy<char, 14> char14;
	strcpy_s(char14.getArray(), 14, "Hello, Word");
	//5 2print(char14); //2 �������� ����ϴµ� ���ڵ� ��ĭ��ĭ�� �� ����ϴϱ� �̻��ϳ�

	int4.print();
	char14.print();//6 2���������� �۵��� ������ ���ó�� ����ȶ������̼��� ������
	//11 �۵��غ��� ������� ����ȶ������̼��� �� �۵��ϴ� ���� Ȯ���� �� �ִ�.
	//�����ϸ� ���ø� �Ķ���Ͱ� �������� ��쿡 ��� �� ����ȶ������̼� �ϴ°� �ƴ϶� �κ������� ����ȷ������̼� �ϴ� ����� ���� ������ ��Ƚ��ϴ�
	//�׸��� �Ϲ����� �Լ��� �ƴ� ����Լ��� ��ӱ����� �������̵� ������� �κ� ����ȶ������̼� ���ָ� ���� ���ϴ� ��

	return 0;
}