#pragma once

template<typename T>
class Heap
{
protected:
	typedef int (*PriorityComp)(T d1, T d2);
	PriorityComp comp;
	int numOfData;
	T HeapArr[100];

public:
	Heap(PriorityComp pc)
		:numOfData(0), comp(pc)
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
		if (GetLChildIDX(idx) > numOfData)
			return 0;
		else if (GetLChildIDX(idx) == numOfData)
			return GetLChildIDX(idx);

		else if (comp(HeapArr[GetLChildIDX(idx)], HeapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}

	void HInsert(T data) {
		int idx = numOfData + 1;

		while (idx != 1) {
			if (comp(data, HeapArr[GetParentIDX(idx)]) > 0)
			{
				HeapArr[idx] = HeapArr[GetParentIDX(idx)];
				idx = GetParentIDX(idx);
			}
			else
				break;
		}

		HeapArr[idx] = data;
		numOfData += 1;
	}

	T HDelete() {
		if (HisEmoty())
			return 0;

		T rdata = HeapArr[1];
		int idx = 1;
		int childIdx;

		while (childIdx = GetHiPriChildIdx(idx)) {
			if (comp(HeapArr[numOfData], HeapArr[childIdx]) > 0)
				break;

			HeapArr[idx] = HeapArr[childIdx];
			idx = childIdx;
		}

		HeapArr[idx] = HeapArr[numOfData];
		numOfData -= 1;
		return rdata;
	}
};

