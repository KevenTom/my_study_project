#include "DBQueue.h"

DBQueue::DBQueue()
	:Deque()
{}

int DBQueue::QIsEmpty()
{
	return DQIsEmpty();
}

void DBQueue::Enqueue(Data data)
{
	DQAddLast(data);
}

Data DBQueue::Dequeue()
{
	return DQRemoveFirst();
}

Data DBQueue::QPeek()
{
	return DQGetFrist();
}