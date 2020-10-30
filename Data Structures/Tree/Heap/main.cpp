#include<iostream>
#include"Heap.h"

using namespace std;

bool PrComp(char c1, char c2) {
	if (c1 < c2)
		return true;
	else
		return false;
}

int main() {
	Heap<char> heap(PrComp);

	heap.HInsert('A');
	heap.HInsert('B');
	heap.HInsert('C');
	
	cout << heap.HDelete() << endl;
	
	heap.HInsert('A');
	heap.HInsert('B');
	heap.HInsert('C');

	cout << heap.HDelete() << endl;

	while (!heap.HIsEmpty())
		cout << heap.HDelete() << endl;

	return 0;
}