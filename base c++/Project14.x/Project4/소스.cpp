//앞 강의에서 예외클래스를 만드는 방법에 대해 설명해 드렸습니다.
//이번에는 스탠다드 라이브러리에 포함되어있는 std::exception 클래스에 대해 설명해 드리겠습니다.
//std::exception는 아주 다양한 경우에 대해서 이미 각각 구현되어있기 때문에 우리가 하나하나 예외클래스를 만들필요 없게 해줍니다.
#include<iostream>
#include<exception>//1 보시면 exception을 인클루드 해주셔야 사용하실 수 있습니다.
#include<cstring>

using namespace std;

class CustomException : public exception {//6 이번에는 exception클래스를 상속받아서 새로운 클래스를 만들어 봤습니다.
public:
	const char* what() const noexcept override {//7 대신 다른 exception클래스처럼 작동하게 하려면 다른 클래스들처럼 what() 함수를 오버라이드 해줘야 합니다. (noexcept는 noexcept붙어있는 바디 안에서는 예외를 던지지 않겠다 라는 뜻임, c++11부터는 noexcept를 붙여줘야 한다고 함)
		return "custom exception";
	}
};

int main() {
	try {
		//7 3string s;
		//s.resize(-1); //2 의도적으로 오류를 일으켰습니다. 참고로 여러 표준라이브러리에서 이상한걸 감지하면 내부에서 exception을 쓰로우 하게 되어 있습니다.

		//5 여러분이 직접 클래스를 만들면서 std::exception 을 사용하고 싶을때도 있겠죠? 아래처럼 하면 됩니다.
		//7 3throw runtime_error("bad");
		
		throw CustomException(); //7 3 작동되나 한번 예외를 던져봅시다. 잘 작동하네요 끝
	}
	catch (exception & exception) {//3 참고로 exception는 부모클래스다.
		cout << typeid(exception).name() << endl; //4 typeid로 name을 찍어보면 자식클래스중 length_error 클래스로 날라왔다는것을 확인할 수 있습니다.
												//아니면 레퍼런스 메뉴얼에서 찾아보면 알 수 있다. http://www.cplusplus.com/reference/string/string/resize/
		cerr << exception.what() << endl; //3 근데 왜 에러가 길다고 뜨는걸까? 언사인드에서 -1하면 9999999... 되서 그럼
	}


	return 0;
}