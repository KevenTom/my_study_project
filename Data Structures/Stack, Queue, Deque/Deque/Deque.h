#pragma once
/*
연결 리스트 기반 덱 ADT

bool Deque<T>::DQIsEmpty()
- 덱이 비어있다면 false, 아니라면 true를 반환한다.

void Deque<T>::DQFirstPush(T indata)
- 덱에 indata값을 첫 번째 노드로 저장한다.

void Deque<T>::DQLastPush(T indata)
- 덱에 indata값을 마지막 노드로 저장한다.

bool Deque<T>::DQFirstPop()
- 첫 번째 노드를 삭제한다.
- 삭제될 경우 true를 반환한다.
- 비어있을 경우 false를 반환한다.

bool Deque<T>::DQLastPop()
- 마지막 노드를 삭제한다.
- 삭제될 경우 true를 반환한다.
- 비어있을 경우 false를 반환한다.

T Deque<T>::DQFirstPeek()
- 첫 번째 노드의 데이터를 반환한다.
- 덱이 비어있을 경우 0을 반환한다.

T Deque<T>::DQLastPeek()
- 마지막 노드의 데이터를 반환한다.
- 덱이 비어있을 경우 0을 반환한다.
*/

template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;
};

template<typename T>
class Deque {
private:
	Node<T>* head;
	Node<T>* tail;

public:
	Deque();
	~Deque();

	bool DQIsEmpty();
	void DQFirstPush(T indata);
	void DQLastPush(T indata);
	bool DQFirstPop();
	bool DQLastPop();
	T DQFirstPeek();
	T DQLastPeek();
};

template<typename T>
inline Deque<T>::Deque() :head(nullptr), tail(nullptr) {}

template<typename T>
inline Deque<T>::~Deque() { while (!DQIsEmpty()) DQFirstPop(); }

template<typename T>
inline bool Deque<T>::DQIsEmpty() {
	if (head == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline void Deque<T>::DQFirstPush(T indata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = indata;
	newNode->next = head;	//newNode 다음을 head로 설정

	if (DQIsEmpty())
		tail = newNode;		//덱이 비어있다면 tail이 newNode를 가리킴
	else
		head->prev = newNode;//아니라면 head의 전 노드로 newNode를 가리킴

	newNode->prev = nullptr;	//newNode의 이전 노드를 nullptr로 설정
	head = newNode;				//head가 newNode를 가리킴
}

template<typename T>
inline void Deque<T>::DQLastPush(T indata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = indata;
	newNode->prev = tail;	//newNode 이전을 tail로 설정

	if (DQIsEmpty())
		head = newNode;		//덱이 비어있다면 head가 newNode를 가리킴
	else
		tail->next = newNode;//아니라면 tail의 다음 노드로 newNode로 가리킴

	newNode->next = nullptr;	//newNode의 다음 노드를 nullptr로 설정
	tail = newNode;				//tail이 newNode를 가리킴
}

template<typename T>
inline bool Deque<T>::DQFirstPop() {
	if (DQIsEmpty())
		return false;

	Node<T>* rnode;		//삭제할 노드
	rnode = head;		//삭제할 노드에 head를 저장
	head = head->next;	//head는 자기 다음 노드를 저장

	if (head == nullptr)	//head가 nullptr이면
		tail = nullptr;		//tail도 nullptr로 만듬
	else
		head->prev = nullptr;//아니라면 head의 전 노드를 nullptr로 만듬

	delete rnode;
	return true;
}

template<typename T>
inline bool Deque<T>::DQLastPop() {
	if (DQIsEmpty())
		return false;

	Node<T>* rnode;		//삭제할 노드
	rnode = tail;		//삭제할 노드에 tail을 저장
	tail = tail->prev;	//tail은 자기 전 노드를 저장

	if (tail == nullptr)	//tail가 nullptr이면
		head = nullptr;		//head도 nullptr로 만듬
	else
		tail->next = nullptr;//아니라면 tail의 다음 노드를 nullptr로 만듬

	delete rnode;
	return true;
}

template<typename T>
inline T Deque<T>::DQFirstPeek() {
	if (DQIsEmpty())
		return 0;

	return head->data;
}

template<typename T>
inline T Deque<T>::DQLastPeek() {
	if (DQIsEmpty())
		return 0;

	return tail->data;
}