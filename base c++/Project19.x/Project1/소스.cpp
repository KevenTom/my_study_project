//현대적 c++에서는 프로그래밍의 유연성을 높여주고 프로그래밍을 편하게 해주는 람다함수 와 std::function을 배워보겠습니다.
#include<iostream>
#include<vector>
#include<algorithm> //for_each
#include<functional>

using namespace std;

void goodbye(const string& s) {
	cout << "Goodbye " << s << endl;
}

class Object {
public:
	void hello(const string& s) {
		cout << "Hello " << s << endl;
	}
};

int main() {
	//람다함수는 익명함수라고도 부릅니다. 말그대로 이름이 없어도 됩니다.
	//[object](int p_) ->int {return my_mode * p_; }
	//람다함수는 크게 4개의 부분으로 구성되어 있습니다.
	//[]를 개시자(intorducer), ()를 인자(parameter), ->를 리턴타입(return-type), {}를 함수의 몸통(statement)

	//[]는 개시자로 그 안에 어떤 외부 변수를 써 넣는다면 이를 람다함수 내부에서 사용할 수 있게 됩니다.
	//()는 평범한 함수와 동일하게 작동하는 파라미터 입니다.
	//->는 리턴타입으로 위의 ->int의 경우, int를 리턴합니다. (void일 경우 ->를 생략 가능합니다)
	//{}는 마찬가지로 함수의 몸통입니다.
	//??그리고 몸통 뒤에 ()를 붙여서 작동시킬수 있습니다. (  예 : []() { cout << "foo" << endl; }()  )

	//이처럼 런타임시 이름은 없지만, 메모리 상에 임시적으로 존재하는 클로져 (Closure) 객체가 생성됩니다.

	if (false) {
		//1 람다 함수를 간단하게 사용해 보았습니다.
		[](const int& i) -> void {
			cout << "Hello world" << endl;
		}(123);
		//Hello world
		//지금은 이게 필요한가 생각하실수 있지만,
		//만약 평범한 함수를 정의하고 바디만들고 가져다 쓰고 하는 등 잡다한걸 구현할게 많은경우에는 번거로워집니다.
		//이때 람다함수를 사용하면 훨씬 유연하게 프로그래밍을 하실수 있습니다.


		auto func = [](const int& i) {
			cout << "Hello world" << endl;
		};
		func(123);
		//2 람다함수도 펑션포인터처럼 사용할수 있습니다.


		string name = "JACKJACK";
		[&]() {cout << name << endl; }();
		//3 인트로듀서에 &을 넣어주면 접근가능한 모든 변수들을 레퍼런스로 가져올 수 있습니다.
		//[=]는 모든 변수들을 값으로 가져옵니다. 또는 두개를 섞어서 사용할수 있다.


		//4 람다펑션은 STL과 같이 사용하실 수 있습니다.
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
		//1
		//2
		//for_each를 사용할때 원래 방식대로 수행할 함수를 정의를하고 갖다 집어 넣고 하면 많이 번거롭죠
		//람다함수로 편하게 사용하실 수 있습니다.


		//클로져 객체들은 암묵적으로 정의된 복사 생성자와 소멸자를 가지고 있습니다. 정보가 필요하면 검색 ㄱㄱ

		//람다펑션을 처음사용할때는 익숙하지 않고 이게 왜 필요한지 의야하실때가 많습니다.
		//하지만 사용하시다 보면 람다함수때문에 코딩이 훨씬 편해진다는걸 알수 있을겁니다.
	}


	if (true) {
		//5 이번에는 std::function을 소개해 드리겠습니다.
		//그전에 Callable을 알아야 합니다. https://modoocode.com/254#page-heading-1
		//std::fuction은 이런 callable들을 보관할수 있는 객체입니다.
		auto func2 = [](int val) {cout << val << endl; };
		std::function<void(int)> func3 = func2; //void가 리턴타입, int가 파라미터 입니다.
		func3(123);
		//123
		//잘 작동하는것을 확인할 수 있습니다.


		//6 더 편하게 코딩하는 방법이 있습니다.
		//어떤 경우에는 파라미터가 있는게 불편한 경우가 있습니다.
		std::function<void()> func4 = std::bind(func2, 456);
		func4();
		//이때 bind를 이용하여 편하게 사용하실 수 있습니다.


		//7 std::function과 std::bind를 같이 사용하실때 placeholders를 알아두시면 좋습니다.
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);
		//object클래스의 멤버함수 hello를 바인드 하려고 합니다.
		//멤버펑션이기 때문에 바인드 하려면 Object 클래스의 객체가 필요합니다.
		//그래서 멤버함수의 포인터를 넣어주고, 객체를 넣어주고, hello함수의 파라미터가 하나니까 placeholders::_1를 잡아줍니다.
		f(string("World"));
		//Hello World

		//당연히 그냥 함수도 바인딩할수 있습니다.
		auto f2 = std::bind(&goodbye, std::placeholders::_1);
		f2(string("World2"));
		//Goodbye World2


		//이것도 람다함수처럼 왜 필요한지 모르실수 있지만 요것도 한번 익숙해지시면 아주 편해집니다. 
		//초보때는 쓸일이 많지는 않을것이고 코드가 복잡해지면 아주 행복하게 사용하실수 있다고 합니다. 끝
	}
}