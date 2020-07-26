#pragma once
#include<iostream>

//4 �x������ auto_ptr�� ����ߴµ� �̰� �����ϸ� ������ �߻��ϴϱ� c++17�� �������� ����Ʈ�����ͷ� ��ȭ�ߴٰ� �����ϸ� �ȴ�.
//�Ʒ��� Ŭ������ auto_ptr�� �����ϰ� ������ ���� ���̴�.
template<class T>
class Autoptr {
public:
	T* m_ptr = nullptr;
public:
	Autoptr(T*ptr = nullptr)
		:m_ptr(ptr)
	{}

	~Autoptr() {
		if (m_ptr != nullptr) delete m_ptr; //5 ���� ���� Ư�������� �ϴ°� �ƴϰ� �׳� nullptr�� �ƴϸ� delete ���ִ� ���̴�.
											//������ �̷� �������ϵ� �ڵ����� ���شٸ� ����� ���ϰ���??
	}


	Autoptr(Autoptr& a) { //13 �������� �ذ��ϱ� ���� ��������ڶ� =���۷����͸� �߰��ߴ�.
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; //14 ���� �޸𸮸� �ִ� a���� nullptr �ϴ°��� �� �� �մ�. �� �������� �̵����״ٰ� �� �� �ִ�.
	}

	Autoptr& operator=(Autoptr& a) {
		if (&a == this)
			return *this; //15 �ڱⰡ �ڱ⸦ �����ϸ� �ƹ��͵� �������� �׳� �����ϰ�

		delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; //16 ���������� a���� nullptr �ϴ°��� �� �� �ִ�.
		return *this;
	}
	
	T* operator*() const { return *m_ptr; };
	T* operator->() const { return m_ptr; };
	bool isNull() const { return m_ptr == nullptr; }
};