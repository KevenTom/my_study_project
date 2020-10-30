#pragma once

#define HEAP_LEN 100

template<typename T>
class Heap {
private:
	struct Node	{
		T data;
		int priority;
	};
	
	Node heapArr[HEAP_LEN];
	int numOfData;

	int GetParentIDX(int idx);
	int GetLChildIDX(int idx);
	int GetRChildIDX(int idx);
	int GetPriorityChildIDX(int idx);
public:
	Heap();

	bool HIsEmpty();
	void HInsert(T data, int pr);
	T HDelete();
};

template<typename T>
inline int Heap<T>::GetParentIDX(int idx) {
	return idx / 2;
}

template<typename T>
inline int Heap<T>::GetLChildIDX(int idx) {
	return idx * 2;
}

template<typename T>
inline int Heap<T>::GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

template<typename T>
inline int Heap<T>::GetPriorityChildIDX(int idx) {
	if (GetLChildIDX(idx) > numOfData)	//자식노드
		return 0;
	else if (GetLChildIDX(idx) == numOfData)
		return GetLChildIDX(idx);

	else {
		if (heapArr[GetLChildIDX(idx)].priority > heapArr[GetRChildIDX(idx)].priority)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

template<typename T>
inline Heap<T>::Heap() :numOfData(0) {}

template<typename T>
inline bool Heap<T>::HIsEmpty() {
	if (numOfData == 0)
		return true;
	else
		return false;
}

template<typename T>
inline void Heap<T>::HInsert(T data, int pr) {
	int idx = numOfData + 1;
	Node nelen = { data, pr };

	while (idx != 1) {
		if (pr < heapArr[GetParentIDX(idx)].priority) {
			heapArr[idx] = heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	heapArr[idx] = nelen;
	++numOfData;
}

template<typename T>
inline T Heap<T>::HDelete() {
	T reData = heapArr[1].data;
	Node lastElem = heapArr[numOfData];


	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetPriorityChildIDX(parentIdx)) {
		if (lastElem.priority <= heapArr[childIdx].priority)
			break;

		heapArr[parentIdx] = heapArr[childIdx];
		parentIdx = childIdx;
	}

	heapArr[parentIdx] = lastElem;
	--numOfData;
	return reData;

}
