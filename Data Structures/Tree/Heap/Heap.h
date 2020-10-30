#pragma once
/*
�ּ� �� ADT

Heap<T>::Heap(PriorityComp pc)
- ���� ������ ������ �Ǵ� �Լ� �����͸� �����Ѵ�.
- PriorityComp �ڷ����� bool ��ȯ�� �Ű����� T, T�� ���� �Լ� ������ �ڷ����̴�.

bool Heap<T>::HIsEmpty()
- ����Ʈ�� ����ִٸ� true, �ƴ϶�� false�� ��ȯ�Ѵ�.

void Heap<T>::HInsert(T data)
- ���� data�� �����Ѵ�.

T Heap<T>::HDelete()
- �켱������ ���� �����͸� �����Ѵ�.
- ������ �����ʹ� ��ȯ�Ѵ�.
*/

#define HEAP_LEN 100

template<typename T>
class Heap {
	using PriorityComp = bool(*)(T, T);
private:
	PriorityComp comp;
	T heapArr[HEAP_LEN];
	int numOfData;

	int GetParentIDX(int idx);	//�θ� ����� �ε��� �� ��ȯ
	int GetLChildIDX(int idx);	//���� �ڽ� ����� �ε��� �� ��ȯ
	int GetRChildIDX(int idx);	//������ �ڽ� ����� �ε��� �� ��ȯ
	int GetPriorityChildIDX(int idx);	//�ΰ��� �ڽ� ��� �� �켱������ ���� �ڽ� ����� �ε��� �� ��ȯ
public:
	Heap(PriorityComp pc);

	bool HIsEmpty();		//���� ������� Ȯ��
	void HInsert(T data);	//���� ������ ����
	T HDelete();	//���� ������ ��ȯ and ����
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
	if (GetLChildIDX(idx) > numOfData)			//�ڽĳ�尡 ���ٸ� 0�� ��ȯ
		return 0;
	else if (GetLChildIDX(idx) == numOfData)	//�ڽĳ�尡 �ϳ����̸� �� ��带 ��ȯ
		return GetLChildIDX(idx);

	else {
		if (comp(heapArr[GetLChildIDX(idx)], heapArr[GetRChildIDX(idx)]))	//�ڽ� ��� �켱���� ���ϰ� ��ȯ
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
	int idx = numOfData + 1;	//idx�� ������ ��ġ�� ����

	while (idx != 1) {	//idx�� ��Ʈ��尡 �ɶ����� �ݺ�
		if (comp(data, heapArr[GetParentIDX(idx)])) {	//�� ����� �켱������ ���ٸ� �θ�, �ڽ� ��� ��ü
			heapArr[idx] = heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else											//�ƴ϶�� break
			break;
	}

	heapArr[idx] = data;
	++numOfData;
}

template<typename T>
inline T Heap<T>::HDelete() {
	T reData = heapArr[1];				//��ȯ�� ��Ʈ ��� ����
	T lastElem = heapArr[numOfData];	//���� ������ ��� ����

	int parentIdx = 1;	//������ ��尡 ��Ʈ ��忡������ �ڱ��ڸ��� ã���������� ������ ����
	int childIdx;

	while (childIdx = GetPriorityChildIDX(parentIdx)) {	//parentIdx�� �ڽĳ�带 childIdx�� ����
		if (comp(lastElem, heapArr[childIdx]))			//�ڽĳ��� ���ؼ� ������ ����� �켱������ ���ٸ� break
			break;
		heapArr[parentIdx] = heapArr[childIdx];	//parentIdx ��忡 �ڽ� ��带 ����
		parentIdx = childIdx;					//parentIdx ������ �ڽ� ��带 ����
	}

	heapArr[parentIdx] = lastElem;
	--numOfData;
	return reData;
}