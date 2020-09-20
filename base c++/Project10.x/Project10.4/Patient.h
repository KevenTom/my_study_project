#pragma once
#include<iostream>
#include<vector>
#include"Doctor.h"

class Doctor;
class Patient
{
private:
	std::string m_name;
	std::vector<Doctor*> m_doctors;
public:
	friend class Doctor;
	Patient(std::string name_in)
		:m_name(name_in)
	{}
	void addDoctor(Doctor* new_doctor) {
		m_doctors.push_back(new_doctor);
	}
	void meetDoctors();
};

