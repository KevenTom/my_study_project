#include"Deque.h"
#include<iostream>

using namespace std;

int main()
{
	Deque deq;

	deq.DQAddLast(1);
	deq.DQAddLast(2);
	deq.DQAddLast(3);
	deq.DQAddLast(4);
	deq.DQAddLast(5);

	while (!deq.DQIsEmpty())
		cout << deq.DQRemoveFirst() << " ";

	return 0;
}