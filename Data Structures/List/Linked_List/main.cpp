#include<iostream>
#include"LinKedList.h"

using namespace std;

bool sort(int d1, int d2) {
	if (d1 < d2)
		return true;
	else
		return false;
}


int main() {
	LinKedList<int> list;

	list.SetsortFunc(sort);

	list.InsertData(1);
	list.InsertData(2);
	list.InsertData(3);
	list.InsertData(4);
	list.InsertData(5);

	int data;

	if (list.FirstNode(&data)) {
		cout << data << " ";

		while (list.NextNode(&data))
			cout << data << " ";

		cout << endl;
	}

	if (list.FirstNode(&data)) {
		if (data == 3)
			list.RemoveNode();

		while (list.NextNode(&data))
			if (data == 3)
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