#pragma once

template<typename T>
struct HeapElem {
	int pr;
	T data;
};

template<typename T>
class Heap
{
protected:
	int numOfData;
	HeapElem<T> HeapArr[100];
public:
	Heap()
		:numOfData(0)
	{}

	int HisEmoty() {
		if (this->numOfData == 0)
			return true;
		else
			return false;
	}

	int GetParentIDX(int idx) {
		return idx / 2;
	}

	int GetLChildIDX(int idx) {
		return idx * 2;
	}

	int GetRChildIDX(int idx) {
		return idx * 2 + 1;
	}


	int GetHiPriChildIdx(int idx) {
		if (GetLChildIDX(idx) > numOfData) //idx의 자식노드 존재유무 확인
			return 0;
		else if (GetLChildIDX(idx) == numOfData) //자식노드중 왼쪽만 존재한다면
			return GetLChildIDX(idx);
		
		else if (HeapArr[GetLChildIDX(idx)].pr > HeapArr[GetRChildIDX(idx)].pr) //자식노드 둘다 존재한 상태에서 
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}

	void HInsert(T data, int pr) {
		int idx = this->numOfData + 1;

		while (idx != 1) {
			if (pr < (HeapArr[GetParentIDX(idx)].pr))
			{
				HeapArr[idx] = HeapArr[GetParentIDX(idx)];
				idx = GetParentIDX(idx);
			}
			else
				break;
		}

		HeapArr[idx] = { pr, data };
		numOfData += 1;
	}

	T HDelete() {
		if (HisEmoty())
			return 0;

		int idx = 1;
		T rdata = HeapArr[idx].data;

		if (GetHiPriChildIdx(idx) == 0) {
			numOfData -= 1;
			return rdata;
		}

		HeapArr[idx] = HeapArr[numOfData];

		while (true) { //여기가 문제임
			if (HeapArr[GetHiPriChildIdx(idx)].pr < HeapArr[idx].pr) {
				HeapElem<T> temp = HeapArr[GetHiPriChildIdx(idx)];
				HeapArr[GetHiPriChildIdx(idx)] = HeapArr[idx];
				HeapArr[idx] = temp;
				idx = GetHiPriChildIdx(idx);
			}
			else
				break;
		}

		numOfData -= 1;
		return rdata;
	}
};

