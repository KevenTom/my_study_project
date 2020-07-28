#include<iostream>
#include"DLinkedList.h"

using namespace std;

int WhoIsPrecede(LData d1, LData d2)
{
	if (d1->xpos < d2->xpos)
		return 0;

	else if (d1->xpos == d2->xpos)
	{
		if (d1->ypos < d2->ypos)
			return 0;
		else
			return 1;
	}

	else
		return 1;
}

int main()
{
	List list;
	Point compos;
	Point* ppos;

	ListInit(&list);


	ppos = new Point;
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = new Point;
	SetPointPos(ppos, 3, 7);
	LInsert(&list, ppos);

	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

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

	ppos = new Point;
	SetPointPos(ppos, 2, 5);
	LInsert(&list, ppos);

	cout << "현재 데이터의 수 : " << LCount(&list) << endl;

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


	cout << "현재 데이터의 수 : " << LCount(&list) << endl;

	if (LFirst(&list, &ppos))
	{
		showPointPos(ppos);

		while (LNext(&list, &ppos))
			showPointPos(ppos);

		cout << endl;
	}

	return 0;
}