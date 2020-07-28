#include "Deque.h"
#include<iostream>

Deque::Deque()
	:head(NULL), tail(NULL)
{}

bool Deque::DQIsEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void Deque::DQAddFirst(Data data)
{
	Node* newnode = new Node;
	newnode->data = data;

	if (DQIsEmpty())
		tail = newnode;
	else
		head->prev = newnode;

	newnode->next = head;
	newnode->prev = NULL;
	head = newnode;
}

void Deque::DQAddLast(Data data)
{
	Node* newnode = new Node;
	newnode->data = data;

	if (DQIsEmpty())
		head = newnode;
	else
		tail->next = newnode;

	newnode->prev = tail;
	newnode->next = NULL;
	tail = newnode;
}

Data Deque::DQRemoveFirst()
{
	Data rdata;
	Node* rnode;

	if (DQIsEmpty())
	{
		exit(-1);
	}
	else if (head == tail)
	{
		rdata = head->data;
		rnode = head;
		head = NULL;
		tail = NULL;
		delete rnode;
		return rdata;
	}

	rdata = head->data;
	rnode = head;
	head = head->next;
	delete rnode;
	return rdata;
}

Data Deque::DQRemoveLast()
{
	Data rdata;
	Node* rnode;

	if (DQIsEmpty())
	{
		exit(-1);
	}
	else if (head == tail)
	{
		rdata = tail->data;
		rnode = tail;
		head = NULL;
		tail = NULL;
		delete rnode;
		return rdata;
	}
	
	rdata = tail->data;
	rnode = tail;
	tail = tail->prev;
	delete rnode;
	return rdata;
}

Data Deque::DQGetFrist()
{
	if (DQIsEmpty())
		exit(-1);
	else
		return head->data;
}

Data Deque::DQGetLast()
{
	if (DQIsEmpty())
		exit(-1);
	else
		return tail->data;
}