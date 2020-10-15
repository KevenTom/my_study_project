#pragma once
/*
���� ����Ʈ ADT

bool LinKedList<T>::isEmpty()
- ����Ʈ�� ����ִٸ� false, �ƴ϶�� true�� ��ȯ�Ѵ�.

int LinKedList<T>::ListSize()
- ����Ʈ�� ��� �� ��ŭ ��ȯ�Ѵ�.

void LinKedList<T>::SetsortFunc(comp func)
- ����Ʈ�� ������ ������ �Ǵ� �Լ� �����͸� �����Ѵ�.
- comp �ڷ����� bool ��ȯ�� �Ű����� T, T�� ���� �Լ� �������� �ڷ����̴�.

void LinKedList<T>::InsertData(T idata)
- ����Ʈ�� idata�� �����Ѵ�.
- ���� �Լ��� ������ �Լ� �������� �����͸� �����Ѵ�.
- ���� �Լ��� ������ ����Ʈ �� �տ� �����͸� �����Ѵ�.

bool LinKedList<T>::FirstNode(T* pdata)
- ����Ʈ�� ù ��° ��带 �����Ѵ�.
- ���� ���� �� false�� ��ȯ�Ѵ�.
- ���� ���� �� true�� ��ȯ�ϰ� pdata�� �����͸� �����Ѵ�.

bool LinKedList<T>::NextNode(T* pdata)
- ������ ����� ���� ��带 �����Ѵ�.
- ���� ���� �� false�� ��ȯ�Ѵ�.
- ���� ���� �� true�� ��ȯ�ϰ� pdata�� �����͸� �����Ѵ�.

void LinKedList<T>::RemoveNode()
- ������ ��带 �����Ѵ�.
*/

template<typename T>
class Node {	//���ø� ���
public:
	T data;
	Node* next;
};



template<typename T>
class LinKedList {
private:
	using comp = bool(*)(T, T);	//�Լ� ������ Ÿ���� ��Ī

	Node<T>* tail;	//����Ʈ ������ ����
	Node<T>* cur;	//����, ������ ���� ���
	Node<T>* before;//����, ������ ���� ���
	int numOfData;	//��� ��
	comp sortFunc;	//�����Լ�

	void InsertFirst(T idata);	 //�����Լ��� ������ �۵�
	void InsertSort(T idata);	 //�����Լ��� ������ �۵�
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
	if (sortFunc == nullptr)	//�����Լ��� ���ٸ�
		InsertFirst(idata);		//InsertFirst �Լ����� ����
	else						//�����Լ��� �ִٸ�
		InsertSort(idata);		//InsertSort �Լ����� ����
}

template<typename T>
inline bool LinKedList<T>::FirstNode(T* pdata) {
	if (isEmpty())		//��尡 ���ٸ�
		return false;	//false ��ȯ

	before = head;
	cur = before->next;

	*pdata = cur->data;	//pdata�� ù��° ����� �����͸� ��ȯ
	return true;
}

template<typename T>
inline bool LinKedList<T>::NextNode(T* pdata) {
	if (cur->next == nullptr)	//���� ��尡 ���ٸ�
		return false;			//false ��ȯ

	before = cur;
	cur = cur->next;

	*pdata = cur->data;	//pdata�� cur ����� �����͸� ��ȯ
	return true;
}

template<typename T>
inline void LinKedList<T>::RemoveNode() {
	Node<T>* rNode;	//������ ��带 ������ ������

	before->next = cur->next;	//before ���� ��带 cur�� ���� ��带 ����Ű�� ��
	rNode = cur;
	cur = before;				//cur�� before�� ����Ű�� ��

	delete rNode;
	--numOfData;
}


template<typename T>
inline void LinKedList<T>::InsertFirst(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;

	newNode->next = head->next;	//���ο� ����� ���� ��带 head�� ���� ��带 ����Ű�� ��
	head->next = newNode;		//head ���� ��带 ���ο� ��带 ����Ű�� ��

	++numOfData;
}

template<typename T>
inline void LinKedList<T>::InsertSort(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;
	Node<T>* pred = head;	//�����Լ� �������� ã�ư� ���

	while (pred->next != nullptr && sortFunc(pred->next->data, idata))	//�����Լ��� true�� ������ ����Ŵ
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;

	++numOfData;
}