#include "Storage.h"

template<>
void Storage<double>::print() {
	std::cout << "double type : ";
	std::cout << std::scientific << m_value << '\n';
} //8 실행해보면 어라 스페셜라이제이션이 안되고 있네요
//엄밀히 말하면 이 컴파일러가 스페셜라이제이션을 할수 있다는걸 모르고 있어요

//9 해결방법으로는 그냥 해더파일로 옮기는 방법 (보통 이렇게 많이 합니다.)
//요즘 cpp파일 오픈소스를 보면 해더 온리 인 경우가 많다.
//두번쨰 방법으로 메인에서 cpp 파일을 인클루드 하는 방법이지만 저번 강의에서 말한것처럼 cpp좋은 방법은 아니다.
//강사가 많이본 방법은 결국 다 해더에 다 집어 넣는 경우가 많았고 해더를 여러개 쓰는 경우도 있다고 한다. 끝

template void Storage<double>::print(); //안나왔지만 이런 방식도 있던데?