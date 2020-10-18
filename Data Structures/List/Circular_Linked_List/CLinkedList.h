#pragma once
/*
���� ���� ����Ʈ ADT

bool CLinKedList<T>::isEmpty()
- ����Ʈ�� ����ִٸ� false, �ƴ϶�� true�� ��ȯ�Ѵ�.

int CLinKedList<T>::ListSize()
- ����Ʈ�� ��� �� ��ŭ ��ȯ�Ѵ�.

void CLinKedList<T>::SetsortFunc(comp func)
- ����Ʈ�� ������ ������ �Ǵ� �Լ� �����͸� �����Ѵ�.
- comp �ڷ����� bool ��ȯ�� �Ű����� T, T�� ���� �Լ� �������� �ڷ����̴�.

void CLinKedList<T>::InsertData(T indata)
- ����Ʈ�� indata�� �����Ѵ�.
- ���� �Լ��� ������ �Լ� �������� �����͸� �����Ѵ�.
- ���� �Լ��� ������ ����Ʈ �� �տ� �����͸� �����Ѵ�.

inline void CLinKedList<T>::InsertTail(T indata)
- ����Ʈ�� indata�� ������ ���� �����Ѵ�. 

bool CLinKedList<T>::FirstNode(T* pdata)
- ����Ʈ�� ù ��° ��带 �����Ѵ�.
- ���� ���� �� false�� ��ȯ�Ѵ�.
- ���� ���� �� true�� ��ȯ�ϰ� pdata�� �����͸� �����Ѵ�.

bool CLinKedList<T>::NextNode(T* pdata)
- ������ ����� ���� ��带 �����Ѵ�.
- ���� ���� �� false�� ��ȯ�Ѵ�.
- ���� ���� �� true�� ��ȯ�ϰ� pdata�� �����͸� �����Ѵ�.

void CLinKedList<T>::RemoveNode()
- ������ ��带 �����Ѵ�.
*/

template<typename T>
class Node {	//���ø� ���
public:
	T data;
	Node* next;
};



template<typename T>
class CLinKedList {
private:
	using comp = bool(*)(T, T);	//�Լ� ������ Ÿ���� ��Ī

	Node<T>* tail;	//����Ʈ�� ������ ����
	Node<T>* cur;	//����, ������ ���� ���
	Node<T>* before;//����, ������ ���� ���
	int numOfData;		//��� ��
	comp sortFunc;	//�����Լ�

	void InsertFront(T indata);	 //�����Լ��� ������ ���
	void InsertSort(T indata);	 //�����Լ��� ������ ���
public:
	CLinKedList();
	~CLinKedList();

	bool isEmpty();
	int ListSize();
	void SetsortFunc(comp func);
	void InsertData(T indata);
	void InsertTail(T indata);

	bool FirstNode(T* pdata);
	bool NextNode(T* pdata);
	void RemoveNode();
};





template<typename T>
inline CLinKedList<T>::CLinKedList() :tail(nullptr), sortFunc(nullptr) {}

template<typename T>
inline CLinKedList<T>::~CLinKedList() {
	T temp;

	if (FirstNode(&temp) == true) {
		RemoveNode();

		while (NextNode(&temp) == true)
			RemoveNode();
	}

	delete tail;
}

template<typename T>
inline bool CLinKedList<T>::isEmpty() {
	if (tail == nullptr)
		return true;
	else
		return false;
}

template<typename T>
inline int CLinKedList<T>::ListSize() {
	return numOfData;
}

template<typename T>
inline void CLinKedList<T>::SetsortFunc(comp func) {
	sortFunc = func;
}

template<typename T>
inline void CLinKedList<T>::InsertData(T idata) {
	if (sortFunc == nullptr)	//�����Լ��� ���ٸ�
		InsertFront(idata);		//InsertFront �Լ����� ����
	else						//�����Լ��� �ִٸ�
		InsertSort(idata);		//InsertSort �Լ����� ����
}

template<typename T>
inline bool CLinKedList<T>::FirstNode(T* pdata) {
	if (isEmpty())		//��尡 ���ٸ�
		return false;	//false ��ȯ

	before = tail;
	cur = tail->next;

	*pdata = cur->data;	//pdata�� ù��° ����� �����͸� ��ȯ
	return true;
}

template<typename T>
inline bool CLinKedList<T>::NextNode(T* pdata) {
	if (isEmpty())		//��尡 ���ٸ�
		return false;	//false ��ȯ

	before = cur;
	cur = cur->next;

	*pdata = cur->data;	//pdata�� cur ����� �����͸� ��ȯ
	return true;
}

template<typename T>
inline void CLinKedList<T>::RemoveNode() {
	Node<T>* rNode;	//������ ��带 ������ ������
	rNode = cur;

	if (rNode == tail) { //������ ��尡 tail �̰�
		if (tail == tail->next)	//��尡 �ϳ����̶��
			tail = nullptr;		//tail�� nullptr�� ����
		else
			tail = before;		//�ƴ϶�� tail�� before�� ����Ŵ

	}

	before->next = cur->next;	//before ���� ��带 cur�� ���� ��带 ����Ű�� ��
	cur = before;				//cur�� before�� ����Ű�� ��

	delete rNode;
	--numOfData;
}


template<typename T>
inline void CLinKedList<T>::InsertFront(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;

	if (isEmpty()) {			//����Ʈ�� ����ִٸ�
		tail = newNode;			//tail�� newNode�� ����Ŵ
		newNode->next = newNode;//�����̴ϱ� ���� ���� �ڱ��ڽ��� ����Ŵ
	}
	else {
		newNode->next = tail->next;	//newNode�� ���� ��带 tail�� ���� ��带 ����Ű�� ��
		tail->next = newNode;		//tail ���� ��带 newNode�� ����Ű�� ��
	}

	++numOfData;
}

template<typename T>
inline void CLinKedList<T>::InsertSort(T idata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = idata;

	if (isEmpty()) {
		tail = newNode;
		newNode->next = newNode;
	}
	else {
		Node<T>* pred = tail;	//�����Լ� �������� ã�ư� ���

		if (sortFunc(pred->next->data, idata)) {	//�����Լ��� true�� ���� ��带 ����Ŵ
			pred = pred->next;	//ó���� pred�� tail�̱� ������ �̷��� ���� if�� ����

			while (sortFunc(pred->next->data, idata) && pred != tail)	//�����Լ��� true�̰� pred�� tail�� �ƴϸ� ������ ����Ŵ
				pred = pred->next;
		}

		newNode->next = pred->next;
		pred->next = newNode;

		if (sortFunc(tail->data, newNode->data)) //newNode�� tail �����̶�� tail�� newNode�� ����Ŵ
			tail = newNode;
	}

	++numOfData;
}

template<typename T>
inline void CLinKedList<T>::InsertTail(T indata) {
	Node<T>* newNode = new Node<T>;
	newNode->data = indata;

	if (isEmpty()) {			//����Ʈ�� ����ִٸ�
		tail = newNode;			//tail�� newNode�� ����Ŵ
		newNode->next = newNode;//�����̴ϱ� ���� ���� �ڱ��ڽ��� ����Ŵ
	}
	else {
		newNode->next = tail->next;	//newNode�� ���� ��带 tail�� ���� ��带 ����Ű�� ��
		tail->next = newNode;		//tail ���� ��带 newNode�� ����Ű�� ��
		tail = newNode;				//tail�� newNode�� ����Ŵ
	}

	++numOfData;
}