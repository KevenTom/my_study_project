#include<iostream>
#include"DBLinkedList.h"

void ListInit(List* plist)
{
	plist->head = new Node;
	plist->tail = new Node;

	plist->head->next = plist->tail;
	plist->head->prev = NULL;

	plist->tail->prev = plist->head;
	plist->tail->next = NULL;

	plist->numofData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	plist->tail->prev->next = newNode;
	newNode->prev = plist->tail->prev;
	plist->tail->prev = newNode;
	newNode->next = plist->tail;

	++plist->numofData;
}

int LFirst(List* plist, Data* data)
{
	if (plist->head->next == plist->tail)
	{
		return FALSE;
	}
	else
	{
		plist->cur = plist->head->next;
		*data = plist->cur->data;
		return TRUE;
	}
}

int LNext(List* plist, Data* data)
{
	if (plist->cur->next == plist->tail)
	{
		return FALSE;
	}
	else
	{
		plist->cur = plist->cur->next;
		*data = plist->cur->data;
		return TRUE;
	}
}

//int LPrevious(List* plist, Data* data)
//{
//	if (plist->cur->prev == plist->head)
//	{
//		return FALSE;
//	}
//	else
//	{
//		plist->cur = plist->cur->prev;
//		*data = plist->cur->data;
//		return TRUE;
//	}
//}

Data LRemove(List* plist)
{
	//Node* remove = new Node;
	Node* remove = plist->cur;
	Data rdata = plist->cur->data;

	//remove = plist->cur;
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	plist->cur = plist->cur->prev;
	delete remove;

	--plist->numofData;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numofData;
}