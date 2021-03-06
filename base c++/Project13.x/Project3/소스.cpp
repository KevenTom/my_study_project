//앞에서 함수템플릿, 클래스템플릿 사용할때는 템플릿의 매개변수로 자료형이 들어갔죠
//여러가지 자료에 대해서 코드를 일반화 하기 위해서 자료형을 템플릿의 매개변수로 사용했습니다.
//이번에는 자료형이 아닌 템플릿 매개변수 사용하는 방법을 설명해 드리겠습니다.
#include<iostream>
#include"Myarray.h"

using namespace std;

int main() {
	Myarray<double, 100> Myarray; //1 우리가 배열을 사용할때는 std::array<double, 100> 처럼 자료형과 데이터가 몇개 들어갈지 템플릿을 만들어서 사용할 예정입니다
								//3 다시보면 코딩하실때 100이라고 입력했잖아요 백터같은경우 백터를 만들고 .resize(100) 이렇게 했었죠
								//하지만 컴파일 타임에 값이 정해진 것들만 사용할 수 있기 때문에 숫자를 적어놔야 하고
								//변수는 말 그대로 값이 변할 수 있어 런타임에서 최종 값이 정해지기 때문에 변수도 사용할 수 없습니다.
								//그러니까 여기에 들어가는 숫자는 컴파일타임이 결정이 되어있는것만 들어갈 수 있습니다.
								//const 변수는 넣어줄 수 있습니다. 근데 const로 넣어줘봤자 의미가 없기 때문에 그냥 해줄때가 많습니다.
	//템플릿의기본적인 원리가 사람이 코딩을 안해줘도 경우에 맞춰서 컴파일을 "다시" 해주는 겁니다. 때문에 컴파일하기 전에 미리 매개변수가 결정되어 있어야 하겠죠?
	//Myarray<char> my_array(10);
	//앞강의에서 했던 코드인데 저 숫자에 넣어주는 것은 런타임때 결정해도 되는거죠? 그러나 마찬가지로 char 타입에 대해서는 미리 알려져야 있어야 사용할 수 있었습니다.
			
	for (int i = 0; i < Myarray.getLength(); ++i)
		Myarray[i] = i + 65;

	Myarray.print(); //6 실행하면 문제없다는걸 알 수 있습니다.
	//지금은 갯수로 데이터를 몇개 담을지 결정하는 파라미터로 100 넣어줬지만 사실 이런 방식보단 메모리 갯수를 결정하는것보단
	//알고리즘 구현할때 이차원일때는 이렇게 구현하고 삼차원일때는 이렇게 구현하고 이런경우에도 사실 많이 사용합니다 그냥 알아 두라고 끝

	return 0;
}