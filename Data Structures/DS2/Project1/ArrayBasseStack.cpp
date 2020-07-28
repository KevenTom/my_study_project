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

	return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	if (pstack->topIndex == -1)
	{
		pstack->arr[0] = data;
		pstack->topIndex = 0;
	}
	else if (pstack->topIndex == ARRAY_MAX - 1)
	{
		cout << "초과했음" << endl;
		return;
	}
	else
	{
		for (int i = pstack->topIndex; i >= 0; --i)
			pstack->arr[i + 1] = pstack->arr[i];
		pstack->arr[0] = data;
		pstack->topIndex += 1;
	}
}

Data SPop(Stack* pstack)
{
	Data Rdata;
	if (pstack->topIndex == -1)
	{
		cout << "데이터 없음" << endl;
		return 0;
	}
	else
	{
		Rdata = pstack->arr[0];

		for (int i = 0; i < pstack->topIndex; ++i)
			pstack->arr[i] = pstack->arr[i + 1];
		pstack->topIndex -= 1;
		return Rdata;
	}
}

Data SPeek(Stack* pstack)
{
	if (pstack->topIndex == -1)
	{
		cout << "데이터 없음" << endl;
		return 0;
	}
	else
	{
		return pstack->arr[0];
	}
}