#pragma once

#define NULL 0

template<typename T>
class Node //��ũ����Ʈ�� ����� ���
{
private:
	T data; //������ ������
	Node<T>* next; // ���� ���
public:
	void SetData(T pdata); //Set data
	void SetNextNode(Node<T>* nextNode); //Set next

	T ReturnData(); //return data
	Node<T>* ReturnNextNode(); //return next
};

template<typename T>
class LinkedList
{
private:
	Node<T>* head; //���̳���� ��������
	Node<T>* cur; //���� �� ������ ���� ���
	Node<T>* before; //������ ���� ���
	int numOfData; //������ ��
	bool (*comp)(T d1, T d2); //������ ������ �Ǵ� �Լ� ������
public:
	LinkedList(bool (*comp)(T d1, T d2) = nullptr); //�Ű����� �ʱ�ȭ ������

	void LInsert(T data); //����Ʈ�� �����͸� ���� (���� X)
	void SInsert(T data); //����Ʈ�� �����͸� ���� (���� O)

	bool LFirest(T* pdata); ///������ ���� �ʱ�ȭ�� ����, ����Ʈ�� ù��° �����͸� pdata�� ����, ������ true, ���н� false
	bool LNext(T* pdata); //������ ������ ����, ������ ���� �����Ͱ� pdata�� ����, ������ Treu, ���н� false

	T LRemove(); //������ ������ �����͸� ����, ������ �����ʹ� ��ȯ
	int LCount(); //����Ʈ�� ������ ���� ��ȯ
};





template<typename T>
inline void Node<T>::SetData(T pdata) {
	data = pdata;
}

template<typename T>
inline void Node<T>::SetNextNode(Node<T>* nextNode) {
	next = nextNode;
}

template<typename T>
inline T Node<T>::ReturnData() {
	return data;
}

template<typename T>
inline Node<T>* Node<T>::ReturnNextNode() {
	return next;
}





template<typename T>
inline LinkedList<T>::LinkedList(bool (*comp)(T d1, T d2))
	:head(new Node<T>), comp(comp), numOfData(NULL)
{
	head->SetNextNode(NULL);
}

template<typename T>
inline void LinkedList<T>::LInsert(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->SetData(data);

	newNode->SetNextNode(head->ReturnNextNode()); //newNode�� ���̳���� ������ ����
	head->SetNextNode(newNode); //���̳�� ������ newNode�� ����

	++numOfData;
}

template<typename T>
inline void LinkedList<T>::SInsert(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->SetData(data);
	Node<T>* pred = head;

	while (pred->ReturnNextNode() != NULL && comp(data, pred->ReturnNextNode()->ReturnData()) != false) {
		pred = pred->ReturnNextNode();
	}

	newNode->SetNextNode(pred->ReturnNextNode());
	pred->SetNextNode(newNode);

	++numOfData;
}

template<typename T>
inline bool LinkedList<T>::LFirest(T* pdata) { //ù ��ȸ ����
	if (head->ReturnNextNode() == NULL)
		return false;

	before = head; //before�� head(���� ���)�� ����Ŵ
	cur = head->ReturnNextNode(); //cur�� head(���� ���) ������ ����Ŵ

	*pdata = cur->ReturnData();
	return true;
}

template<typename T>
inline bool LinkedList<T>::LNext(T* pdata) { //���� ��ȸ ����
	if (cur->ReturnNextNode() == NULL)
		return false;

	before = cur; //before�� cur�� ����Ŵ
	cur = cur->ReturnNextNode(); //cur�� cur ������ ����Ŵ

	*pdata = cur->ReturnData();
	return true;
}

template<typename T>
inline T LinkedList<T>::LRemove() { //cur �κ��� �����ϰ� ������ ����
	Node<T>* rpos = cur;
	T rdata = rpos->ReturnData();

	before->SetNextNode(cur->ReturnNextNode());
	cur = before;

	delete[] rpos;
	--numOfData;
	return rdata;
}

template<typename T>
inline int LinkedList<T>::LCount() {
	return numOfData;
}