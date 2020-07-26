//다른 클래스를 담는 클래스를 컨테이너 클래스 라고 부릅니다. 컨테이너 클래스에 대해 알아봅시다.
#include <iostream>
#include <vector>
#include <array>

int main()
{
	//1 지금까지 여러가지 컨테이너 클래스들을 사용해 왔죠

	std::vector<int> int_vec;//3 이경우에는 int가 백터에 담겨있는거죠
	std::array<int, 10> int_arr;//2 이런식으로 백터나 어레이 같은 컨테이너들을 사용해 왔어요
								//5 위키에서 스탠다드 템플릿 라이브러리 가보면 컨테이너 종류가 많이 적혀 있다.
	return 0;
}