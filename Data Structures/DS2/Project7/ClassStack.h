#pragma once

#define TRUE 1
#define FALSE 0

typedef int Data;

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
	bool SIsEmpty();

	LStack* SPush(Data data);
	Data SPop();
	Data SPeek();
};