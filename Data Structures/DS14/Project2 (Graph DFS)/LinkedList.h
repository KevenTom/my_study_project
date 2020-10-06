#pragma once

#define NULL 0

template<typename T>
class Node //링크리스트에 사용할 노드
{
private:
	T data; //노드안의 데이터
	Node<T>* next; // 다음 노드
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
	Node<T>* head; //더미노드의 시작지점
	Node<T>* cur; //참조 및 삭제를 돕는 멤버
	Node<T>* before; //삭제를 돕는 멤버
	int numOfData; //데이터 수
	bool (*comp)(T d1, T d2); //정렬의 기준이 되는 함수 포인터
public:
	LinkedList(); //매개변수 초기화 생성자

	void LInsert(T data); //정렬함수 유무에 따라 데이터를 저장
	void FInsert(T data); //LInsert와 연계
	void SInsert(T data); //LInsert와 연계

	bool LFirest(T* pdata); ///참조를 위한 초기화가 진행, 리스트의 첫번째 데이터를 pdata에 저장, 성공시 true, 실패시 false
	bool LNext(T* pdata); //참조의 다음을 진행, 참조된 다음 데이터가 pdata에 저장, 성공시 Treu, 실패시 false
	T LRemove(); //참조의 마지막 데이터를 삭제, 삭제된 데이터는 반환

	int LCount(); //리스트의 데이터 수를 반환
	void SetSortRule(bool (*comp2)(T d1, T d2)); //정렬 함수 추가
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
inline LinkedList<T>::LinkedList()
	:head(new Node<T>), comp(NULL), numOfData(NULL) 
{
	head->SetNextNode(NULL);
}

template<typename T>
inline void LinkedList<T>::LInsert(T data) {
	if (comp == NULL)
		FInsert(data); //정렬함수가 없다면 FInsert
	else
		SInsert(data); //정렬함수가 있다면 SInsert
}

template<typename T>
inline void LinkedList<T>::FInsert(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->SetData(data);

	newNode->SetNextNode(head->ReturnNextNode()); //newNode에 더미노드의 다음을 저장
	head->SetNextNode(newNode); //더미노드 다음을 newNode로 저장

	++numOfData;
}

template<typename T>
inline void LinkedList<T>::SInsert(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->SetData(data);
	Node<T>* pred = head;

	while (pred->ReturnNextNode() != NULL && comp(data, pred->ReturnNextNode()->ReturnData()) == true)
		pred = pred->ReturnNextNode(); //정렬함수가 false일 때까지 next

	newNode->SetNextNode(pred->ReturnNextNode()); //newNode에 pred의 다음노드를 저장
	pred->SetNextNode(newNode); //pred 다음을 newNode로 저장

	++numOfData;
}

template<typename T>
inline bool LinkedList<T>::LFirest(T* pdata) { //첫 조회 절차
	if (head->ReturnNextNode() == NULL)
		return false;
	
	before = head; //before는 head(더미 노드)를 가르킴
	cur = head->ReturnNextNode(); //cur는 head(더미 노드) 다음을 가르킴

	*pdata = cur->ReturnData();
	return true;
}

template<typename T>
inline bool LinkedList<T>::LNext(T* pdata) { //다음 조회 절차
	if (cur->ReturnNextNode() == NULL)
		return false;

	before = cur; //before는 cur를 가르킴
	cur = cur->ReturnNextNode(); //cur는 cur 다음을 가르킴

	*pdata = cur->ReturnData();
	return true;
}

template<typename T>
inline T LinkedList<T>::LRemove() { //cur 부분을 삭제하고 데이터 리턴
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

template<typename T>
inline void LinkedList<T>::SetSortRule(bool(*comp2)(T d1, T d2)) {
	comp = comp2;
}
