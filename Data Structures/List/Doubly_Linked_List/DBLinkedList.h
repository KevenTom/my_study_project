#pragma once
/*
연결리스트 ADT

bool DBLinKedList<T>::isEmpty()
- 리스트가 비어있다면 false, 아니라면 true를 반환한다.

int DBLinKedList<T>::ListSize()
- 리스트의 노드 수 만큼 반환한다.

void DBLinKedList<T>::SetsortFunc(comp func)
- 리스트에 정렬의 기준이 되는 함수 포인터를 설정한다.
- comp 자료형은 bool 반환에 매개변수 T, T를 가진 함수 포인터의 자료형이다.

void DBLinKedList<T>::InsertData(T idata)
- 리스트에 idata를 저장한다.
- 정렬 함수가 있으면 함수 기준으로 데이터를 저장한다.
- 정렬 함수가 없으면 리스트 맨 앞에 데이터를 저장한다.

bool DBLinKedList<T>::FirstNode(T* pdata)
- 리스트의 첫 번째 노드를 참조한다.
- 참조 실패 시 false을 반환한다.
- 참조 성공 시 true를 반환하고 pdata에 데이터를 저장한다.

bool DBLinKedList<T>::NextNode(T* pdata)
- 참조된 노드의 다음 노드를 참조한다.
- 참조 실패 시 false을 반환한다.
- 참조 성공 시 true를 반환하고 pdata에 데이터를 저장한다.

void DBLinKedList<T>::RemoveNode()
- 참조된 노드를 삭제한다.
*/

template<typename T>
class Node {	//양방향 노드
public:
	T data;
	Node* next;
	Node* prev;
};

template<typename T>
class DBLinKedList {
private:
	using comp = bool(*)(T, T);	//함수 포인터 타입의 별칭

	Node<T>* head;	//리스트의 시작지점
	Node<T>* tail;	//리스트의 끝지점
	Node<T>* cur;	//참조, 삭제를 돕는 멤버
	int numOfData;
	comp sortFunc;

	void InsertFirst(T idata);
	void InsertSort(T idata);
public:
	DBLinKedList();
	~DBLinKedList();

	bool isEmpty();
	int ListSize();
	void SetsortFunc(comp func);
	void InsertData(T indata);

	bool FirstNode(T* pdata);
	bool NextNode(T* pdata);
	void RemoveNode();
};





template<typename T>
inline DBLinKedList<T>::DBLinKedList() :head(new Node<T>), tail(new Node<T>), sortFunc(nullptr) { //head와 tail에 더미노드 생성
	head->next = tail;
	head->prev = nullptr;
							//head와 tail 서로 연결
	tail->next = nullptr;
	tail->prev = head;
}

template<typename T>
inline DBLinKedList<T>::~DBLinKedList() {
	T temp;

	if (FirstNode(&temp) == true) {
		RemoveNode();

		while (NextNode(&temp) == true)
			RemoveNode();
	}

	delete head;
	delete tail;
}

template<typename T>
inline bool DBLinKedList<T>::isEmpty() {
	if (head->next == tail)
		return true;
	else
		return false;
}

template<typename T>
inline int DBLinKedList<T>::ListSize() {
	return numOfData;
}

template<typename T>
inline void DBLinKedList<T>::SetsortFunc(comp func) {
	sortFunc = func;
}

template<typename T>
inline void DBLinKedList<T>::InsertData(T idata) {
	if (sortFunc == nullptr)
		InsertFirst(idata);
	else
		InsertSort(idata);
}

template<typename T>
inline bool DBLinKedList<T>::FirstNode(T* pdata) {
	if (isEmpty())
		return false;

	cur = head->next;	//연결리스트와 달리 cur만 사용
	*pdata = cur->data;
	return true;
}

template<typename T>
inline bool DBLinKedList<T>::NextNode(T* pdata) {
	if (cur->next == tail)	//다음 노드가 tail이면
		return false;			//false 반환

	cur = cur->next;
	*pdata = cur->data;	//pdata에 cur 노드의 데이터를 반환
	return true;
}

template<typename T>
inline void DBLinKedList<T>::RemoveNode() {
	Node<T>* rNode = cur;	//삭제한 노드를 저장할 포인터

	cur->prev->next = cur->next;	//cur 이전 노드의 다음주소를 cur 다음노드를 가리킴
	cur->next->prev = cur->prev;	//cur 다음 노드의 이전주소를 cur 이전노드를 가리킴
	cur = cur->prev;				//cur의 위치 재조정

	delete rNode;
	--numOfData;
}


template<typename T>
inline void DBLinKedList<T>::InsertFirst(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;

	newNode->next = head->next;	//newNode 다음 주소는 head 다음 노드를 가리키게 함
	head->next->prev = newNode;	//head 다음 노드의 이전 주소를 newNode를 가리키게 함

	newNode->prev = head;		//newNode의 이전 주소는 head를 가리키게 함
	head->next = newNode;		//head의 다음 주소는 newNode를 가리킴

	++numOfData;
}

template<typename T>
inline void DBLinKedList<T>::InsertSort(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;
	Node<T>* pred = head;

	while (pred->next != tail && sortFunc(pred->next->data, idata))	//pred의 다음노드가 tail이 아니면서 정렬함수가 true면 자기의 다음 노드를 가리킴
		pred = pred->next;

	newNode->next = pred->next;
	pred->next->prev = newNode;

	newNode->prev = pred;
	pred->next = newNode;

	++numOfData;
}