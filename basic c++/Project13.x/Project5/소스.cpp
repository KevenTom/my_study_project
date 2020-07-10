//앞에서 함수템플릿 스페셜라이제이션(specialization)을 하는 방법을 배웠다면 이번에는 클래스템플릿 특수화에 대해 배워보겠습니다.
#include <iostream>

using namespace std;

template<typename T>
class A {
public:
	void doSimething() {
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};

template<>
class A<char> {
public:
	void doSimething() {
		cout << "char type!!" << endl;
	}
	//테스트함수 없음

}; //2 실행하면 스페셜라이제이션 된 클래스로 작동되는것을 확인할 수 있습니다.
//주의사항이 있는데 코드길이를 보면 사실상 복사붙여넣기랑 비슷하죠? 사실상 다른 클래스라고 보셔도 되요 예를들어 클래스템플릿에는 test함수가 있고 여기에는 없죠?

int main() {
	A<int> a_int;
	A<double> a_double;
	A<char> a_char;

	a_int.doSimething();
	a_double.doSimething();
	a_char.doSimething();//1 딱히 문제없이 출력되는것을 확인할 수 있다.
						//이떄 char 타입에 대해서만 특별한 행동을 하도록 스페셜라이즈 해보겠습니다.
	a_int.test();
	//4 2a_char.test(); //3 일반 클래스템플릿은 test(); 호출이 가능하지만 스페셜라이제이션한 클래스는 호출이 안되는것을 알 수 있습니다.
	//4 2그래서 혹시나 상속과 해깔릴수 있는데 아니라 그냥 클래스를 따로 만드는거랑 비슷하다
	//5 클래스에 생성자를 만들고 인수를 넣어주면 <int> 이런걸 넣어줄 필요 없다고 동영상에 있는데 귀찮아서 안넣음 보고싶으면 5분10초
	//그뒤는 간단한 예제인데 복잡해 딱히?? 필요 없을거 같음 끝

	return 0;
}