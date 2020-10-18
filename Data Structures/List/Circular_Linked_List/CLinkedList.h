#pragma once
/*
원형 연결 리스트 ADT

bool CLinKedList<T>::isEmpty()
- 리스트가 비어있다면 false, 아니라면 true를 반환한다.

int CLinKedList<T>::ListSize()
- 리스트의 노드 수 만큼 반환한다.

void CLinKedList<T>::SetsortFunc(comp func)
- 리스트에 정렬의 기준이 되는 함수 포인터를 설정한다.
- comp 자료형은 bool 반환에 매개변수 T, T를 가진 함수 포인터의 자료형이다.

void CLinKedList<T>::InsertData(T indata)
- 리스트에 indata를 저장한다.
- 정렬 함수가 있으면 함수 기준으로 데이터를 저장한다.
- 정렬 함수가 없으면 리스트 맨 앞에 데이터를 저장한다.

inline void CLinKedList<T>::InsertTail(T indata)
- 리스트에 indata를 마지막 노드로 저장한다. 

bool CLinKedList<T>::FirstNode(T* pdata)
- 리스트의 첫 번째 노드를 참조한다.
- 참조 실패 시 false을 반환한다.
- 참조 성공 시 true를 반환하고 pdata에 데이터를 저장한다.

bool CLinKedList<T>::NextNode(T* pdata)
- 참조된 노드의 다음 노드를 참조한다.
- 참조 실패 시 false을 반환한다.
- 참조 성공 시 true를 반환하고 pdata에 데이터를 저장한다.

void CLinKedList<T>::RemoveNode()
- 참조된 노드를 삭제한다.
*/

template<typename T>
class Node {	//템플릿 노드
public:
	T data;
	Node* next;
};



template<typename T>
class CLinKedList {
private:
	using comp = bool(*)(T, T);	//함수 포인터 타입의 별칭

	Node<T>* tail;	//리스트의 마지막 지점
	Node<T>* cur;	//참조, 삭제를 돕는 멤버
	Node<T>* before;//참조, 삭제를 돕는 멤버
	int numOfData;		//노드 수
	comp sortFunc;	//정렬함수

	void InsertFront(T indata);	 //정렬함수가 없을시 사용
	void InsertSort(T indata);	 //정렬함수가 있을시 사용
public:
	CLinKedList();
	~CLinKedList();

	bool isEmpty();
	int ListSize();
	void SetsortFunc(comp func);
	void InsertData(T indata);
	void InsertTail(T indata);

	bool FirstNode(T* pdata);
	bool NextNode(T* pdata);
	void RemoveNode();
};





template<typename T>
inline CLinKedList<T>::CLinKedList() :tail(nullptr), sortFunc(nullptr) {}

template<typename T>
inline CLinKedList<T>::~CLinKedList() {
	T temp;

	if (FirstNode(&temp) == true) {
		RemoveNode();

		while (NextNode(&temp) == true)
			RemoveNode();
	}

	delete tail;
}

template<typename T>
inline bool CLinKedList<T>::isEmpty() {
	if (tail == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline int CLinKedList<T>::ListSize() {
	return numOfData;
}

template<typename T>
inline void CLinKedList<T>::SetsortFunc(comp func) {
	sortFunc = func;
}

template<typename T>
inline void CLinKedList<T>::InsertData(T idata) {
	if (sortFunc == nullptr)	//정렬함수가 없다면
		InsertFront(idata);		//InsertFront 함수에서 진행
	else						//정렬함수가 있다면
		InsertSort(idata);		//InsertSort 함수에서 진행
}

template<typename T>
inline bool CLinKedList<T>::FirstNode(T* pdata) {
	if (isEmpty())		//노드가 없다면
		return false;	//false 반환

	before = tail;
	cur = tail->next;

	*pdata = cur->data;	//pdata에 첫번째 노드의 데이터를 반환
	return true;
}

template<typename T>
inline bool CLinKedList<T>::NextNode(T* pdata) {
	if (isEmpty())		//노드가 없다면
		return false;	//false 반환

	before = cur;
	cur = cur->next;

	*pdata = cur->data;	//pdata에 cur 노드의 데이터를 반환
	return true;
}

template<typename T>
inline void CLinKedList<T>::RemoveNode() {
	Node<T>* rNode;	//삭제한 노드를 저장할 포인터
	rNode = cur;

	if (rNode == tail) { //삭제할 노드가 tail 이고
		if (tail == tail->next)	//노드가 하나뿐이라면
			tail = nullptr;		//tail을 nullptr로 만듬
		else
			tail = before;		//아니라면 tail을 before을 가리킴

	}

	before->next = cur->next;	//before 다음 노드를 cur의 다음 노드를 가리키게 함
	cur = before;				//cur은 before을 가리키게 함

	delete rNode;
	--numOfData;
}


template<typename T>
inline void CLinKedList<T>::InsertFront(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;

	if (isEmpty()) {			//리스트가 비어있다면
		tail = newNode;			//tail이 newNode를 가리킴
		newNode->next = newNode;//원형이니까 다음 노드로 자기자신을 가리킴
	}
	else {
		newNode->next = tail->next;	//newNode의 다음 노드를 tail의 다음 노드를 가리키게 함
		tail->next = newNode;		//tail 다음 노드를 newNode를 가르키게 함
	}

	++numOfData;
}

template<typename T>
inline void CLinKedList<T>::InsertSort(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;

	if (isEmpty()) {
		tail = newNode;
		newNode->next = newNode;
	}
	else {
		Node<T>* pred = tail;	//정렬함수 기준으로 찾아갈 노드

		if (sortFunc(pred->next->data, idata)) {	//정렬함수가 true면 다음 노드를 가리킴
			pred = pred->next;	//처음만 pred가 tail이기 때문에 이렇게 따로 if를 해줌

			while (sortFunc(pred->next->data, idata) && pred != tail)	//정렬함수가 true이고 pred가 tail이 아니면 다음을 가리킴
				pred = pred->next;
		}

		newNode->next = pred->next;
		pred->next = newNode;

		if (sortFunc(tail->data, newNode->data)) //newNode가 tail 다음이라면 tail이 newNode를 가리킴
			tail = newNode;
	}

	++numOfData;
}

template<typename T>
inline void CLinKedList<T>::InsertTail(T indata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = indata;

	if (isEmpty()) {			//리스트가 비어있다면
		tail = newNode;			//tail이 newNode를 가리킴
		newNode->next = newNode;//원형이니까 다음 노드로 자기자신을 가리킴
	}
	else {
		newNode->next = tail->next;	//newNode의 다음 노드를 tail의 다음 노드를 가리키게 함
		tail->next = newNode;		//tail 다음 노드를 newNode를 가르키게 함
		tail = newNode;				//tail이 newNode를 가리킴
	}

	++numOfData;
}