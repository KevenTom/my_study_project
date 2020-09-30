#pragma once
#include"Slot.h"

#define NULL 0
#define MAX_TBL 100

template<class T>
class Table
{
private:
	Slot<T> tbl[MAX_TBL];
	int (*HashFunc)(int key); //������ 1�� �ؽ�
	int (*HashFunc2)(int key); //������ 2�� �ؽ�
public:
	Table(int (*fun)(int key), int (*fun2)(int key)) //�����ڷ� 1��, 2�� �ؽ��� ����
		: HashFunc(fun), HashFunc2(fun2) {
		for (int i = 0; i < MAX_TBL; ++i)
			tbl[i].status = EMPTY;
	}

	void TBLInsert(Key k, T* v) {
		int hv = HashFunc(k); //1�� �ؽ��� ����
		int dh; //�浹 ȸ�Ǹ� ���� ����

		if (tbl[hv].status != INUSE) { // �����Ͱ� �ִ� ���°� �ƴ� ���
			tbl[hv].key = k;
			tbl[hv].val = v;
			tbl[hv].status = INUSE;
		}
		else {
			hv = HashFunc2(k); //hv ���� 2�� �ؽ��� ����
			dh = hv;

			while (tbl[hv].status == INUSE) { // �����Ͱ� �ִ� ���°� �ƴ� ��� hv + dh, hv�� MAX_TBL�� �Ѿ�� -100
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

		if (tbl[hv].status == INUSE && tbl[hv].val->GetSSN() == k) { // �����Ͱ� ��������鼭 SSN���� �Ű����� ���� ���� ���
			tbl[hv].status = DELETED;
			return tbl[hv].val;
		}
		else { //�ƴҰ�� 2�� �ؽ��� ��ġ
			hv = HashFunc2(k);
			dh = hv;

			while (tbl[hv].status != INUSE && tbl[hv].val->GetSSN() != k) { // ���� �˻�
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