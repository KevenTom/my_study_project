#pragma once


template<typename T>
class Node {
public:
	T data;
	Node* next;
};





template<typename T>
class DLinKedList {
private:
	using comp = bool(*)(T, T);

	Node<T>* head;
	Node<T>* cur;
	Node<T>* before;
	int count;
	comp sortFunc;

	void InsertFirst(T idata);
	void InsertSort(T idata);
public:
	DLinKedList();
	~DLinKedList();

	bool isEmpty();
	int ListSize();
	void SetsortFunc(comp func);
	void InsertData(T idata);


	Node<T>* FirstNode();
	Node<T>* NextNode();
	void RemoveNode();
};





template<typename T>
inline DLinKedList<T>::DLinKedList() :head(new Node<T>->next = nullptr), sortFunc(nullptr) {
	head->next = nullptr;
}

template<typename T>
inline DLinKedList<T>::~DLinKedList() {
	if (FirstNode() != nullptr) {
		RemoveNode();

		while (NextNode() != nullptr)
			RemoveNode();
	}

	delete head;
}

template<typename T>
inline bool DLinKedList<T>::isEmpty() {
	if (head->next == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline int DLinKedList<T>::ListSize() {
	return count;
}

template<typename T>
inline void DLinKedList<T>::SetsortFunc(comp func) {
	sortFunc = func;
}

template<typename T>
inline void DLinKedList<T>::InsertData(T idata) {
	if (sortFunc == nullptr)
		InsertFirst(idata);
	else
		InsertSort(idata);
}


template<typename T>
inline Node<T>* DLinKedList<T>::FirstNode() {
	if (isEmpty())
		return nullptr;

	before = head;
	cur = before->next;

	return cur;
}

template<typename T>
inline Node<T>* DLinKedList<T>::NextNode() {
	if (cur->next == nullptr)
		return nullptr;

	before = cur;
	cur = cur->next;

	return cur;
}

template<typename T>
inline void DLinKedList<T>::RemoveNode() {
	Node<T>* rNode;

	before->next = cur->next;
	rNode = cur;
	cur = before;

	delete rNode;
	--count;
}





template<typename T>
inline void DLinKedList<T>::InsertFirst(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;

	newNode->next = head->next;
	head->next = newNode;

	++count;
}

template<typename T>
inline void DLinKedList<T>::InsertSort(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;
	Node<T>* pred = head;

	while (pred->next != nullptr && sortFunc(idata, pred->next->data))
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;

	++count;
}
