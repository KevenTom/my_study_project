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

	void print() {//5 ���� ����Ÿ�Կ� ���ؼ��� Ư���� ������ �ϰ� �Ϸ��� ��� �ؾ� �ұ�?
		std::cout << m_value << '\n';
	}
};

//7 2template<> 
//void Storage<double>::print() { //6 �̷��� ���ָ� �ȴ�. �����غ��� ���������� ����Ǵ°��� �� �� �ִ�.
//	std::cout << "double type : ";
//	std::cout << std::scientific << m_value << '\n';
//}//7 2���� �̰͵� cpp ���Ϸ� �ű���� ��� �ؾ��ұ�?