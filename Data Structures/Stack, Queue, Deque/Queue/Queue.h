#pragma once
/*
���� ����Ʈ ��� ť ADT

bool Queue<T>::QIsEmpty()
- ť�� ����ִٸ� false, �ƴ϶�� true�� ��ȯ�Ѵ�.

void Queue<T>::QPush(T indata)
- ť�� indata���� �����Ѵ�.

bool Queue<T>::QPop()
- ���� ���� ����� ��带 �����Ѵ�.
- ������ ��� true�� ��ȯ�Ѵ�.
- ���������� false�� ��ȯ�Ѵ�.

T Queue<T>::QPeek()
- ���� ���� ����� �����͸� ��ȯ�Ѵ�.
- ť�� ���������� 0�� ��ȯ�Ѵ�.
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

	if (QIsEmpty()) {	//ť�� �����ִٸ�
		head = newNode;	//head, tail�� newNode�� ����Ŵ
		tail = newNode;
	}
	else {
		tail->next = newNode;	//tail ���� ��带 newNode�� ����Ŵ
		tail = newNode;			//tail�� newNode�� ����Ŵ
	}
}

template<typename T>
inline bool Queue<T>::QPop() {
	if (QIsEmpty())
		return false;

	Node<T>* rnode;	//������ ���

	rnode = head;	//������ ��忡 head�� ����
	head = head->next;	//head�� �ڱ� ���� ��带 ����

	delete rnode;
	return true;
}

template<typename T>
inline T Queue<T>::QPeek() {
	if (QIsEmpty())
		return 0;

	return head->data;
}