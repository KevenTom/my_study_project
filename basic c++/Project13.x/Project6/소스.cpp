//앞의 두 강의는 템플릿을 특수화 하는 방법에 대해 설명해 드렸죠
//이번에는 템플릿을 특수화 하긴 하는데 부분적으로만 특수화하는 방법에 대해 알아봅시다.
#include<iostream>

using namespace std;

template<class T, int size> //1 이 클래스같은 경우는 클래스t에 대해서 템플릿타이즈 되어 있고 int size에 대해서 파라미터라이즈 되어 있습니다
class StaticArray {
	T m_array[size];
public:
	T* getArray() {
		return m_array;
	}

	T& operator[](int index) {
		return m_array[index];
	}

	void print() {//6 2 멤버함수로 print 추가함
		for (int c = 0; c < size; ++c)
			cout << m_array[c] << ' ';
		cout << endl;//7 근데 멤버펑션은 스페셜라이즈 해주기가 번거롭다.
		//좀 편한방법이 있는데 클래스를 상속 받는 방법이 있다.
	}
};

template<class T, int size>
class StaticArrayy : public StaticArray<T, size> { //8 상속으로 해주는 이유가 뭐냐면 템플릿을 통째로 싹다 복사해서 스페셜라이즈 하는것보단 이게 훨씬 쉬워서 그렇다
};//10 얘는 굳이 뭘 적어줄 필요가 없죠? 어차피 마더클래스로 작동할 꺼니까 

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

//4 3template<int size>//3 T만 없애면 되니까 int size는 남겨둠, 실행하면 잘 작동된다
//void print(StaticArray<char, size>& array) {
//	for (int c = 0; c < size; ++c)
//		cout << array[c];
//	cout << endl;
//}
//4 3이번에는 이 함수들을 멤버함수로 넣어보자


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
	//5 2print(char14); //2 문제없이 출력하는데 문자도 한칸한칸씩 띄어서 출력하니까 이상하네

	int4.print();
	char14.print();//6 2정상적으로 작동은 하지만 방금처럼 스페셜라이제이션을 해주자
	//11 작동해보면 상속으로 스페셜라이제이션이 잘 작동하는 것을 확인할 수 있다.
	//정리하면 템플릿 파라미터가 여러개일 경우에 모두 다 스페셜라이제이션 하는게 아니라 부분적으로 스페셜랴이제이선 하는 방법에 대해 설명해 드렸습니다
	//그리고 일반적인 함수가 아닌 멤버함수는 상속구조로 오버라이딩 방식으로 부분 스페셜라이제이션 해주면 좀더 편하다 끝

	return 0;
}