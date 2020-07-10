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

//3 2"�� ���"�� �ͼ� int�� ���� ���� ����ó�� ���� Ÿ���� ������� �Ѵ�.

template<typename T>
//6 �ٵ� Ŭ�����ȿ� ���� �ڵ带 ������� �ִ� ������
//���߿� �ϳ��� Ŭ���� ������ �����ڽ��ϴ�.
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

	//7 2void print() { //7 2print �Լ��� ���Ǹ� ������ �̵��� ���ô�. (������Ŭ��-> �����۾�-> ���� �̵�)
	//	for (int i = 0; i < m_length; ++i)
	//		std::cout << m_data[i] << " ";
	//	std::cout << std::endl;
	//}

	void print();
};

//10 2template<typename T>
//void Myarray<T>::print() { //8 �� �׳� myarray.h�� �̵��� �ϳ� 
//	for (int i = 0; i < m_length; ++i)
//		std::cout << m_data[i] << " ";
//	std::cout << std::endl;
//} //10 2���� �׳� cpp���Ϸ� �ű�� ���? �غ���

//9 void Myarray::print() { �׳� Ŭ������ �ۿ��� ���ǵȰŶ��� �ణ �ٸ��ٴ°� �˼� �ִ�. 
//	for (int i = 0; i < m_length; ++i)
//		std::cout << m_data[i] << " ";
//	std::cout << std::endl;
//}