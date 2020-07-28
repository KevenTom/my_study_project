#include<iostream>
#include"CircularQueue.h"

using namespace std;

int NextPosIdx(int pos)
{
	if (pos == ARRAY_MAX - 1)
		return 0;
	else
		return pos + 1;
}


LQueue::LQueue()
	:front(0), rear(0)
{}

bool LQueue::QIsEmpty()
{
	if (front == rear)
		return TRUE;
	else
		return FALSE;
}

void LQueue::Enqueue(Data data)
{
	if (NextPosIdx(rear) == front)
	{
		cout << "데이터를 초과하였습니다aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
		exit(-1);
	}
	else
	{
		rear = NextPosIdx(rear);
		arr[rear] = data;
	}
}

Data LQueue::Dequeue()
{
	if (QIsEmpty())
	{
		std::cout << "힙에 메모리가 없습니다aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
		exit(-1);
	}
	else
	{
		front = NextPosIdx(front);
		return arr[front];
	}
}

Data LQueue::QPeek()
{
	if (QIsEmpty())
	{
		std::cout << "힙에 메모리가 없습니다aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
		exit(-1);
	}
	else
		return arr[NextPosIdx(front)];
}