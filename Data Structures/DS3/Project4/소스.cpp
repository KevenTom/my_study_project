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

		for (int i = 0; i < 3600; ++i) // for문 1회전이 1초임
		{
			if (i % CUS_COME_TERM == 0) // 15초 마다 햄버거 주문을 받음
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

		cout << "시뮬레이션 결과" << endl;
		cout << "- 치즈버거 주문 갯수 : " << cheOrder << endl;
		cout << "- 불고기버거 주문 갯수 : " << bulOrder << endl;
		cout << "- 더블버거 주문 갯수 : " << dubOrder << endl;
		cout << "- 대기실 사이즈 : " << ARRAY_MAX << endl;
	}
	return 0;
}