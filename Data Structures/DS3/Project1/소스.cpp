#include<iostream>
#include"CircularQueue.h"

using namespace std;

int main()
{
	LQueue list;

	list.QIsEmpty();
	list.Dequeue();
	list.QPeek();

	list.Enqueue(123);

	cout << list.QPeek() << endl;

	list.Enqueue(124);

	cout << list.QPeek() << endl;
	cout << endl;

	cout << list.Dequeue() << endl;
	cout << list.QPeek() << endl;
	cout << endl;

	list.Enqueue(234);
	cout << list.Dequeue() << endl;
	cout << list.QPeek() << endl;

	return 0;
}