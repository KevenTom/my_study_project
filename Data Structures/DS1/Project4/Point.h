#pragma once

#define TRUE 1
#define FALSE 0

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

void SetPointPos(Point* ppos, int xpos, int yps);
void showPointPos(Point* ppos);
int PointComp(Point* pps1, Point* pos2);