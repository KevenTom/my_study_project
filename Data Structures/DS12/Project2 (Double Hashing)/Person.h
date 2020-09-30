#pragma once
#include<iostream>

class Person
{
private:
	int ssn;
	std::string name;
	std::string addr;
public:
	Person(int x, char y[], char z[])
		:ssn(x), name(y), addr(z)
	{}

	int GetSSN() {
		return ssn;
	}

	void ShowPerInfo() {
		std::cout 
			<< "주민등록번호 : " << ssn << '\n'
			<< "이름 : " << name << '\n'
			<< "주소 : " << addr << std::endl;
	}
};

