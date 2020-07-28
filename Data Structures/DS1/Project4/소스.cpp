#include<iostream>
#include"ArrayList.h"


using namespace std;

int main()
{
	List list;
	Point compos;
	Point* ppos;

	ListInit(&list);

	ppos = new Point;
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = new Point;
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = new Point;
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = new Point;
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);


	cout << "���� �������� �� : " << LCount(&list) << endl;

	if (LFirst(&list, &ppos))
	{
		showPointPos(ppos);

		while (LNext(&list, &ppos))
			showPointPos(ppos);

		cout << endl;
	}
	

	if (LFirst(&list, &ppos))
	{
		if (ppos->xpos == 2)
		{
			ppos = LRemove(&list);
			delete ppos;
		}
		while (LNext(&list, &ppos))
		{
			if (ppos->xpos == 2)
			{
				ppos = LRemove(&list);
				delete ppos;
			}
		}
	}


	cout << "���� �������� �� : " << LCount(&list) << endl;

	if (LFirst(&list, &ppos))
	{
		showPointPos(ppos);

		while (LNext(&list, &ppos))
			showPointPos(ppos);

		cout << endl;
	}

	return 0;
}