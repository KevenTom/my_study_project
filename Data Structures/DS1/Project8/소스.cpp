#include<iostream>
#include"CLinkedList.h"

using namespace std;

staffinfo* staffoncall(List* plist, const char* name, int number)
{
	Data newstaff;
	if (LFirst(plist, &newstaff))
	{
		if (strcmp(newstaff->staffname, name) == 0)
		{
			for (int i = 0; i < number; ++i)
				LNext(plist, &newstaff);

			return newstaff;
		}

		for (int i = 0; i < LCount(plist) - 1; ++i)
		{
			if (LNext(plist, &newstaff))
			{
				if (strcmp(newstaff->staffname, name) == 0)
				{
					for (int i = 0; i < number; ++i)
						LNext(plist, &newstaff);

					return newstaff;
				}
			}
		}

		cout << "�ش� �̸��� ���� ����� �����ϴ�." << endl;
		return 0;
	}
}

int main()
{
	List list;
	ListInit(&list);
	Data newstaff;
	int nodeNum = 0;


	newstaff = newstaffinfo("ccc", 111);
	LInsert(&list, newstaff);

	newstaff = newstaffinfo("aaa", 222);
	LInsert(&list, newstaff);

	newstaff = newstaffinfo("ddd", 333);
	LInsertFront(&list, newstaff);

	newstaff = newstaffinfo("bbb", 444);
	LInsert(&list, newstaff);

	newstaff = newstaffinfo("ccc", 111);
	LInsert(&list, newstaff);


	cout << "���� ������ �� : " << LCount(&list) << endl;
	if (LFirst(&list, &newstaff))
	{
		staffcout(newstaff);

		for (int i = 0; i < LCount(&list)- 1; ++i)
		{
			if (LNext(&list, &newstaff))
				staffcout(newstaff);
		}
		cout << '\n' << endl;
	}


	//if (LCount(&list) != 0)
	//{
	//	nodeNum = (LCount(&list));
	//	(LFirst(&list, &newstaff));
	//	if (newstaff->staffnumber == 111)
	//		LRemove(&list);

	//	for (int i = 0; i < nodeNum - 1; ++i)
	//	{
	//		LNext(&list, &newstaff);
	//		if (newstaff->staffnumber == 111)
	//			LRemove(&list);
	//	}

	//}

	staffcout(staffoncall(&list, "aaa", 4));
	cout << endl;

	cout << "���� ������ �� : " << LCount(&list) << endl;
	if (LFirst(&list, &newstaff))
	{
		staffcout(newstaff);

		for (int i = 0; i < LCount(&list) - 1; ++i)
		{
			if (LNext(&list, &newstaff))
				staffcout(newstaff);
		}
		cout << '\n' << endl;
	}









	//List list;
	//int data;
	//ListInit(&list);

	//LInsert(&list, 3);
	//LInsert(&list, 4);
	//LInsert(&list, 5);
	//LInsertFront(&list, 2);
	//LInsertFront(&list, 1);

	//if (LFirst(&list, &data))
	//{
	//	cout << data << " ";

	//	for (int i = 0; i < LCount(&list) * 3 - 1; ++i)
	//	{
	//		if (LNext(&list, &data))
	//			cout << data << " ";
	//	}
	//	cout << '\n' << endl;
	//}

	//if (LCount(&list) != 0)
	//{
	//	(LFirst(&list, &data));
	//	if (data % 2 == 0)
	//		LRemove(&list);

	//	for (int i = 0; i < LCount(&list) - 1; ++i)
	//	{
	//		LNext(&list, &data);
	//		if (data % 2 == 0)
	//			LRemove(&list);
	//	}

	//}

	//if (LFirst(&list, &data))
	//{
	//	cout << data << " ";

	//	for (int i = 0; i < LCount(&list) - 1; ++i)
	//	{
	//		if (LNext(&list, &data))
	//			cout << data << " ";
	//	}
	//	cout << '\n' << endl;
	//}

	return 0;
}