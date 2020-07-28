#include<iostream>
#include"CLinkedList.h"

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numofData = 0;
}

void LInsertFront(List* plist, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (plist->tail == NULL)
		plist->tail = newNode;
	else
		newNode->next = plist->tail->next;

	plist->tail->next = newNode;
	++plist->numofData;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (plist->tail == NULL)
		plist->tail = newNode;
	else
		newNode->next = plist->tail->next;

	plist->tail->next = newNode;
	plist->tail = plist->tail->next;
	++plist->numofData;
}

int LFirst(List* plist, Data* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*data = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist)
{
	Data rdata = plist->cur->data;

	if (plist->cur == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	delete plist->cur;
	plist->cur = plist->before;

	--plist->numofData;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numofData;
}