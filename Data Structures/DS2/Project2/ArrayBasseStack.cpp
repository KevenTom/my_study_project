#include<iostream>
#include"ArrayBaseStack.h"

using namespace std;

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->arr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	Data Rdata;

	if (SIsEmpty(pstack))
	{
		cout << "데이터 없음" << endl;
		return -1;
	}
	else
	{
		Rdata = pstack->arr[pstack->topIndex];
		pstack->topIndex -= 1;
		return Rdata;
	}
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		cout << "데이터 없음" << endl;
		return -1;
	}
	else
	{
		return pstack->arr[pstack->topIndex];
	}
}