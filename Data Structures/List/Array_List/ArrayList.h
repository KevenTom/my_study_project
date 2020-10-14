#pragma once
/*
순차리스트 ADT

void ArrayList<T>::LInsert(T data)
-리스트에 매개변수 data의 값을 저장한다.

bool ArrayList<T>::LFirst(T* pdata)
- 리스트의 첫 번째 노드를 참조한다.
- 참조 실패 시 false을 반환한다.
- 참조 성공 시 true를 반환하고 pdata에 데이터를 저장한다.

bool ArrayList<T>::LNext(T* pdata)
- 참조된 노드의 다음 노드를 참조한다.
- 참조 실패 시 false을 반환한다.
- 참조 성공 시 true를 반환하고 pdata에 데이터를 저장한다.

void ArrayList<T>::LRemove()
- 참조된 노드를 삭제한다.

int ArrayList<T>::ListSize()
- 리스트의 데이터 수만큼 반환한다.
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