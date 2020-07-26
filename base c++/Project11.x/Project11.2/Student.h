#pragma once
//4 #include <iostream>
//#include <string>
#include "Person.h"

class Student : public Person
{
private:
	//3 std::string m_name; //1 ���ݺ��� �л��� ������ �������� �κ��� �ְ� �� �������� �κ��� ��� �Ϲ�ȭ�Ҽ� �ִ� ��ü�� ������� �Ѵ�.
	int m_intel;
public:
	Student(const std::string& name_in = "No name", const int& intel_in = 0)
		//5 3:m_name(name_in), m_intel(intel_in)//5 3�� �翬�� ����Ŭ���� ��������� �����Ҽ� ������
		: Person(name_in), m_intel(intel_in)
	{}
	//6 3void setName(const std::string& name_in)
	//{
	//	m_name = name_in;
	//}
	void setIntel(const int& intel_in)//8 ������ ��Ʃ��Ʈ���ϱ� �������� ����!
									  //(����� �и��ϰ� ������ �и��Ҷ� �ߺ��Ǵ°��� ������ �θ�Ŭ������ �ְ� �ߺ����� �ʴ� Ư���� ��Ҹ� �ڽ�Ŭ������ �߰��� �����°��� ����� ����ϴ� ���� ȿ������ ����̴�.)
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