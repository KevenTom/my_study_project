#pragma once

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _Node
{
	Data data;
	struct _Node* next;
} Node;

class LQueue
{
	Node* front;
	Node* rear;
public:
	LQueue();
	bool QIsEmpty();
	void Enqueue(Data data);
	Data Dequeue();
	Data QPeek();
};