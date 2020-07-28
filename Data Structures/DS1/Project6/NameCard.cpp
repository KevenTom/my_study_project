#include<iostream>
#include<cstring>
#include"NameCard.h"

using namespace std;

NameCard* MakeNameCard(const char* name, const char* phone)
{
	NameCard* card = new NameCard;
	strcpy_s(card->name, name);
	strcpy_s(card->phone, phone);
	return card;
}

void ShowNameCardInfo(NameCard* pcard)
{
	cout << pcard->name << " " << pcard->phone << endl;
}

int NameCompare(NameCard* pcard, const char* name)
{
	if (strcmp(pcard->name, name) == 0)
		return 0;
	else
		return 1;
}

void ChangePhoneNum(NameCard* pcard, const char* phone)
{
	strcpy_s(pcard->phone, phone);
}