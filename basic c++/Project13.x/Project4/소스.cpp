//템플릿 프로그래밍을 하다보면 특별할 자료형에 대해서는 다른 기능을 구현하고싶을때가 있습니다.
//이럴때 사용하는 템플릿 특수화에 대해서 함수를 먼저 설명해 드리겠습니다. (specialization)
#include<iostream>

using namespace std;

template<typename T>
T getMax(T x, T y) { 
	return (x > y) ? x : y;
}

template<>//2 특수한 경우에 대해서만 적용하는것이기 때문에 일반화가 됬던거를 특수한 타입에만 적용되게 하는 거꾸로 가는 형태죠? 그냥 알아두라고
char getMax(char x, char y) { //3 다시정리하면 getMax라는 템플릿이 된 함수가 있는데 이 함수를 특별한 경우 여기서는 char타입에 대해서 인스턴시에이션이 되는 경우엔 얘를 사용해라 하게 된다.
	cout << "Warring : char type" << endl;

	return (x > y) ? x : y;
}

int main() {

	cout << getMax(1, 2) << endl; //1 앞강의에서 사용한 getMax 입니다. 커서를 갖다대면 저번에 배운 인스턴시에이션이 자동으로 되어 있다는걸 알수 있습니다.
	//어떤 경우에는 1, 2를 더블타입으로 쓰고싶을때가 있죠 (getMax(1.0, 2.0) 또는 getMax<double>(1, 2))
	//만약 getMax에 문자를 넣는다면 문자끼리 비교한다는 경고문을 띄어주길 원할수도 있습니다.
	//즉 특별한 자료형에 대응할수 없을까?
	//일단 컴파일타입에 해결해야하기 때문에 if문을 쓸수는 없다.
	//이때 스페셜라이제이션(specialization)을 사용하실 수 있습니다.

	cout << getMax('a', 'b') << endl;

	return 0;
}