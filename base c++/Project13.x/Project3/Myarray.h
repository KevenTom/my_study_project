#pragma once
#include<cassert>
#include<iostream>

template<typename T, unsigned int T_SIZE> //2 �� ������ m_length�� ��� unsugned int T_SIZE �� �߰��Ͽ����ϴ�.
class Myarray							//�̷��� T_SIZE�� ������ �ܰ迡�� T_SIZE�� �˷����־�� �մϴ�.
{
	T* m_data; //4 ��� T m_data[T_SIZE] ���ټ��� ������ �ƽôٽ��� �������� �۵��ϰ� ���� ���� ���� �� ���� ������ �����Ҵ��� ����� ���̴ϴ�. �����ϸ� �̷��� ����ص� ��
public:
	Myarray()
		:m_data(new T[T_SIZE])
	{}

	~Myarray() {
		delete[] m_data;
		m_data = nullptr;
	}

	T& operator[](int index) {
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength() {
		return T_SIZE;
	}

	void print() {//5 �տ��� �� �Լ��� .cpp �� �־ �ͽ��ø� �ν��Ͻÿ��̼� �ؾ��ϴ°� �ƽ���? �ٵ� �� T_SIZE�� ����ε� int�߿��� ��� ���ڵ� ���ü� �ְ�
		for (int i = 0; i < T_SIZE; ++i)//����� ���ݾƿ� �׷��� ���� ���� �ͽ��ø��ν��Ͻÿ��̼��Ѵٸ� ��� �����Ʈ int���ڸ� ����� �մϴ�. �Ұ�������
			std::cout << m_data[i] << " ";//�׷��� ��Ÿ���Ķ���͸� ����Ҷ��� �׳� �ش��� �����ϰ� ����ؾ� �Ѵ� ����
		std::cout << std::endl;
	}
};