#pragma once
#include"Slot.h"

#define NULL 0

template<class T>
class Table
{
private:
	Slot<T> tbl[100]; //테이블
	int (*HashFunc)(int key); //저장할 해쉬함수
public:
	Table(int (*fun)(int key)) //생성자로 해쉬함수 저장
		:HashFunc(fun) {
		for (int i = 0; i < 100; ++i)
			tbl[i].status = EMPTY;
	}
	
	void TBLInsert(Key k, T* v) { //테이블에 키, 값 저장
		int hv = HashFunc(k);
		tbl[hv].key = k;
		tbl[hv].val = v;
		tbl[hv].status = INUSE;
	}

	T* TBLDelete(Key k) { //테이블에서 데이터 삭제 and 리턴
		int hv = HashFunc(k);

		if (tbl[hv].status != INUSE)
			return NULL;
		else {
			tbl[hv].status = DELETED;
			return tbl[hv].val;
		}
	}

	T* TBLSearch(Key k) { //테이블에서 탐색
		int hv = HashFunc(k);

		if (tbl[hv].status != INUSE)
			return NULL;
		else
			return tbl[hv].val;
	}
};