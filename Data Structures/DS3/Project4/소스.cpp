#include<iostream>
#include<ctime>
#include"CircularQueue.h"

#define CUS_COME_TERM 15

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

using namespace std;

int main()
{
	for (int i = 0; i < 10000; ++i)
	{
		LQueue que;
		int makerProc = 0;
		int cheOrder = 0, bulOrder = 0, dubOrder = 0;
		srand(time(NULL));

		for (int i = 0; i < 3600; ++i) // for�� 1ȸ���� 1����
		{
			if (i % CUS_COME_TERM == 0) // 15�� ���� �ܹ��� �ֹ��� ����
			{
				switch (rand() % 3)
				{
				case CHE_BUR:
					que.Enqueue(CHE_TERM);
					++cheOrder;
					break;

				case BUL_BUR:
					que.Enqueue(BUL_TERM);
					++bulOrder;
					break;

				case DUB_BUR:
					que.Enqueue(DUB_TERM);
					++dubOrder;
					break;
				}
			}

			if (makerProc <= 0 && !que.QIsEmpty())
				makerProc = que.Dequeue();

			makerProc--;
		}

		cout << "�ùķ��̼� ���" << endl;
		cout << "- ġ����� �ֹ� ���� : " << cheOrder << endl;
		cout << "- �Ұ����� �ֹ� ���� : " << bulOrder << endl;
		cout << "- ������� �ֹ� ���� : " << dubOrder << endl;
		cout << "- ���� ������ : " << ARRAY_MAX << endl;
	}
	return 0;
}