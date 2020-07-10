#pragma once
#include<iostream>

//4 엤날에는 auto_ptr을 사용했는데 이거 복잡하면 오류가 발생하니까 c++17에 없어지고 스마트포인터로 진화했다고 생각하면 된다.
//아래의 클래스는 auto_ptr을 간단하게 예제로 만들어본 것이다.
template<class T>
class Autoptr {
public:
	T* m_ptr = nullptr;
public:
	Autoptr(T*ptr = nullptr)
		:m_ptr(ptr)
	{}

	~Autoptr() {
		if (m_ptr != nullptr) delete m_ptr; //5 보면 뭔가 특별한일을 하는건 아니고 그냥 nullptr이 아니면 delete 해주는 것이다.
											//하지만 이런 간단한일도 자동으로 해준다면 충분히 편하겠죠??
	}


	Autoptr(Autoptr& a) { //13 소유권을 해결하기 위해 복사생성자랑 =오퍼레이터를 추가했다.
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; //14 보면 메모리를 주던 a에게 nullptr 하는것을 알 수 잇다. 즉 소유권을 이동시켰다고 할 수 있다.
	}

	Autoptr& operator=(Autoptr& a) {
		if (&a == this)
			return *this; //15 자기가 자기를 복사하면 아무것도 하지말고 그냥 리턴하고

		delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; //16 마찬가지로 a에게 nullptr 하는것을 알 수 있다.
		return *this;
	}
	
	T* operator*() const { return *m_ptr; };
	T* operator->() const { return m_ptr; };
	bool isNull() const { return m_ptr == nullptr; }
};