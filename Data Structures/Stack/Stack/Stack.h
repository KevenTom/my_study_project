#pragma once
/*
���� ADT




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

	newNode->next = head;	//newNode�� �ֱ� ��带 ����Ŵ
	head = newNode;			//head�� newNode�� ����Ŵ
}

template<typename T>
inline bool Stack<T>::SPop() {
	if (SIsEmpty())
		return false;

	Node<T>* rnode;	//������ ���

	rnode = head;	//������ ��忡 head�� ����
	head = head->next;	//head�� �ڱ� ���� ��带 ����

	delete rnode;
	return true;
}

template<typename T>
inline T Stack<T>::SPeek() {
	if (SIsEmpty())
		return 0;

	return head->data;
}
