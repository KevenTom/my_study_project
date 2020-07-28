#pragma once

typedef struct __staffinfo
{
	char staffname[30];
	int staffnumber;
} staffinfo;


staffinfo* newstaffinfo(const char* name, int number);
void staffcout(staffinfo* data);