#pragma once

#define TRUE 1
#define FALSE 0
#define ARRAY_MAX 50

typedef int Data;

class LQueue
{
	Data arr[ARRAY_MAX];
	int front;
	int rear;
public:
	LQueue();
	bool QIsEmpty();
	void Enqueue(Data data);
	Data Dequeue();
	Data QPeek();
};