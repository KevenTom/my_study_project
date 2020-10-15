#include<iostream>
#include"CLinkedList.h"

using namespace std;

bool sort(int d1, int d2) {
	if (d1 < d2)
		return true;
	else
		return false;
}

int main() {
	CLinKedList<int> list;
	int data;

	list.InsertTail(3);
	list.InsertTail(4);
	list.InsertTail(5);
	list.InsertData(2);
	list.InsertData(1);

	if (list.FirstNode(&data)) {
		cout << data << " ";

		for (int i = 0; i < list.ListSize() * 3 - 1; ++i)
			if (list.NextNode(&data))
				cout << data << " ";
		cout << endl;
	}

	if (list.FirstNode(&data)) {
		if (data % 2 == 0)
			list.RemoveNode();

		for (int i = 0; i < list.ListSize() - 1; ++i)
			if (list.NextNode(&data) && data % 2 == 0)
				list.RemoveNode();
		cout << endl;
	}

	if (list.FirstNode(&data)) {
		cout << data << " ";

		for (int i = 0; i < list.ListSize() - 1; ++i)
			if (list.NextNode(&data))
				cout << data << " ";
		cout << endl;
	}

	return 0;
}