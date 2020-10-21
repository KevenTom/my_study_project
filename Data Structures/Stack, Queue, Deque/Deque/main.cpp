#include<iostream>
#include"Deque.h"

using namespace std;

int main() {
	Deque<int> deq;

	deq.DQFirstPush(3);
	deq.DQFirstPush(2);
	deq.DQFirstPush(1);

	deq.DQLastPush(4);
	deq.DQLastPush(5);
	deq.DQLastPush(6);

	while (!deq.DQIsEmpty()) {
		cout << deq.DQFirstPeek() << " ";
		deq.DQFirstPop();
	}
	cout << endl;

	deq.DQFirstPush(3);
	deq.DQFirstPush(2);
	deq.DQFirstPush(1);

	deq.DQLastPush(4);
	deq.DQLastPush(5);
	deq.DQLastPush(6);

	while (!deq.DQIsEmpty()) {
		cout << deq.DQLastPeek() << " ";
		deq.DQLastPop();
	}
	cout << endl;

	return 0;
}