#pragma once
//4 #include <string> //4 �ߺ��Ǹ� ����°� ����ϴϱ� ����.
#include "Person.h"

class Teacher : public Person
{
private:
	//3 std::string m_name; 
public:
	Teacher(const std::string& name_in = "No name")
		//5 3:m_name(name_in)
		:Person(name_in)
	{}
	//6 3void setName(const std::string& name_in)  //6 3��Ʃ��Ʈ, Ƽ��, �³���, �ٳ��� �̷��� ���� �ߺ��Ǿ� ������. ->�׷� �ʳ� ���� �ǵ��� ���� �׸��� �޽��� �ű���
	//{
	//	m_name = name_in;
	//}
	//std::string getName()
	//{
	//	return m_name;
	//}
	friend std::ostream& operator<<(std::ostream& out, const Teacher& teacher)
	{
		//10 3out << teacher.m_name;//10 3�޽����� m_name�� �����̺��̱� ������ ���� �ִ�. ������Ƽ��� �ٲٴ� ����� ������
 		out << teacher.getName();
		return out;
	}
};