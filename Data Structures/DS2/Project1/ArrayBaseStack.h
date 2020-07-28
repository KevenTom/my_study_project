#pragma once

#define TRUE 1
#define FALSE 0
#define ARRAY_MAX 30

typedef int Data;

//typedef struct _node
//{
//	Data data;
//	struct _node* next;
//	struct _node* prev;
//} Node;

//typedef struct _StackList
//{
//	Node* head;
//	Node* tail;
//	Node* cur;
//	int numofData;
//} StackList;

typedef struct _StackList
{
	Data arr[ARRAY_MAX];
	int topIndex;
} StackList;

typedef StackList Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);