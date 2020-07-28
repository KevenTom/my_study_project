#include"DLinkedList.h"
#include <iostream>

void ListInit(List* plist)
{
	plist->head = new Node;
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numofData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	++plist->numofData;
}

void SInsert(List* plist, LData data)
{
	Node* newNode = new Node;
	Node* pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;

	++plist->numofData;
}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List* plist, LData* data)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*data = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* data)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	delete rpos;
	--plist->numofData;
	return rdata;
}

//LData LRemove(List* plist)
//{
//	LData rdata = plist->cur->data;
//
//	plist->before->next = plist->cur->next;
//	delete plist->cur;
//	plist->cur = plist->before;
//
//	--plist->numofData;
//	return rdata;
//}

void SetSortRube(List* plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

int LCount(List* plist)
{
	return plist->numofData;
}