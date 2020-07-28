#pragma once
#include "Deque.h"
class DBQueue :
	public Deque
{
public:
	DBQueue();
	int QIsEmpty();

	void Enqueue(Data data);
	Data Dequeue();

	Data QPeek();
};

