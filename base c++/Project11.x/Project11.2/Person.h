#pragma once
#include <iostream> //5 강의할때는 .cpp 파일로 하나로 설명하는게 편하기는 한데 습관을 들이실때 클래스는 그냥 별도의 헤더파일 만들어서 뺀다고 습관을 들이는게 좋다.
#include <string>

//2 클래스 위저드에 대해 가르쳐주는데 지금은 필요 없어서 안적음
class Person
{
private:
	std::string m_name;
public:
	Person(const std::string& name_in)
		:m_name(name_in)
	{}
	void setName(const std::string& name_in)//7 가져온 setName, getName은 퍼블릭이라서 사용할수 있다.
	{
		m_name = name_in;
	}
	//11 2std::string getName()//11 2오퍼레이터가 const로 가져오기 때문에 const로 바꿔야 한다.
	std::string getName() const
	{
		return m_name;
	}//12 객체지향을 하는 주요 이유가 중복되는 기능이 있을때 그 기능을 수정하거나 유지보수하거나 추가를 해줄때 이렇게 한번만 수정해주면 자동으로 티쳐나 스튜던트에서도 사용할수 있게 되죠
	void doNothing() const//13 2유지보수처럼 기능을 추가해 보았다.
	{
		std::cout << m_name << "is doing nothing" << std::endl;
	}
};