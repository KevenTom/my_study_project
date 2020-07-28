#pragma once

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _Node
{
	Data data;
	struct _Node* next;
} Node;

typedef struct _StackList
{
	Node* head;
} StackList;

typedef StackList Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);