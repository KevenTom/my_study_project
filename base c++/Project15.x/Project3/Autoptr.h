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

	//9 2Autoptr(const Autoptr& a) {//4 ī�� ����Ʈ���� �Դϴ�.	 �׸��� �Ķ���͸� ���� L���� ���۷����� �ް��ִٴ� �͵� �� �� �ֽ��ϴ�.
	//	std::cout << "Autoptr copy constructor" << std::endl;

	//	//deep copy
	//	m_ptr = new T;
	//	*m_ptr = *a.m_ptr; //�ڵ尡 �����ϰ� �������� Resource ��ü�� ���� ��� Resource�� �ִ� ī�� ����̸�Ʈ�� �۵��ϰ���? �� ��ī�Ǹ� �����ϴϱ� �������ϴ�.
	//}

	//Autoptr& operator=(const Autoptr& a) {
	//	std::cout << "Autoptr copy assignment" << std::endl;

	//	if (&a == this)
	//		return *this;

	//	if (m_ptr != nullptr)delete m_ptr;
	//	
	//	//deep copy
	//	m_ptr = new T;
	//	*m_ptr = *a.m_ptr;	 //5 ���ó� �̰� ȣ��Ǹ� ��ī�ǰ� �Ͼ�ϱ� �������̴ϴ�.
	//	return *this;
	//}

	//9 2�̹����� ī������Ʈ����, ī�Ǿ���̸�Ʈ�� �ּ�ó���ϰ�, ��������Ʈ���Ϳ� �������̸�Ʈ�� Ȱ��ȭ �غ��� �ڵ带 �����ϱ� ���� ���� �ӵ��� Ȯ���غ��ڽ��ϴ�.
	//11 �ΰ��� ���� r���� ���۷����� �޴´ٴ°��� Ȯ���� �� �ֽ��ϴ�.
	//�� �޸𸮴� ����� �ڸ������� �ƴϰ� ��� ����ٰ� ������ڴٴ� �̴ϴ�.

	Autoptr(Autoptr&& a) //13 �̹����� �ڵ带 ������ �帮�ڽ��ϴ�. R���� ���۷����� �޾ƿ��� �����͸� ������ ������ ���� a�� nullptr�� ������شٴ°� �� �� �ֽ��ϴ�.
		:m_ptr(a.m_ptr) {
		//shallow copy
		std::cout << "Autoptr move constructor" << std::endl;

		a.m_ptr = nullptr;
	}

	Autoptr& operator=(Autoptr&& a) { // ���������� R������ �ް� �����ϰ� nullptr�� ����� �شٴ� ���� �� �� �ֽ��ϴ�. ��
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