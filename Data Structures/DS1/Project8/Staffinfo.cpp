#include<iostream>
#include<cstring>
#include"Staffinfo.h"

using namespace std;

staffinfo* newstaffinfo(const char* name, int number)
{
	staffinfo* staff = new staffinfo;
	strcpy_s(staff->staffname, name);
	staff->staffnumber = number;
	return staff;
}

void staffcout(staffinfo* data)
{
	cout << data->staffname << " " << data->staffnumber << "  ";
}