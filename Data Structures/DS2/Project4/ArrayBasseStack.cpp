#include<iostream>
#include"ArrayBaseStack.h"

using namespace std;

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	Node* newnode = new Node;
	newnode->data = data;
	newnode->next = pstack->head;
	pstack->head = newnode;
}

Data SPop(Stack* pstack)
{
	Node* rnode;
	Data Rdata;

	if (SIsEmpty(pstack))
	{
		cout << "데이터 없음" << endl;
		return -1;
	}
	else
	{
		Rdata = pstack->head->data;
		rnode = pstack->head;
		pstack->head = pstack->head->next;
		delete rnode;
		return Rdata;
	}
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		cout << "데이터 없음" << endl;
		return -1;
	}
	else
	{
		return pstack->head->data;
	}
}