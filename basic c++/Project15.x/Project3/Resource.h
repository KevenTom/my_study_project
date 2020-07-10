#pragma once
#include<iostream>

class Resource {
public:
	int *m_data = nullptr;
	unsigned m_length = 0;
public:
	Resource() {
		std::cout << "Resource default constructed" << std::endl;
	}

	Resource(unsigned length) {
		std::cout << "Resource length constructed" << std::endl;
		this->m_data = new int[length];
		this->m_length = length;
	}

	Resource(const Resource& res) { //2 카피 컨트스럭쳐가 있는데
		std::cout << "Resource copy constructed" << std::endl;

		Resource(res.m_length);

		//deep copy
		for (unsigned i = 0; i < m_length; ++i) //내용물을 하나하나 복사하고 있죠 앞 강의에 배웠던것처럼 딥카피라고 불리죠 대신 느리죠
			m_data[i] = res.m_data[i];
	}

	~Resource() {
		std::cout << "Resource destroyed" << std::endl;

		if (m_data != nullptr) delete[] m_data;
	}

	Resource& operator=(Resource& res) { //3 카피 어사이먼트 또한 똑같습니다. 마찬가지로 하나하나 복사하다 보니까 느려집니다.
		std::cout << "Resource copy assignment" << std::endl;

		if (&res == this) return *this;

		if (this->m_data != nullptr)delete[] m_data;

		m_length = res.m_length;
		m_data = new int[m_length];

		//deep copy
		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];

		return *this;
	}
};
