#include "Myarray.h"

template<typename T>
void Myarray<T>::print() { //11 2어 옮기니까 오류뜨네 오류가 발생하는 원리를 확인하기 위해 진행 순서를 알아보자 소스.cpp ㄱㄱ (만일 이 코드가 template이 아니었다면 정상 동작한다)
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}//12 좋은 방법으로 이 코드를 컴파일 할때 char 타입으로 컴파일 해야한다고 알려주는 방법이 있다. 이걸 explicit instantiation 이라 부릅니다.
//함수 템플릿을 할때도 자동으로 인스턴시에이션 해줬죠?
//또한 코드가 헤더파일에 있을때도 자동으로 인스턴시에이션을 해줬죠?
//이번에는 cpp파일에 있기 때문에 컴파일러가 알수있기 힘들기 때문에 명시적으로 인스턴스화(explicit instantiation)를 해줘야 한다

//15 2template void Myarray<double>::print();
//template void Myarray<char>::print(); //13 사용법은 간단하다 

//14 그런데 cpp로 옮겨주는 함수가 많아지면 매번 이렇게 해주기는 번거롭죠

//15 2클래스 자체를 인스턴시에이션 해주는 방법이 있습니다. 끝
template class Myarray<char>;
template class Myarray<double>;