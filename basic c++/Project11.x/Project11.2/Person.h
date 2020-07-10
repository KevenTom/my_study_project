#pragma once
#include <iostream> //5 �����Ҷ��� .cpp ���Ϸ� �ϳ��� �����ϴ°� ���ϱ�� �ѵ� ������ ���̽Ƕ� Ŭ������ �׳� ������ ������� ���� ���ٰ� ������ ���̴°� ����.
#include <string>

//2 Ŭ���� �����忡 ���� �������ִµ� ������ �ʿ� ��� ������
class Person
{
private:
	std::string m_name;
public:
	Person(const std::string& name_in)
		:m_name(name_in)
	{}
	void setName(const std::string& name_in)//7 ������ setName, getName�� �ۺ��̶� ����Ҽ� �ִ�.
	{
		m_name = name_in;
	}
	//11 2std::string getName()//11 2���۷����Ͱ� const�� �������� ������ const�� �ٲ�� �Ѵ�.
	std::string getName() const
	{
		return m_name;
	}//12 ��ü������ �ϴ� �ֿ� ������ �ߺ��Ǵ� ����� ������ �� ����� �����ϰų� ���������ϰų� �߰��� ���ٶ� �̷��� �ѹ��� �������ָ� �ڵ����� Ƽ�ĳ� ��Ʃ��Ʈ������ ����Ҽ� �ְ� ����
	void doNothing() const//13 2��������ó�� ����� �߰��� ���Ҵ�.
	{
		std::cout << m_name << "is doing nothing" << std::endl;
	}
};