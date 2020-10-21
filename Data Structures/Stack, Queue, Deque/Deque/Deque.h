#pragma once
/*
���� ����Ʈ ��� �� ADT

bool Deque<T>::DQIsEmpty()
- ���� ����ִٸ� false, �ƴ϶�� true�� ��ȯ�Ѵ�.

void Deque<T>::DQFirstPush(T indata)
- ���� indata���� ù ��° ���� �����Ѵ�.

void Deque<T>::DQLastPush(T indata)
- ���� indata���� ������ ���� �����Ѵ�.

bool Deque<T>::DQFirstPop()
- ù ��° ��带 �����Ѵ�.
- ������ ��� true�� ��ȯ�Ѵ�.
- ������� ��� false�� ��ȯ�Ѵ�.

bool Deque<T>::DQLastPop()
- ������ ��带 �����Ѵ�.
- ������ ��� true�� ��ȯ�Ѵ�.
- ������� ��� false�� ��ȯ�Ѵ�.

T Deque<T>::DQFirstPeek()
- ù ��° ����� �����͸� ��ȯ�Ѵ�.
- ���� ������� ��� 0�� ��ȯ�Ѵ�.

T Deque<T>::DQLastPeek()
- ������ ����� �����͸� ��ȯ�Ѵ�.
- ���� ������� ��� 0�� ��ȯ�Ѵ�.
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
	newNode->next = head;	//newNode ������ head�� ����

	if (DQIsEmpty())
		tail = newNode;		//���� ����ִٸ� tail�� newNode�� ����Ŵ
	else
		head->prev = newNode;//�ƴ϶�� head�� �� ���� newNode�� ����Ŵ

	newNode->prev = nullptr;	//newNode�� ���� ��带 nullptr�� ����
	head = newNode;				//head�� newNode�� ����Ŵ
}

template<typename T>
inline void Deque<T>::DQLastPush(T indata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = indata;
	newNode->prev = tail;	//newNode ������ tail�� ����

	if (DQIsEmpty())
		head = newNode;		//���� ����ִٸ� head�� newNode�� ����Ŵ
	else
		tail->next = newNode;//�ƴ϶�� tail�� ���� ���� newNode�� ����Ŵ

	newNode->next = nullptr;	//newNode�� ���� ��带 nullptr�� ����
	tail = newNode;				//tail�� newNode�� ����Ŵ
}

template<typename T>
inline bool Deque<T>::DQFirstPop() {
	if (DQIsEmpty())
		return false;

	Node<T>* rnode;		//������ ���
	rnode = head;		//������ ��忡 head�� ����
	head = head->next;	//head�� �ڱ� ���� ��带 ����

	if (head == nullptr)	//head�� nullptr�̸�
		tail = nullptr;		//tail�� nullptr�� ����
	else
		head->prev = nullptr;//�ƴ϶�� head�� �� ��带 nullptr�� ����

	delete rnode;
	return true;
}

template<typename T>
inline bool Deque<T>::DQLastPop() {
	if (DQIsEmpty())
		return false;

	Node<T>* rnode;		//������ ���
	rnode = tail;		//������ ��忡 tail�� ����
	tail = tail->prev;	//tail�� �ڱ� �� ��带 ����

	if (tail == nullptr)	//tail�� nullptr�̸�
		head = nullptr;		//head�� nullptr�� ����
	else
		tail->next = nullptr;//�ƴ϶�� tail�� ���� ��带 nullptr�� ����

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