#pragma once

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _CLL
{
	Node* tail;
	Node* cur;
	Node* before;
	int numofData;
} CList;

typedef CList List;

void ListInit(List* plist);
void LInsertFront(List* plist, Data data);
void LInsert(List* plist, Data data);

int LFirst(List* plist, Data* data);
int LNext(List* plist, Data* data);
Data LRemove(List* plist);
int LCount(List* plist);