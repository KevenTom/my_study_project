#include<iostream>
#include"ClassStack.h"

using namespace std;

LStack::LStack()
	:head(NULL)
{}

bool LStack::SIsEmpty(LStack* pstack)
{
	if (pstack->head == NULL)
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

	Rdata = this->head->data;
	rnode = this->head;
	this->head = this->head->next;
	delete rnode;
	return Rdata;
}

Data LStack::SPeek()
{
	return this->head->data;
}