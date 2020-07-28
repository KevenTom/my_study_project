#include<iostream>
#include"DBLinkedList.h"

void ListInit(List* plist)
{
	plist->head = NULL;
	plist->numofData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (plist->head == NULL)
	{
		plist->head = newNode;
		plist->head->next = NULL;
		plist->head->prev = NULL;
	}
	else
	{
		newNode->next = plist->head;
		plist->head->prev = newNode;
		newNode->prev = NULL;
		plist->head = newNode;

	}
	++plist->numofData;
}

int LFirst(List* plist, Data* data)
{
	if (plist->head == NULL)
	{
		return FALSE;
	}
	else
	{
		plist->cur = plist->head;
		*data = plist->cur->data;
		return TRUE;
	}
}

int LNext(List* plist, Data* data)
{
	if (plist->cur->next == NULL)
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

int LPrevious(List* plist, Data* data)
{
	if (plist->cur->prev == NULL)
	{
		return FALSE;
	}
	else
	{
		plist->cur = plist->cur->prev;
		*data = plist->cur->data;
		return TRUE;
	}
}

//Data LRemove(List* plist)
//{
//	Data rdata = plist->cur->data;
//
//	if (plist->cur == plist->head)
//	{
//		if (plist->head == plist->head->next)
//			plist->head = NULL;
//		else
//			plist->head = plist->before;
//	}
//
//	plist->before->next = plist->cur->next;
//	delete plist->cur;
//	plist->cur = plist->before;
//
//	--plist->numofData;
//	return rdata;
//}

int LCount(List* plist)
{
	return plist->numofData;
}