#pragma once
#include<iostream>

class Person //���̺� ����� Ŭ����
{
private:
	int ssn; //�ֹε�Ϲ�ȣ
	std::string name; //�̸�
	std::string addr; //�ּ�
public:
	Person(int x, char y[], char z[])
		:ssn(x), name(y), addr(z)
	{}
	int GetSSN() {
		return ssn;
	}

	void ShowPerInfo() {
		std::cout 
			<< "�ֹε�Ϲ�ȣ : " << ssn << '\n'
			<< "�̸� : " << name << '\n'
			<< "�ּ� : " << addr << std::endl;
	}
};

