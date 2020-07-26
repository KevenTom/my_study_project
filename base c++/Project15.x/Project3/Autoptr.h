#pragma once
#include<iostream>

template<class T>
class Autoptr {
public:
	T* m_ptr;
public:
	Autoptr(T* ptr = nullptr)
		:m_ptr(ptr) {
		std::cout << "Autoptr default constructor" << std::endl;
	}

	~Autoptr() {
		std::cout << "Autoptr destructor" << std::endl;

		if (m_ptr != nullptr) delete m_ptr;
	}

	//9 2Autoptr(const Autoptr& a) {//4 카피 컨스트럭쳐 입니다.	 그리고 파라미터를 보면 L벨류 레퍼런스를 받고있다는 것도 알 수 있습니다.
	//	std::cout << "Autoptr copy constructor" << std::endl;

	//	//deep copy
	//	m_ptr = new T;
	//	*m_ptr = *a.m_ptr; //코드가 간단하게 보이지만 Resource 객체를 넣을 경우 Resource에 있는 카피 어사이먼트가 작동하겠죠? 즉 딥카피를 수행하니까 느려집니다.
	//}

	//Autoptr& operator=(const Autoptr& a) {
	//	std::cout << "Autoptr copy assignment" << std::endl;

	//	if (&a == this)
	//		return *this;

	//	if (m_ptr != nullptr)delete m_ptr;
	//	
	//	//deep copy
	//	m_ptr = new T;
	//	*m_ptr = *a.m_ptr;	 //5 역시나 이게 호출되면 딥카피가 일어나니까 느려질겁니다.
	//	return *this;
	//}

	//9 2이번에는 카피컨스트럭터, 카피어사이먼트는 주석처리하고, 무브컨스트럭터와 무브어사이먼트를 활성화 해보고 코드를 설명하기 전에 먼저 속도를 확인해보겠습니다.
	//11 두개다 보면 r벨류 레퍼런스를 받는다는것을 확인할 수 있습니다.
	//즉 메모리는 제대로 자리잡은게 아니고 잠깐 생겼다가 사라지겠다는 겁니다.

	Autoptr(Autoptr&& a) //13 이번에는 코드를 설명해 드리겠습니다. R벨류 레퍼런스를 받아오고 포인터를 복사한 다음에 받은 a는 nullptr로 만들어준다는건 알 수 있습니다.
		:m_ptr(a.m_ptr) {
		//shallow copy
		std::cout << "Autoptr move constructor" << std::endl;

		a.m_ptr = nullptr;
	}

	Autoptr& operator=(Autoptr&& a) { // 마찬가지로 R벨류를 받고 복사하고 nullptr로 만들어 준다는 것을 알 수 있습니다. 끝
		std::cout << "Autoptr move assignment" << std::endl;

		if (&a == this)
			return *this;

		if (!m_ptr) delete m_ptr;

		//shallow copy
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return *this;
	}
};











//T* operator*() const { return *m_ptr; };
//T* operator->() const { return m_ptr; };
//bool isNull() const { return m_ptr == nullptr; }