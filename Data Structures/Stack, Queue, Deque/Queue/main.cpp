#include<iostream>
#include"Queue.h"

using namespace std;

int main() {
	Queue<int> q;

	q.QPush(1);
	q.QPush(2);
	q.QPush(3);
	q.QPush(4);
	q.QPush(5);


	while (!q.QIsEmpty()) {
		cout << q.QPeek() << " ";
		q.QPop();
	}



	return 0;
}