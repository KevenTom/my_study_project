#pragma once

using comp = bool(*)(int, int); //정렬 함수 포인터 타입 별칭 정의

template<typename T>
class Node //리스트에 사용할 노드
{
private:
	T data; //데이터
	Node<T>* next; // 다음 노드
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
	Node<T>* head; //더미노드의 시작지점
	Node<T>* cur; //참조, 삭제를 돕는 멤버
	Node<T>* before; //참조, 삭제를 돕는 멤버
	int numOfData; //데이터 수
	comp sortFunction; //정렬의 기준이 되는 함수 포인터
public:
	LinkedList(); //생성자

	void LInsert(T data); //정렬함수 유무에 따라 저장함수를 호출
	void FInsert(T data); //첫번째 노드에 data 저장
	void SInsert(T data); //정렬함수를 근거로 data 저장

	bool LFirest(T* pdata); ///참조를 위한 초기화가 진행 (첫번째 데이터를 pdata에 저장, 성공시 true, 실패시 false)
	bool LNext(T* pdata); //참조의 다음을 진행 (참조된 다음 데이터가 pdata에 저장, 성공시 Treu, 실패시 false)
	T LRemove(); //참조된 마지막 노드를 삭제, 삭제된 데이터는 반환

	int LCount(); //리스트의 노드 수 반환
	void SetSortRule(comp fp); //정렬 함수 추가
};





template<typename T>
inline LinkedList<T>::LinkedList() //매개변수 초기화 생성자
	:head(new Node<T>), sortFunction(nullptr), numOfData(0) {
	head->SetNextNode(nullptr);
}

template<typename T>
inline void LinkedList<T>::LInsert(T data) {
	if (sortFunction == nullptr)
		FInsert(data); //정렬함수가 없다면 FInsert
	else
		SInsert(data); //정렬함수가 있다면 SInsert
}

template<typename T>
inline void LinkedList<T>::FInsert(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->SetData(data);

	newNode->SetNextNode(head->OutputNextNode()); //newNode에 더미노드의 다음을 저장
	head->SetNextNode(newNode); //더미노드 다음을 newNode로 저장

	++numOfData;
}

template<typename T>
inline void LinkedList<T>::SInsert(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->SetData(data);
	Node<T>* pred = head;

	while (pred->OutputNextNode() != nullptr && sortFunction(data, pred->OutputNextNode()->OutputData()) == true)
		pred = pred->OutputNextNode(); //정렬함수가 false일 때까지 next

	newNode->SetNextNode(pred->OutputNextNode()); //newNode에 pred의 다음노드를 저장
	pred->SetNextNode(newNode); //pred 다음을 newNode로 저장

	++numOfData;
}

template<typename T>
inline bool LinkedList<T>::LFirest(T* pdata) { //첫 조회 절차
	if (head->OutputNextNode() == nullptr)
		return false;
	
	before = head; //before는 head(더미 노드)를 가르킴
	cur = head->OutputNextNode(); //cur는 head(더미 노드) 다음을 가르킴

	*pdata = cur->OutputData();
	return true;
}

template<typename T>
inline bool LinkedList<T>::LNext(T* pdata) { //다음 조회 절차
	if (cur->OutputNextNode() == nullptr)
		return false;

	before = cur; //before는 cur를 가르킴
	cur = cur->OutputNextNode(); //cur는 cur 다음을 가르킴

	*pdata = cur->OutputData();
	return true;
}

template<typename T>
inline T LinkedList<T>::LRemove() { //cur 부분을 삭제하고 data 리턴
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