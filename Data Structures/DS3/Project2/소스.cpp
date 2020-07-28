#include<iostream>
#include"CircularQueue.h"

using namespace std;

int main()
{
	LQueue list;

	list.Dequeue();

	list.Enqueue(1);
	list.Enqueue(2);
	list.Enqueue(3);
	list.Enqueue(4);
	list.Enqueue(5);

	while (!list.QIsEmpty())
	{
		cout << list.Dequeue() << " ";
	}

	return 0;
}