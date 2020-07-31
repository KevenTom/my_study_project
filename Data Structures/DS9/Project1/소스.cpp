#include<iostream>
#include"SimpleHeap.h"

using namespace std;

template<typename T>
int cheack(T d1, T d2) {
	if (d1 > d2)
		return 1;
	else if (d1 < d2)
		return -1;
	else
		return 0;
}

int main() {
	Heap<char> heap(cheack);


	heap.HInsert('A');
	heap.HInsert('B');
	heap.HInsert('C');

	heap.HInsert('A');
	heap.HInsert('B');
	heap.HInsert('C');

	while (!heap.HisEmoty())
		cout << heap.HDelete() << endl;

	return 0;
}