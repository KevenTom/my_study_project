#pragma once
#include <vector>
#include <iostream>
#include "Teacher.h"
#include "Student.h"

class Lecture
{
private:
	std::string m_name;
	//11 Teacher teacher; //4 자 지금 보면 Lecture 안에 Teacher, Student를 멤버로 갖고 있다. 즉 Lectire 객체가 없어진다면 그 객체안의 Teacher, Student도 같이 없어진다. 그게 구성관계의 중요한 특징 이다.
	//std::vector<Student> students; //5 학생은 여러명이 있을 수 있으니까 백터로 만들었다.

	Teacher* teacher; //12 주소로 받아오면 되겠네!
	std::vector<Student*> students; //13 여기서 Lecture가 없어지면 students도 없어지지만, 스튜던트 포인터가 가리키고 있는 원래 주소에 있는건 그대로 유지가 됩니다.
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
		students.push_back(student_input); //10 그 이유는 push_back으로 넣어주면 복사해서 넣어주기 때문
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