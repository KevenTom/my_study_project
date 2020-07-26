#pragma once
#include <vector>
#include <iostream>
#include "Teacher.h"
#include "Student.h"

class Lecture
{
private:
	std::string m_name;
	//11 Teacher teacher; //4 �� ���� ���� Lecture �ȿ� Teacher, Student�� ����� ���� �ִ�. �� Lectire ��ü�� �������ٸ� �� ��ü���� Teacher, Student�� ���� ��������. �װ� ���������� �߿��� Ư¡ �̴�.
	//std::vector<Student> students; //5 �л��� �������� ���� �� �����ϱ� ���ͷ� �������.

	Teacher* teacher; //12 �ּҷ� �޾ƿ��� �ǰڳ�!
	std::vector<Student*> students; //13 ���⼭ Lecture�� �������� students�� ����������, ��Ʃ��Ʈ �����Ͱ� ����Ű�� �ִ� ���� �ּҿ� �ִ°� �״�� ������ �˴ϴ�.
public:
	Lecture(const std::string name_in)
		:m_name(name_in)
	{}
	//14 void assignTeacher(const Teacher& const teacher_input)
	void assignTeacher(Teacher* const teacher_input)
	{
		teacher = teacher_input;
		
	}
	//14 void registerStudent(const Student& const student_input)
	void registerStudent(Student* const student_input)
	{
		students.push_back(student_input); //10 �� ������ push_back���� �־��ָ� �����ؼ� �־��ֱ� ����
	}
	void study()
	{
		std::cout << m_name << " study " << std::endl << std::endl;
		//14 for (auto& element : students)
		for (auto element : students)
		//14 element.setIntel(element.getIntel() + 1);
		(*element).setIntel((*element).getIntel() + 1);
	}
	friend std::ostream& operator << (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture nanme : " << lecture.m_name << std::endl;
		//14 out << lecture.teacher << std::endl;
		out << *lecture.teacher << std::endl;
		for (auto element : lecture.students)
			//14 out << element << std::endl;
			out << *element << std::endl;
		return out;
	}
};