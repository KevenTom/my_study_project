#pragma once
#include"Slot.h"

#define NULL 0

template<class T>
class Table
{
private:
	Slot<T> tbl[100]; //���̺�
	int (*HashFunc)(int key); //������ �ؽ��Լ�
public:
	Table(int (*fun)(int key)) //�����ڷ� �ؽ��Լ� ����
		:HashFunc(fun) {
		for (int i = 0; i < 100; ++i)
			tbl[i].status = EMPTY;
	}
	
	void TBLInsert(Key k, T* v) { //���̺� Ű, �� ����
		int hv = HashFunc(k);
		tbl[hv].key = k;
		tbl[hv].val = v;
		tbl[hv].status = INUSE;
	}

	T* TBLDelete(Key k) { //���̺��� ������ ���� and ����
		int hv = HashFunc(k);

		if (tbl[hv].status != INUSE)
			return NULL;
		else {
			tbl[hv].status = DELETED;
			return tbl[hv].val;
		}
	}

	T* TBLSearch(Key k) { //���̺��� Ž��
		int hv = HashFunc(k);

		if (tbl[hv].status != INUSE)
			return NULL;
		else
			return tbl[hv].val;
	}
};