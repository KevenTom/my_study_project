#pragma once
/*
최소 힙 ADT

Heap<T>::Heap(PriorityComp pc)
- 힙에 정렬의 기준이 되는 함수 포인터를 설정한다.
- PriorityComp 자료형은 bool 반환에 매개변수 T, T를 가진 함수 포인터 자료형이다.

bool Heap<T>::HIsEmpty()
- 리스트가 비어있다면 true, 아니라면 false를 반환한다.

void Heap<T>::HInsert(T data)
- 힙에 data를 저장한다.

T Heap<T>::HDelete()
- 우선순위가 높은 데이터를 삭제한다.
- 삭제한 데이터는 반환한다.
*/

#define HEAP_LEN 100

template<typename T>
class Heap {
	using PriorityComp = bool(*)(T, T);
private:
	PriorityComp comp;
	T heapArr[HEAP_LEN];
	int numOfData;

	int GetParentIDX(int idx);	//부모 노드의 인덱스 값 반환
	int GetLChildIDX(int idx);	//왼쪽 자식 노드의 인덱스 값 반환
	int GetRChildIDX(int idx);	//오른쪽 자식 노드의 인덱스 값 반환
	int GetPriorityChildIDX(int idx);	//두개의 자식 노드 중 우선순위가 높은 자식 노드의 인덱스 값 반환
public:
	Heap(PriorityComp pc);

	bool HIsEmpty();		//힙이 비었는지 확인
	void HInsert(T data);	//힙에 데이터 저장
	T HDelete();	//힙에 데이터 반환 and 삭제
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
	if (GetLChildIDX(idx) > numOfData)			//자식노드가 없다면 0을 반환
		return 0;
	else if (GetLChildIDX(idx) == numOfData)	//자식노드가 하나뿐이면 그 노드를 반환
		return GetLChildIDX(idx);

	else {
		if (comp(heapArr[GetLChildIDX(idx)], heapArr[GetRChildIDX(idx)]))	//자식 노드 우선순위 비교하고 반환
			return GetLChildIDX(idx);
		else
			return GetRChildIDX(idx);
	}
}

template<typename T>
inline Heap<T>::Heap(PriorityComp pc) :numOfData(0), comp(pc) {}

template<typename T>
inline bool Heap<T>::HIsEmpty() {
	if (numOfData == 0)
		return true;
	else
		return false;
}

template<typename T>
inline void Heap<T>::HInsert(T data) {
	int idx = numOfData + 1;	//idx에 마지막 위치를 저장

	while (idx != 1) {	//idx가 루트노드가 될때까지 반복
		if (comp(data, heapArr[GetParentIDX(idx)])) {	//새 노드의 우선순위가 높다면 부모, 자식 노드 교체
			heapArr[idx] = heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else											//아니라면 break
			break;
	}

	heapArr[idx] = data;
	++numOfData;
}

template<typename T>
inline T Heap<T>::HDelete() {
	T reData = heapArr[1];				//반환할 루트 노드 저장
	T lastElem = heapArr[numOfData];	//힙의 마지막 노드 저장

	int parentIdx = 1;	//마지막 노드가 루트 노드에서부터 자기자리를 찾을때까지의 변수를 저장
	int childIdx;

	while (childIdx = GetPriorityChildIDX(parentIdx)) {	//parentIdx의 자식노드를 childIdx에 저장
		if (comp(lastElem, heapArr[childIdx]))			//자식노드와 비교해서 마지막 노드의 우선순위가 높다면 break
			break;
		heapArr[parentIdx] = heapArr[childIdx];	//parentIdx 노드에 자식 노드를 저장
		parentIdx = childIdx;					//parentIdx 변수에 자식 노드를 저장
	}

	heapArr[parentIdx] = lastElem;
	--numOfData;
	return reData;
}