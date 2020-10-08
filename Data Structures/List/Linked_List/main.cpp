/*
연결리스트 ADT

bool DLinKedList<T>::isEmpty()
- 

*/
#include<iostream>
#include"DLinKedList.h"

using namespace std;

bool sort(int d1, int d2) {
	if (d1 < d2)
		return false;
	else
		return true;
}


int main() {
		DLinKedList<int> test;

		test.SetsortFunc(sort);

		test.InsertData(1);
		test.InsertData(2);
		test.InsertData(3);
		test.InsertData(4);
		test.InsertData(5);

		Node<int>* del;

		if (test.FirstNode()->data == 3)
			test.RemoveNode();
		for (int i = 0; i < test.ListSize() - 1; ++i) {
			del = test.NextNode();

			if (del->data == 3)
				test.RemoveNode();
		}


		cout << test.FirstNode()->data << " ";
		for (int i = 0; i < test.ListSize() - 1; ++i)
			cout << test.NextNode()->data << " ";



	return 0;
}