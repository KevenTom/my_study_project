#pragma once
//4 #include <string> //4 중복되면 지우는게 깔끔하니까 좋다.
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
	//6 3void setName(const std::string& name_in)  //6 3스튜던트, 티쳐, 셋네임, 겟네임 이렇게 많이 중복되어 버린다. ->그래 너넨 차라리 건들지 마렴 그리고 펄슨에 옮기자
	//{
	//	m_name = name_in;
	//}
	//std::string getName()
	//{
	//	return m_name;
	//}
	friend std::ostream& operator<<(std::ostream& out, const Teacher& teacher)
	{
		//10 3out << teacher.m_name;//10 3펄슨에서 m_name이 프라이빗이기 떄문에 막혀 있다. 프로택티드로 바꾸는 방법도 있지만
 		out << teacher.getName();
		return out;
	}
};