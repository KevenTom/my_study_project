//#include<iostream>
//#include"DLinkedList.h"
//
//using namespace std;
//
//int WhoIsPrecede(LData d1, LData d2)
//{
//	if (d1 < d2)
//		return 0;
//	else
//		return 1;
//}
//
//int main()
//{
//	List list;
//	int data;
//	ListInit(&list);
//
//	SetSortRube(&list, WhoIsPrecede);
//
//	LInsert(&list, 33);
//	LInsert(&list, 22);
//	LInsert(&list, 11);
//	LInsert(&list, 11);
//	LInsert(&list, 22);
//	LInsert(&list, 22);
//	LInsert(&list, 33);
//
//
//	cout << "현재 데이터 수 : " << LCount(&list) << endl;
//	if (LFirst(&list, &data))
//	{
//		cout << data << " ";
//
//		while (LNext(&list, &data))
//		{
//			cout << data << " ";
//		}
//		cout << '\n' << endl;
//	}
//
//	if (LFirst(&list, &data))
//	{
//		if (data == 33)
//			LRemove(&list);
//
//		while (LNext(&list, &data))
//		{
//			if (data == 33)
//				LRemove(&list);
//		}
//
//	}
//
//	cout << "현재 데이터 수 : " << LCount(&list) << endl;
//	if (LFirst(&list, &data))
//	{
//		cout << data << " ";
//
//		while (LNext(&list, &data))
//		{
//			cout << data << " ";
//		}
//		cout << '\n' << endl;
//	}
//
//	return 0;
//}