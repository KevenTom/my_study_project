#pragma once
#include<iostream>
#include<vector>
#include"Patient.h"

class Patient;
class Doctor
{
private:
	std::string m_name;
	std::vector<Patient*> m_patients;
public:
	friend class Patient;
	Doctor(std::string name_in)
		:m_name(name_in)
	{}
	void addPatient(Patient* new_patient) {
		m_patients.push_back(new_patient);
	}
	void meetPatients();
};

