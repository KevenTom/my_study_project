#include<iostream>
#include"Point.h"

using namespace std;

void SetPointPos(Point* ppos, int xpos, int ypos)
{
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void showPointPos(Point* ppos)
{
	cout << ppos->xpos << ", " << ppos->ypos << endl;
}
int PointComp(Point* ps1, Point* pos2)
{
	if (ps1->xpos == pos2->xpos && ps1->ypos == pos2->ypos)
		return 0;
	else if (ps1->xpos == pos2->xpos)
		return 1;
	else if (ps1->ypos == pos2->ypos)
		return 2;
	else
		return -1;
}