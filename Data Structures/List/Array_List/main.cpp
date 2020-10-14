#include<iostream>
#include"ArrayList.h"

using namespace std;

int main() {
	ArrayList<int> list;
	int data;
	
	list.LInsert(11);
	list.LInsert(11);
	list.LInsert(22);
	list.LInsert(22);
	list.LInsert(33);

	cout << "�� ������ : " << list.ListSize() << endl;
	if (list.LFirst(&data)) {
		cout << data << " ";

		while (list.LNext(&data))
			cout << data << " ";

		cout << endl;
	}


	if (list.LFirst(&data)) {
		if (data == 22)
			list.LRemove();

		while (list.LNext(&data))
			if (data == 22)
				list.LRemove();
	}


	cout << "���� �� ������ : " << list.ListSize() << endl;
	if (list.LFirst(&data)) {
		cout << data << " ";

		while (list.LNext(&data))
			cout << data << " ";

		cout << endl;
	}

	return 0;
}