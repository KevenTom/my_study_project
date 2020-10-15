#include<iostream>
#include"DBLinkedList.h"

using namespace std;

bool sort(int d1, int d2) {
	if (d1 < d2)
		return true;
	else
		return false;
}

int main() {
	DBLinKedList<int> list;
	int data;
	list.SetsortFunc(sort);

	list.InsertData(5);
	list.InsertData(1);
	list.InsertData(2);
	list.InsertData(3);
	list.InsertData(4);
	list.InsertData(5);
	list.InsertData(6);
	list.InsertData(7);
	list.InsertData(8);

	if (list.FirstNode(&data)) {
		cout << data << " ";

		while (list.NextNode(&data))
			cout << data << " ";
		cout << endl;
	}

	if (list.FirstNode(&data)) {
		if (data % 2 == 0)
			list.RemoveNode();

		while (list.NextNode(&data))
			if (data % 2 == 0)
				list.RemoveNode();
	}

	if (list.FirstNode(&data)) {
		cout << data << " ";

		while (list.NextNode(&data))
			cout << data << " ";
		cout << endl;
	}

	return 0;
}