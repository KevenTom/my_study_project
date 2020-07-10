#pragma once
#include<cassert>
#include<iostream>

//3 2class Myarray
//{
//	int m_length;
//	int* m_data;
//public:
//	Myarray()
//		:m_length(0), m_data(nullptr)
//	{}
//
//	Myarray(int length)
//		:m_length(length), m_data(new int[length])
//	{}
//
//	~Myarray() {
//		reset();
//	}
//
//	void reset() {
//		delete[] m_data;
//		m_data = nullptr;
//		m_length = 0;
//	}
//
//	int& operator[](int index) {
//		assert(index >= 0 && index < m_length);
//		return m_data[index];
//	}
//
//	int getLength() {
//		return m_length;
//	}
//
//	void print() {
//		for (int i = 0; i < m_length; ++i)
//			std::cout << m_data[i] << " ";
//		std::cout << std::endl;
//	}
//};

//3 2"그 상사"가 와서 int만 담지 말고 저번처럼 여러 타입을 담으라고 한다.

template<typename T>
//6 근데 클래스안에 전부 코드를 집어놓고 있는 상태죠
//이중에 하나만 클래스 밖으로 빼보겠습니다.
class Myarray
{
	int m_length;
	T* m_data;
public:
	Myarray()
		:m_length(0), m_data(nullptr)
	{}

	Myarray(int length)
		:m_length(length), m_data(new T [length])
	{}

	~Myarray() {
		reset();
	}

	void reset() {
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	T& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() {
		return m_length;
	}

	//7 2void print() { //7 2print 함수의 정의를 밖으로 이동해 봅시다. (오른쪽클릭-> 빠른작업-> 정의 이동)
	//	for (int i = 0; i < m_length; ++i)
	//		std::cout << m_data[i] << " ";
	//	std::cout << std::endl;
	//}

	void print();
};

//10 2template<typename T>
//void Myarray<T>::print() { //8 어 그냥 myarray.h로 이동을 하네 
//	for (int i = 0; i < m_length; ++i)
//		std::cout << m_data[i] << " ";
//	std::cout << std::endl;
//} //10 2예를 그냥 cpp파일로 옮기면 어떨까? 해보자

//9 void Myarray::print() { 그냥 클래스가 밖에서 정의된거랑은 약간 다르다는걸 알수 있다. 
//	for (int i = 0; i < m_length; ++i)
//		std::cout << m_data[i] << " ";
//	std::cout << std::endl;
//}