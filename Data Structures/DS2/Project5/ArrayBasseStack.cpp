#include<iostream>
#include"ArrayBaseStack.h"
#include"CLinkedList.h"

using namespace std;

void StackInit(Stack* pstack)
{
	pstack->tail = NULL;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->tail == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	LInsertFront(pstack, data);
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

	Rdata = pstack->tail->next->data;
	rnode = pstack->tail->next;

	if (rnode == pstack->tail)
		pstack->tail = NULL;
	else
		pstack->tail->next = rnode->next;

	delete rnode;
	return Rdata;
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
		return pstack->tail->next->data;
	}
}