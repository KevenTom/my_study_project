#pragma once
#include"BinaryTree.h"

#define TRUE 1
#define FALSE 0

typedef BTreeNode* Data;

typedef struct _Node
{
	Data data;
	struct _Node* next;
} Node;

class LStack
{
	Node* head;
public:
	LStack();
	bool SIsEmpty(LStack* pstack);

	LStack* SPush(Data data);
	Data SPop();
	Data SPeek();
};