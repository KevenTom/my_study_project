#pragma once
//4 #include <iostream>
//#include <string>
#include "Person.h"

class Student : public Person
{
private:
	//3 std::string m_name; //1 지금보면 학생과 선생의 공통적인 부분이 있고 그 공통적인 부분을 묶어서 일반화할수 있는 객체를 만드려고 한다.
	int m_intel;
public:
	Student(const std::string& name_in = "No name", const int& intel_in = 0)
		//5 3:m_name(name_in), m_intel(intel_in)//5 3자 당연히 마더클래스 멤버변수에 접속할수 없어짐
		: Person(name_in), m_intel(intel_in)
	{}
	//6 3void setName(const std::string& name_in)
	//{
	//	m_name = name_in;
	//}
	void setIntel(const int& intel_in)//8 인텔은 스튜던트꺼니까 가져갈수 없어!
									  //(기능을 분리하고 역할을 분리할때 중복되는것을 가급적 부모클래스에 넣고 중복되지 않는 특별한 요소만 자식클래스에 추가로 구현는것이 상속을 사용하는 가장 효율적인 방법이다.)
	{
		m_intel = intel_in;
	}
	int getIntel()
	{
		return m_intel;
	}
	friend std::ostream& operator<<(std::ostream& out, const Student& studnet)
	{
		//10 3out << studnet.m_name << " " << studnet.m_intel;
		out << studnet.getName() << " " << studnet.m_intel;
		return out;
	}
};