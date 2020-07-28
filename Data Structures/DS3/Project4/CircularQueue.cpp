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
		cout << "�����͸� �ʰ��Ͽ����ϴ�aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
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
		std::cout << "���� �޸𸮰� �����ϴ�aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
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
		std::cout << "���� �޸𸮰� �����ϴ�aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
		exit(-1);
	}
	else
		return arr[NextPosIdx(front)];
}