#pragma once
#include <string>

class Student
{
private:
	std::string m_name;
	int m_intel;
public:
	Student(const std::string & name_in = "No name", const int & intel_in = 0)
		:m_name(name_in), m_intel(intel_in)
	{}
	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}
	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}
	int getIntel()
	{
		return m_intel;
	}
	friend std::ostream& operator << (std::ostream& out, const Student student)
	{
		out << student.m_name << " " << student.m_intel;
		return out;
	}
}; //2 보면 티쳐도 이름이 있고 스튜던트도 이름이 있고 셋네임, 오퍼레이터 등 중복된 기능을 하는게 많으니까 사용하지만 나중에 상속이나 템플릿을 배우고 나면 그때는 중복된 부분을 한번만 코딩하고 중복되지 않는 코딩을
	//합치는 방식으로 할수 있기 때문에 지금은 코딩의 내부를 공부하다는 느낌으로 공부하는겁니다