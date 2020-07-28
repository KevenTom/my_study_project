#include"DBQueue.h"
#include<iostream>

using namespace std;

int main()
{
	DBQueue q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);

	while (!q.DQIsEmpty())
		cout << q.Dequeue() << " ";

	return 0;
}