#pragma once

#define TRUE 1
#define FALSE 0
#define ARRAY_MAX 100

typedef int Data;

class LQueue
{
	Data arr[ARRAY_MAX];
	int topIndex;
public:
	LQueue();
	bool QIsEmpty();
	void Enqueue(Data data);
	Data Dequeue();
	Data QPeek();
};