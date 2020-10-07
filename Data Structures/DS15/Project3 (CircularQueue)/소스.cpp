#include<iostream>
#include"CircularQueue.h"

using namespace std;

int main() {
	CircularQueue<int> q;

	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);

	while (!q.QIsEmpty())
		cout << q.Dequeue() << " ";



	return 0;
}