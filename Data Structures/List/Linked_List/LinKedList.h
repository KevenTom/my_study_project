#pragma once
/*
연결 리스트 ADT

bool LinKedList<T>::isEmpty()
- 리스트가 비어있다면 false, 아니라면 true를 반환한다.

int LinKedList<T>::ListSize()
- 리스트의 노드 수 만큼 반환한다.

void LinKedList<T>::SetsortFunc(comp func)
- 리스트에 정렬의 기준이 되는 함수 포인터를 설정한다.
- comp 자료형은 bool 반환에 매개변수 T, T를 가진 함수 포인터의 자료형이다.

void LinKedList<T>::InsertData(T idata)
- 리스트에 idata를 저장한다.
- 정렬 함수가 있으면 함수 기준으로 데이터를 저장한다.
- 정렬 함수가 없으면 리스트 맨 앞에 데이터를 저장한다.

bool LinKedList<T>::FirstNode(T* pdata)
- 리스트의 첫 번째 노드를 참조한다.
- 참조 실패 시 false을 반환한다.
- 참조 성공 시 true를 반환하고 pdata에 데이터를 저장한다.

bool LinKedList<T>::NextNode(T* pdata)
- 참조된 노드의 다음 노드를 참조한다.
- 참조 실패 시 false을 반환한다.
- 참조 성공 시 true를 반환하고 pdata에 데이터를 저장한다.

void LinKedList<T>::RemoveNode()
- 참조된 노드를 삭제한다.
*/

template<typename T>
class Node {	//템플릿 노드
public:
	T data;
	Node* next;
};



template<typename T>
class LinKedList {
private:
	using comp = bool(*)(T, T);	//함수 포인터 타입의 별칭

	Node<T>* tail;	//리스트 마지막 지점
	Node<T>* cur;	//참조, 삭제를 돕는 멤버
	Node<T>* before;//참조, 삭제를 돕는 멤버
	int numOfData;	//노드 수
	comp sortFunc;	//정렬함수

	void InsertFirst(T idata);	 //정렬함수가 없을시 작동
	void InsertSort(T idata);	 //정렬함수가 있을시 작동
public:
	LinKedList();
	~LinKedList();

	bool isEmpty();
	int ListSize();
	void SetsortFunc(comp func);
	void InsertData(T indata);

	bool FirstNode(T* pdata);
	bool NextNode(T* pdata);
	void RemoveNode();
};





template<typename T>
inline LinKedList<T>::LinKedList() :head(new Node<T>), sortFunc(nullptr) {
	head->next = nullptr;
}

template<typename T>
inline LinKedList<T>::~LinKedList() {
	T temp;

	if (FirstNode(&temp) == true) {
		RemoveNode();

		while (NextNode(&temp) == true)
			RemoveNode();
	}

	delete head;
}

template<typename T>
inline bool LinKedList<T>::isEmpty() {
	if (head->next == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline int LinKedList<T>::ListSize() {
	return numOfData;
}

template<typename T>
inline void LinKedList<T>::SetsortFunc(comp func) {
	sortFunc = func;
}

template<typename T>
inline void LinKedList<T>::InsertData(T idata) {
	if (sortFunc == nullptr)	//정렬함수가 없다면
		InsertFirst(idata);		//InsertFirst 함수에서 진행
	else						//정렬함수가 있다면
		InsertSort(idata);		//InsertSort 함수에서 진행
}

template<typename T>
inline bool LinKedList<T>::FirstNode(T* pdata) {
	if (isEmpty())		//노드가 없다면
		return false;	//false 반환

	before = head;
	cur = before->next;

	*pdata = cur->data;	//pdata에 첫번째 노드의 데이터를 반환
	return true;
}

template<typename T>
inline bool LinKedList<T>::NextNode(T* pdata) {
	if (cur->next == nullptr)	//다음 노드가 없다면
		return false;			//false 반환

	before = cur;
	cur = cur->next;

	*pdata = cur->data;	//pdata에 cur 노드의 데이터를 반환
	return true;
}

template<typename T>
inline void LinKedList<T>::RemoveNode() {
	Node<T>* rNode;	//삭제한 노드를 저장할 포인터

	before->next = cur->next;	//before 다음 노드를 cur의 다음 노드를 가리키게 함
	rNode = cur;
	cur = before;				//cur은 before을 가리키게 함

	delete rNode;
	--numOfData;
}


template<typename T>
inline void LinKedList<T>::InsertFirst(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;

	newNode->next = head->next;	//새로운 노드의 다음 노드를 head의 다음 노드를 가리키게 함
	head->next = newNode;		//head 다음 노드를 새로운 노드를 가르키게 함

	++numOfData;
}

template<typename T>
inline void LinKedList<T>::InsertSort(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;
	Node<T>* pred = head;	//정렬함수 기준으로 찾아갈 노드

	while (pred->next != nullptr && sortFunc(pred->next->data, idata))	//정렬함수가 true면 다음을 가리킴
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;

	++numOfData;
}