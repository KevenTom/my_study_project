#pragma once
/*
연결 리스트 기반 스택 ADT

bool Stack<T>::SIsEmpty()
- 스택이 비어있다면 false, 아니라면 true를 반환한다.

void Stack<T>::SPush(T indata)
- 스택에 indata값을 저장한다.

bool Stack<T>::SPop()
- 마지막에 저장된 노드를 삭제한다.
- 삭제될 경우 true를 반환한다.
- 비어있을경우 false를 반환한다.

T Stack<T>::SPeek()
- 마지막에 저장된 데이터를 반환한다.
- 스택이 비어있을경우 0을 반환한다.
*/

template<typename T>
class Node {
public:
	T data;
	Node* next;
};

template<typename T>
class Stack {
private:
	Node<T>* head;

public:
	Stack();
	~Stack();

	bool SIsEmpty();
	void SPush(T indata);
	bool SPop();
	T SPeek();
};

template<typename T>
inline Stack<T>::Stack() :head(nullptr) {}

template<typename T>
inline Stack<T>::~Stack() {
	Node<T>* rnode;

	while (!SIsEmpty()) {
		rnode = head;
		head = head->next;
		delete rnode;
	}
}

template<typename T>
inline bool Stack<T>::SIsEmpty() {
	if (head == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline void Stack<T>::SPush(T indata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = indata;

	newNode->next = head;	//newNode가 최근 노드를 가리킴
	head = newNode;			//head는 newNode를 가리킴
}

template<typename T>
inline bool Stack<T>::SPop() {
	if (SIsEmpty())
		return false;

	Node<T>* rnode;	//삭제할 노드

	rnode = head;	//삭제할 노드에 head를 저장
	head = head->next;	//head는 자기 다음 노드를 저장

	delete rnode;
	return true;
}

template<typename T>
inline T Stack<T>::SPeek() {
	if (SIsEmpty())
		return 0;

	return head->data;
}