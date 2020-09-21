#pragma once
#include<iostream>

class Person //테이블에 저장될 클래스
{
private:
	int ssn; //주민등록번호
	std::string name; //이름
	std::string addr; //주소
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

