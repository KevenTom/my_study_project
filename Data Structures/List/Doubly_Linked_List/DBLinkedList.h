#pragma once
/*
���Ḯ��Ʈ ADT

bool DBLinKedList<T>::isEmpty()
- ����Ʈ�� ����ִٸ� false, �ƴ϶�� true�� ��ȯ�Ѵ�.

int DBLinKedList<T>::ListSize()
- ����Ʈ�� ��� �� ��ŭ ��ȯ�Ѵ�.

void DBLinKedList<T>::SetsortFunc(comp func)
- ����Ʈ�� ������ ������ �Ǵ� �Լ� �����͸� �����Ѵ�.
- comp �ڷ����� bool ��ȯ�� �Ű����� T, T�� ���� �Լ� �������� �ڷ����̴�.

void DBLinKedList<T>::InsertData(T idata)
- ����Ʈ�� idata�� �����Ѵ�.
- ���� �Լ��� ������ �Լ� �������� �����͸� �����Ѵ�.
- ���� �Լ��� ������ ����Ʈ �� �տ� �����͸� �����Ѵ�.

bool DBLinKedList<T>::FirstNode(T* pdata)
- ����Ʈ�� ù ��° ��带 �����Ѵ�.
- ���� ���� �� false�� ��ȯ�Ѵ�.
- ���� ���� �� true�� ��ȯ�ϰ� pdata�� �����͸� �����Ѵ�.

bool DBLinKedList<T>::NextNode(T* pdata)
- ������ ����� ���� ��带 �����Ѵ�.
- ���� ���� �� false�� ��ȯ�Ѵ�.
- ���� ���� �� true�� ��ȯ�ϰ� pdata�� �����͸� �����Ѵ�.

void DBLinKedList<T>::RemoveNode()
- ������ ��带 �����Ѵ�.
*/

template<typename T>
class Node {	//����� ���
public:
	T data;
	Node* next;
	Node* prev;
};

template<typename T>
class DBLinKedList {
private:
	using comp = bool(*)(T, T);	//�Լ� ������ Ÿ���� ��Ī

	Node<T>* head;	//����Ʈ�� ��������
	Node<T>* tail;	//����Ʈ�� ������
	Node<T>* cur;	//����, ������ ���� ���
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
inline DBLinKedList<T>::DBLinKedList() :head(new Node<T>), tail(new Node<T>), sortFunc(nullptr) { //head�� tail�� ���̳�� ����
	head->next = tail;
	head->prev = nullptr;
							//head�� tail ���� ����
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

	cur = head->next;	//���Ḯ��Ʈ�� �޸� cur�� ���
	*pdata = cur->data;
	return true;
}

template<typename T>
inline bool DBLinKedList<T>::NextNode(T* pdata) {
	if (cur->next == tail)	//���� ��尡 tail�̸�
		return false;			//false ��ȯ

	cur = cur->next;
	*pdata = cur->data;	//pdata�� cur ����� �����͸� ��ȯ
	return true;
}

template<typename T>
inline void DBLinKedList<T>::RemoveNode() {
	Node<T>* rNode = cur;	//������ ��带 ������ ������

	cur->prev->next = cur->next;	//cur ���� ����� �����ּҸ� cur ������带 ����Ŵ
	cur->next->prev = cur->prev;	//cur ���� ����� �����ּҸ� cur ������带 ����Ŵ
	cur = cur->prev;				//cur�� ��ġ ������

	delete rNode;
	--numOfData;
}


template<typename T>
inline void DBLinKedList<T>::InsertFirst(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;

	newNode->next = head->next;	//newNode ���� �ּҴ� head ���� ��带 ����Ű�� ��
	head->next->prev = newNode;	//head ���� ����� ���� �ּҸ� newNode�� ����Ű�� ��

	newNode->prev = head;		//newNode�� ���� �ּҴ� head�� ����Ű�� ��
	head->next = newNode;		//head�� ���� �ּҴ� newNode�� ����Ŵ

	++numOfData;
}

template<typename T>
inline void DBLinKedList<T>::InsertSort(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;
	Node<T>* pred = head;

	while (pred->next != tail && sortFunc(pred->next->data, idata))	//pred�� ������尡 tail�� �ƴϸ鼭 �����Լ��� true�� �ڱ��� ���� ��带 ����Ŵ
		pred = pred->next;

	newNode->next = pred->next;
	pred->next->prev = newNode;

	newNode->prev = pred;
	pred->next = newNode;

	++numOfData;
}