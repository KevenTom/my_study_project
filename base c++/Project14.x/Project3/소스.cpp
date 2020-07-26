//지금까지는 예외를 던지거나 받을때 기본자료형을 사용했죠
//이번에는 사용자 정의 자료형, 그러니까 예외 클래스를 만드는 방법에 대해 설명해드리고 상속을 사용할때 주의해야할점도 설명해드리겠습니다.
#include<iostream>

using namespace std;

class Exception { //3 예외처리에 사용할 클래스를 만들어 봤습니다.
public:
	void report() {
		cerr << "Exception report" << endl;
	}
};
class ArrayException : public Exception {
public:
	void report() {
		cerr << "Array exception" << endl;
	}
};

class Myarry {
	int m_data[5];
public:
	int& operator[](const int& index) {
		//4 2if (index < 0 || index >= 5) throw - 1;//2 우리가 이렇게 기본자료형만으로 예외를 던진다면 사실 표현하지 못하는것도 많겠죠
												//또 어떤경우에는 자료형만 가지고 어떤 예외인지 알수있지 않을까 생각할 수도 있고
												//예외를 던진 후에 캐치에서 하는 작업들을 어떤 함수나 클래스로 따로 정의하고 싶은데 어떤 방법 없을까
												//생각할수 있죠 이럴때 여러분이 직접 예외클래스를 만들 수 있습니다.

		//7 4if (index < 0 || index >= 5) throw Exception(); //4 2 한번 익섹션클래스의 오브젝트를 던져보겠습니다.
														//6 지금은 간단한 예제라서 디폴트생성자를 사용하고 별다른 파라미터나 멤버가 없지만 뭔가 정보를 담아서 넣어줄수 있겠죠
		if (index < 0 || index >= 5) throw ArrayException();//7 4 주의할점이 있는데 상속구조를 줄때는 다형성떄 배운 객체잘림이 일어날 수 있습니다.
		return m_data[index];
	}
};

void dosomething() {
	Myarry my_array;

	try {
		my_array[100]; //1 if문 보다 큰 숫자를 넣었으니까 당연히 예외처리가 될겁니다.
	}
	catch (const int& x) {
		cerr << "Exception" << x << endl;
	}
	catch (ArrayException & e) {//7 4 이렇게 위로 옮겨주면 해결 된다.
		e.report();
		throw e; //10 이럴때 캐치한걸 다시 던질수 있습니다. 다만 여기서 던지면 스택 위와인딩이 되서 바로 매인에서 받게 됩니다.
	}
	catch (Exception & e) {//5 익세션을 받을수 있는 캐치를 만들어 봤습니다. 실행해보면 문제없이 오류를 출력하는것을 확인하실 수 있습니다.
		e.report();
		//11 throw e; 참고로 자식 객체를 받을때 부모클래스가 받고 다시 던지면 부모객체를 던집니다.
		//12 throw; 해결 방법으로는 그냥 쓰로우 해주면 받은 객체를 그대로 보낸다고 생각하면 됩니다. 끝
	}
	//catch (ArrayException & e) {//7 4 자식클래스를 받아주는 캐치를 여기다 만들면 exception캐치 아래에 있기 때문에 exception캐치 위에다가 적어주면 해결가능하다.
	//	e.report();
	//}
}

int main() {

	//8 이번에는 이부분에도 try를 만들어주면 어떻게 작동할까?
	try {
		dosomething();
	}
	catch (ArrayException & e) {//9 당연히 dosomething 안에서 예외처리가 되었기 때문에 여기에있는 캐치는 작동하지 않는다.
								//하지만 어떤경우에는 바깥에서도 또 예외처리를 하고싶은 경우에도 있어요 어떻게 해야할까요?
		cout << "mian" << endl;
		e.report();
	}



	return 0;
}