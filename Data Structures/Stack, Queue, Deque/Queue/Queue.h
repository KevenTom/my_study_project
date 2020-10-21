#pragma once
/*
연결 리스트 기반 큐 ADT

bool Queue<T>::QIsEmpty()
- 큐가 비어있다면 false, 아니라면 true를 반환한다.

void Queue<T>::QPush(T indata)
- 큐에 indata값을 저장한다.

bool Queue<T>::QPop()
- 가장 먼저 저장된 노드를 삭제한다.
- 삭제될 경우 true를 반환한다.
- 비어있을경우 false를 반환한다.

T Queue<T>::QPeek()
- 가장 먼저 저장된 데이터를 반환한다.
- 큐가 비어있을경우 0을 반환한다.
*/

template<typename T>
class Node {
public:
	T data;
	Node* next;
};

template<typename T>
class Queue {
private:
	Node<T>* head;
	Node<T>* tail;

public:
	Queue();
	~Queue();

	bool QIsEmpty();
	void QPush(T indata);
	bool QPop();
	T QPeek();
};

template<typename T>
inline Queue<T>::Queue() :head(nullptr), tail(nullptr) {}

template<typename T>
inline Queue<T>::~Queue() { while (!QIsEmpty()) QPop(); }

template<typename T>
inline bool Queue<T>::QIsEmpty() {
	if (head == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline void Queue<T>::QPush(T indata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = indata;
	newNode->next = nullptr;

	if (QIsEmpty()) {	//큐가 비어어있다면
		head = newNode;	//head, tail이 newNode를 가리킴
		tail = newNode;
	}
	else {
		tail->next = newNode;	//tail 다음 노드를 newNode로 가리킴
		tail = newNode;			//tail이 newNode를 가리킴
	}
}

template<typename T>
inline bool Queue<T>::QPop() {
	if (QIsEmpty())
		return false;

	Node<T>* rnode;	//삭제할 노드

	rnode = head;	//삭제할 노드에 head를 저장
	head = head->next;	//head는 자기 다음 노드를 저장

	delete rnode;
	return true;
}

template<typename T>
inline T Queue<T>::QPeek() {
	if (QIsEmpty())
		return 0;

	return head->data;
}