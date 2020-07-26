//여러분들이 현대적 c++문법을 사용하시다보면 std::forward 함수를 여기저기서 보시게 됩니다.
//std::forward는 완벽한 전달을 구현할때 사용이 되는데요 이 의미를 모르는 상태에서 접하시게 되면은 당황하실수 있습니다.
//여기서는 완벽한 전달의 의미와 L벨류 레퍼런스, R벨류 레퍼런스, 무브시멘틱스와 연관지어서 어떻게 구현을 하고 사용하는지 알려드리겠습니다.

//첫번째 예제에서는 딱 문법만 알려드리고, 두번째 예제에서는 여러가지 연관되어있는것들을 쫙 훑어가면서 설명해드리겠습니다.
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
void func_wrapper2(T&& t) { //3 사용법은 파라미터를 R벨류 레퍼런스를 받아오는것처럼 해주고
	func(forward<T>(t));	//그리고 forward를 이용해서 전달을 해주면 됩니다.
}							//forward가 하는 일은 t가 들어올때 만약 L벨류 레퍼런스로 들어온다면 L벨류 레퍼런스로 주고 R벨류 레퍼런스로 들어온다면 R벨류로 리턴해줍니다.


int main() {
	MyStruct s;

	func(s);
	func(MyStruct());
	//Pass by L - ref
	//Pass by R - ref
	//1 정상적으로 L벨류 R벨류로 들어가는것을 알수 있습니다.
	//이렇게 직접적으로 사용하는것은 컴파일러가 L벨류인지 R벨류인지 구분을 해줍니다.
	//문제가 생기는 것은 템플릿을 사용할때는 구분을 못해줍니다.

	func_wrapper(s);
	func_wrapper(MyStruct());
	//Pass by L - ref
	//Pass by L - ref
	//템플릿을 사용하면 구분을 못해주기 때문에 둘다 L벨류레퍼런스 처럼 실행이 되어버립니다.

	//2 이럴때 우리는 forward을 사용하실수 있습니다.
	func_wrapper2(s);
	func_wrapper2(MyStruct());
	//Pass by L - ref
	//Pass by R - ref
	//4 이처럼 각각의 맞게 파라미터로 전송되는것을 확인할 수 있습니다.


	return 0;
}