#include<iostream>
#include"ClassStack.h"

using namespace std;

LQueue::LQueue()
	:front(NULL), rear(NULL)
{}

bool LQueue::QIsEmpty()
{
	if (front == NULL)
		return TRUE;
	else
		return FALSE;
}

void LQueue::Enqueue(Data data)
{
	Node* newnode = new Node;
	newnode->next = NULL;
	newnode->data = data;

	if (QIsEmpty())
	{
		front = newnode;
		rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}

Data LQueue::Dequeue()
{
	if (QIsEmpty())
	{
		std::cout << "힙에 메모리가 없습니다" << std::endl;
		exit(-1);
	}

	Node* delNode;
	Data refdata;

	delNode = front;
	refdata = delNode->data;
	front = front->next;

	delete delNode;
	return refdata;
}

Data LQueue::QPeek()
{
	if (QIsEmpty())
	{
		std::cout << "힙에 메모리가 없습니다" << std::endl;
		exit(-1);
	}
	else
		return front->data;
}