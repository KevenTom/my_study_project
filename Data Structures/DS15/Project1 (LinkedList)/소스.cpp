#include<iostream>
#include"LinkedList.h"

using namespace std;

template<typename T>
bool WhoIsPrecede(T data1, T data2) {
	if (data1 < data2)
		return false;
	else
		return true;
}

int main() {
	LinkedList<int> list(WhoIsPrecede);
	int data;

	list.LInsert(11);
	list.LInsert(11);
	list.LInsert(22);
	list.LInsert(22);
	list.LInsert(33);

	cout << "현재 데이터의 수 : " << list.LCount() << endl;

	if (list.LFirest(&data)) {
		cout << data <<" ";

		while (list.LNext(&data))
			cout << data <<" ";
		cout << endl;
	}

	if (list.LFirest(&data)) {
		if (data == 22)
			list.LRemove();

		while (list.LNext(&data)) {
			if (data == 22)
				list.LRemove();
		}
	}

	cout << "현재 데이터의 수 : " << list.LCount() << endl;

	if (list.LFirest(&data)) {
		cout << data << " ";

		while (list.LNext(&data))
			cout << data << " ";
		cout << endl;
	}



	return 0;
}