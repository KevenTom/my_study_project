#include <iostream>
#include"DBLinkedList.h"

using namespace std;

int main()
{
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);

	cout << "데이터 수 : " << LCount(&list) << endl;
	if (LFirst(&list, &data))
	{
		cout << data <<" ";

		while(LNext(&list, &data))
			cout << data << " ";

		cout << '\n' << endl;
	}

	if (LFirst(&list, &data))
	{
		if (data % 2 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0)
				LRemove(&list);
		}

		cout << '\n' << endl;
	}

	cout << "데이터 수 : " << LCount(&list) << endl;
	if (LFirst(&list, &data))
	{
		cout << data << " ";

		while (LNext(&list, &data))
			cout << data << " ";

		cout << '\n' << endl;
	}

	return 0;
}