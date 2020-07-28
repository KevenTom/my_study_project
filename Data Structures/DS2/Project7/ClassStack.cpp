#include<iostream>
#include"ClassStack.h"

using namespace std;

LStack::LStack()
	:head(NULL)
{}

bool LStack::SIsEmpty()
{
	if (this->head == NULL)
		return TRUE;
	else
		return FALSE;
}

LStack* LStack::SPush(Data data)
{
	Node* newnode = new Node;
	newnode->data = data;
	newnode->next = this->head;
	this->head = newnode;
	return this;
}

Data LStack::SPop()
{
	Node* rnode;
	Data Rdata;

	if (SIsEmpty())
	{
		cout << "데이터 없음" << endl;
		return -1;
	}
	else
	{
		Rdata = this->head->data;
		rnode = this->head;
		this->head = this->head->next;
		delete rnode;
		return Rdata;
	}
}

Data LStack::SPeek()
{
	if (SIsEmpty())
	{
		cout << "데이터 없음" << endl;
		return -1;
	}
	else
	{
		return this->head->data;
	}
}