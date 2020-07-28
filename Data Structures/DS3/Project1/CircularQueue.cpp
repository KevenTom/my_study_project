#include<iostream>
#include"CircularQueue.h"

LQueue::LQueue()
	:topIndex(-1)
{}

bool LQueue::QIsEmpty()
{
	if (topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void LQueue::Enqueue(Data data)
{
	arr[++topIndex] = data;
}

Data LQueue::Dequeue()
{
	if (QIsEmpty())
	{
		std::cout << "힙에 메모리가 없습니다" << std::endl;
		return -1;
	}
	else
	{
		Data data = arr[0];
		for (int i = 0; i < topIndex; ++i)
			arr[i] = arr[i + 1];
		--topIndex;
		return data;
	}
}

Data LQueue::QPeek()
{
	if (QIsEmpty())
	{
		std::cout << "힙에 메모리가 없습니다" << std::endl;
		return -1;
	}
	else
		return arr[0];
}