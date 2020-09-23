#pragma once
#include"Slot.h"

#define NULL 0
#define MAX_TBL 100

template<class T>
class Table
{
private:
	Slot<T> tbl[MAX_TBL];
	int (*HashFunc)(int key); //저장할 1차 해쉬
	int (*HashFunc2)(int key); //저장할 2차 해쉬
public:
	Table(int (*fun)(int key), int (*fun2)(int key)) //생성자로 1차, 2차 해쉬를 저장
		: HashFunc(fun), HashFunc2(fun2) {
		for (int i = 0; i < MAX_TBL; ++i)
			tbl[i].status = EMPTY;
	}

	void TBLInsert(Key k, T* v) {
		int hv = HashFunc(k); //1차 해쉬로 저장
		int dh; //충돌 회피를 위한 변수

		if (tbl[hv].status != INUSE) { // 데이터가 있는 상태가 아닐 경우
			tbl[hv].key = k;
			tbl[hv].val = v;
			tbl[hv].status = INUSE;
		}
		else {
			hv = HashFunc2(k); //hv 값을 2차 해쉬로 저장
			dh = hv;

			while (tbl[hv].status == INUSE) { // 데이터가 있는 상태가 아닐 경우 hv + dh, hv가 MAX_TBL을 넘어가면 -100
				if (hv >= MAX_TBL)
					hv -= 100;

				hv += dh;
			}

			tbl[hv].key = k;
			tbl[hv].val = v;
			tbl[hv].status = INUSE;
		}
	}

	T* TBLDelete(Key k) {
		int hv = HashFunc(k);
		int dh;

		if (tbl[hv].status == INUSE && tbl[hv].val->GetSSN() == k) { // 데이터가 들어있으면서 SSN값이 매개변수 값이 맞을 경우
			tbl[hv].status = DELETED;
			return tbl[hv].val;
		}
		else { //아닐경우 2차 해쉬로 서치
			hv = HashFunc2(k);
			dh = hv;

			while (tbl[hv].status != INUSE && tbl[hv].val->GetSSN() != k) { // 좀더 검색
				if (hv >= MAX_TBL)
					hv -= 100;

				hv += dh;
			}

			tbl[hv].status = DELETED;
			return tbl[hv].val;
		}
	}

	T* TBLSearch(Key k) {
		int hv = HashFunc(k);
		int dh;

		if (tbl[hv].status == INUSE && tbl[hv].val->GetSSN() == k) {
			return tbl[hv].val;
		}
		else {
			hv = HashFunc2(k);
			dh = hv;

			while (tbl[hv].status != INUSE && tbl[hv].val->GetSSN() != k) {
				if (hv >= MAX_TBL)
					hv -= 100;

				hv += dh;
			}

			return tbl[hv].val;
		}

	}
};