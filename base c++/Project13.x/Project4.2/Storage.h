#pragma once
#include <iostream>

template<typename T>
class Storage
{
	T m_value;
public:
	Storage(T value)
		:m_value(value)
	{}

	~Storage(){}

	void print() {//5 만약 더블타입에 대해서는 특수한 동작을 하게 하려면 어떻게 해야 할까?
		std::cout << m_value << '\n';
	}
};

//7 2template<> 
//void Storage<double>::print() { //6 이렇게 해주면 된다. 실행해보면 정상적으로 출려되는것을 알 수 있다.
//	std::cout << "double type : ";
//	std::cout << std::scientific << m_value << '\n';
//}//7 2만약 이것도 cpp 파일로 옮기려면 어떻게 해야할까?