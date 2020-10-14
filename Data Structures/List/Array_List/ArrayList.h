#pragma once
/*
��������Ʈ ADT

void ArrayList<T>::LInsert(T data)
-����Ʈ�� �Ű����� data�� ���� �����Ѵ�.

bool ArrayList<T>::LFirst(T* pdata)
- ����Ʈ�� ù ��° ��带 �����Ѵ�.
- ���� ���� �� false�� ��ȯ�Ѵ�.
- ���� ���� �� true�� ��ȯ�ϰ� pdata�� �����͸� �����Ѵ�.

bool ArrayList<T>::LNext(T* pdata)
- ������ ����� ���� ��带 �����Ѵ�.
- ���� ���� �� false�� ��ȯ�Ѵ�.
- ���� ���� �� true�� ��ȯ�ϰ� pdata�� �����͸� �����Ѵ�.

void ArrayList<T>::LRemove()
- ������ ��带 �����Ѵ�.

int ArrayList<T>::ListSize()
- ����Ʈ�� ������ ����ŭ ��ȯ�Ѵ�.
*/

#define LIST_LEN 100

template<typename T>
class ArrayList {
private:
	T arr[LIST_LEN];
	int numOfData;
	int curPos;

public:
	ArrayList();

	void LInsert(T data);
	bool LFirst(T* pdata);
	bool LNext(T* pdata);
	void LRemove();
	int ListSize();
};





template<typename T>
inline ArrayList<T>::ArrayList() :numOfData(0), curPos(-1) {}

template<typename T>
inline void ArrayList<T>::LInsert(T data) {
	if (numOfData >= LIST_LEN)
		return;

	arr[numOfData] = data;
	++numOfData;
}

template<typename T>
inline bool ArrayList<T>::LFirst(T* pdata) {
	if (numOfData == 0)
		return false;

	curPos = 0;
	*pdata = arr[0];
	return true;
}

template<typename T>
inline bool ArrayList<T>::LNext(T* pdata) {
	if (curPos >= numOfData - 1)
		return false;

	++curPos;
	*pdata = arr[curPos];
	return true;
}

template<typename T>
inline void ArrayList<T>::LRemove() {
	for (int i = curPos; i < numOfData; ++i)
		arr[i] = arr[i + 1];

	--numOfData;
	--curPos;
}

template<typename T>
inline int ArrayList<T>::ListSize() {
	return numOfData;
}