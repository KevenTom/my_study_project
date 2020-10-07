#pragma once

using comp = bool(*)(int, int); //���� �Լ� ������ Ÿ�� ��Ī ����

template<typename T>
class Node //����Ʈ�� ����� ���
{
private:
	T data; //������
	Node<T>* next; // ���� ���
public:
	void SetData(T pdata); //Set data
	void SetNextNode(Node<T>* nextNode); //Set next

	T OutputData(); //return data
	Node<T>* OutputNextNode(); //return next
};

template<typename T>
class LinkedList
{
private:
	Node<T>* head; //���̳���� ��������
	Node<T>* cur; //����, ������ ���� ���
	Node<T>* before; //����, ������ ���� ���
	int numOfData; //������ ��
	comp sortFunction; //������ ������ �Ǵ� �Լ� ������
public:
	LinkedList(); //������

	void LInsert(T data); //�����Լ� ������ ���� �����Լ��� ȣ��
	void FInsert(T data); //ù��° ��忡 data ����
	void SInsert(T data); //�����Լ��� �ٰŷ� data ����

	bool LFirest(T* pdata); ///������ ���� �ʱ�ȭ�� ���� (ù��° �����͸� pdata�� ����, ������ true, ���н� false)
	bool LNext(T* pdata); //������ ������ ���� (������ ���� �����Ͱ� pdata�� ����, ������ Treu, ���н� false)
	T LRemove(); //������ ������ ��带 ����, ������ �����ʹ� ��ȯ

	int LCount(); //����Ʈ�� ��� �� ��ȯ
	void SetSortRule(comp fp); //���� �Լ� �߰�
};





template<typename T>
inline LinkedList<T>::LinkedList() //�Ű����� �ʱ�ȭ ������
	:head(new Node<T>), sortFunction(nullptr), numOfData(0) {
	head->SetNextNode(nullptr);
}

template<typename T>
inline void LinkedList<T>::LInsert(T data) {
	if (sortFunction == nullptr)
		FInsert(data); //�����Լ��� ���ٸ� FInsert
	else
		SInsert(data); //�����Լ��� �ִٸ� SInsert
}

template<typename T>
inline void LinkedList<T>::FInsert(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->SetData(data);

	newNode->SetNextNode(head->OutputNextNode()); //newNode�� ���̳���� ������ ����
	head->SetNextNode(newNode); //���̳�� ������ newNode�� ����

	++numOfData;
}

template<typename T>
inline void LinkedList<T>::SInsert(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->SetData(data);
	Node<T>* pred = head;

	while (pred->OutputNextNode() != nullptr && sortFunction(data, pred->OutputNextNode()->OutputData()) == true)
		pred = pred->OutputNextNode(); //�����Լ��� false�� ������ next

	newNode->SetNextNode(pred->OutputNextNode()); //newNode�� pred�� ������带 ����
	pred->SetNextNode(newNode); //pred ������ newNode�� ����

	++numOfData;
}

template<typename T>
inline bool LinkedList<T>::LFirest(T* pdata) { //ù ��ȸ ����
	if (head->OutputNextNode() == nullptr)
		return false;
	
	before = head; //before�� head(���� ���)�� ����Ŵ
	cur = head->OutputNextNode(); //cur�� head(���� ���) ������ ����Ŵ

	*pdata = cur->OutputData();
	return true;
}

template<typename T>
inline bool LinkedList<T>::LNext(T* pdata) { //���� ��ȸ ����
	if (cur->OutputNextNode() == nullptr)
		return false;

	before = cur; //before�� cur�� ����Ŵ
	cur = cur->OutputNextNode(); //cur�� cur ������ ����Ŵ

	*pdata = cur->OutputData();
	return true;
}

template<typename T>
inline T LinkedList<T>::LRemove() { //cur �κ��� �����ϰ� data ����
	Node<T>* rpos = cur;
	T rdata = rpos->OutputData();

	before->SetNextNode(cur->OutputNextNode());
	cur = before;

	delete[] rpos;
	--numOfData;
	return rdata;
}

template<typename T>
inline int LinkedList<T>::LCount() {
	return numOfData;
}

template<typename T>
inline void LinkedList<T>::SetSortRule(comp fp) {
	sortFunction = fp;
}





template<typename T>
inline void Node<T>::SetData(T pdata) {
	data = pdata;
}

template<typename T>
inline void Node<T>::SetNextNode(Node<T>* nextNode) {
	next = nextNode;
}

template<typename T>
inline T Node<T>::OutputData() {
	return data;
}

template<typename T>
inline Node<T>* Node<T>::OutputNextNode() {
	return next;
}