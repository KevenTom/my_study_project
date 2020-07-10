//c, c++로 프로그래밍으로 할때 가장 번거로운점은 new, delete로 직접 관리해야한다는 점일겁니다.
//현대에서는 스마트포인터 라는것을 도입하여 이런 부분을 상당부분 개선했습니다.
//여기서는 스마트포인터와 스마트포인터를 이해할때 필요한 '이동'(move semantics)애 대해 알아봅시다.
#include<iostream>
#include"Autoptr.h" //6 방금 만든 autoptr을 사용해보자

using namespace std;

//1 int 타입의 데이터를 담고있는 간단한 클래스입니다.
class Resource {
public:
	int m_data[100];
public:
	Resource() {
		cout << "Resource constructed" << endl;
	}
	~Resource() {
		cout << "Resource destroyed" << endl;
	}
};

void dosomething() {
	//8 3Resource* res = new Resource; //7 요렇게 동적으로 메모리를 할당받고 있지만 책임을 안지고 delete 해줘야 하는 ptr을 dull pointer 라고 부른다.
	Autoptr<Resource> res(new Resource);//8 3 이렇게 smart pointer 를 만들어 보았다.
										//실행해보면 delete 하지 않아도 소멸자로 자동으로 delete 해주는것을 알 수 있다.


	if (true) { //3 이처럼 먼저 early return 할 경우, 당연히 delete를 넣어주면 해결할수 있다. 하지만 예외처리에서도 실수로 delete를 건너가도록 코딩할 수도 있다.
				//이처럼 번거로운것은 마찬가지다. 정통적은 c++ 강의에서는 "꼮! delete 하고 나가라!" 라고 가르쳤는데 최근에 모던c++에서는 스마트포인트를 사용합니다.
				//스마트포인터에서는 delete할 필요가 없어집니다.

		return;
	}


	//8 3delete res; //2 동적할당된 데이터를 delete 해주고 있다. 이처럼 new 한 곳에서 delete 해주는 것을 RAII라 부릅니다.
					//RAII는 C++에서 자주 쓰이는 idiom으로 자원의 안전한 사용을 위해 객체가 쓰이는 스코프를 벗어나면 자원을 해제해주는 기법이다.
					//프로그래밍 하면서 실수할때가 있다. 예를들어 delete를 까먹거나
	return;
}

int main() {
	//9 dosomething(); 이번에는 다른 예제를 살펴봅시다.
	
	Autoptr<Resource> res1(new Resource);
	Autoptr<Resource> res2;

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << '\n' << endl;

	res2 = res1; //10 보면 대입을 해주는것을 알수 있다. 디폴트 어사이먼트 오퍼레이터는 그냥 복사만 해주죠 그러니까 내부적으로 멤버를 복사해주겠죠?
	//12 결론적으로 얘가 문제죠. 그럼 주소를 하나만 가지게, 즉 소유권을 하나만 가지게 하려면 어떻게 해결해야 할까요
	//가장 좋은방법은 소유권을 하나만 가질수 있게 소유권을 주면 res1을 박탈하게 하면 되겠죠? 즉 소유권을 이전하게 해주면 되겟죠

	//17 작동하면 정상적으로 작동하는것을 확인할 수 있다. 이렇게 소유권을 이전나는 것을 move semantics 라고 한다.
	//systax vs. semantics
	//신텍서는 문법이 맞냐 안맞냐, 컴파일이 되냐 안되냐
	//시멘틱스는 컴파일이 되는것은 똑같은데 내부적으로 의미가 뭐냐

	//int x = 1, y = 1;
	//x + y;
	//string str1("Hello"), str2("World");
	//str1 + str2;
	//이처럼 숫자끼리 '+' 라는 것은 숫자를 더한다는 의미지만 문자에서 '+'를 여기서는 문자열에 문자열을 붙인다로 사용한다. 즉 +의 의미가 다르다. 이런걸 시멘틱스라 부른다.
	//즉 똑같이 대입을 하든 파라미터를 넣든 똑같은데 받는 입장에서 기능을 어떻게 할지는 시멘틱스에 따라 달라진다고 할 수 있다.
	//c++에서 알아야 할 시멘틱스는
	//value semantics(copy sematics)
	//reference sematics(pointer)
	//move semantics(move>
	//가 있다. 우리가 방근 복사생성자를 만들때 복사생성자를 만든 것이 아닌, 무브시멘틱스를 구현했다고 할수 있습니다. 그리고 다시말하지만 autoptr은 없어졌다 끝

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;
	//11 런타임 에러가 발생한다. 보면 알겠지만 소멸자가 두번 실행된다. 지웠던 메모리를 다시 지우려고 하니까 런타임 에러가 납니다.


	return 0;
}