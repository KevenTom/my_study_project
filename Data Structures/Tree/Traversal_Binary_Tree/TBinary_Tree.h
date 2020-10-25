#pragma once
/*
순회 이진 트리 ADT

void TBinary_Tree<T>::SetData(T indata)
- 노드에 indata 데이터를 저장한다.

T TBinary_Tree<T>::getData()
- 노드에 저장된 데이터를 반환한다.

void TBinary_Tree<T>::MakeLeftSubTree(TBinary_Tree<T>* sub)
- sub 매개변수를 왼쪽 서브 트리에 연결한다.

void TBinary_Tree<T>::MakeRightSubTree(TBinary_Tree<T>* sub)
- sub 매개변수를 오른쪽 서브 트리에 연결한다.

TBinary_Tree<T>* TBinary_Tree<T>::GetLeftSubTree()
- 왼쪽 서브 트리의 주소 값을 반환한다.

TBinary_Tree<T>* TBinary_Tree<T>::GetRightSubTree()
- 오른쪽 서브 트리의 주소 값을 반환한다.

void TBinary_Tree<T>::PreorderTraverse(comp action)
void TBinary_Tree<T>::InorderTraverse(comp action)
void TBinary_Tree<T>::PostorderTraverse(comp action)
- 각각 전위, 중위, 후위 순회로 action 함수 포인터를 실행한다.
- comp 자료형은 매개변수 T를 가진 void 함수 포인터 자료형이다.

void TBinary_Tree<T>::DeleteTree()
- 이진 트리를 후위 순회로 delete 해준다.
*/

template<typename T>
class TBinary_Tree
{
	T data;
	TBinary_Tree* left;
	TBinary_Tree* right;
public:
	TBinary_Tree();

	void SetData(T indata);
	T getData();
	void MakeLeftSubTree(TBinary_Tree<T>* sub);
	void MakeRightSubTree(TBinary_Tree<T>* sub);
	TBinary_Tree<T>* GetLeftSubTree();
	TBinary_Tree<T>* GetRightSubTree();

	using comp = void(*)(T data);	//함수 포인터 타입 별칭
	void PreorderTraverse(comp action);		//전위 순회 함수
	void InorderTraverse(comp action);		//중위 순회 함수
	void PostorderTraverse(comp action);	//후위 순회 함수
	void DeleteTree();	//서브 트리 삭제 함수
};

template<typename T>
inline TBinary_Tree<T>::TBinary_Tree() :left(nullptr), right(nullptr) {}

template<typename T>
inline void TBinary_Tree<T>::SetData(T indata) {
	data = indata;
}

template<typename T>
inline T TBinary_Tree<T>::getData() {
	return data;
}

template<typename T>
inline void TBinary_Tree<T>::MakeLeftSubTree(TBinary_Tree<T>* sub) {
	if (left != nullptr)
		delete left;

	left = sub;
}

template<typename T>
inline void TBinary_Tree<T>::MakeRightSubTree(TBinary_Tree<T>* sub) {
	if (right != nullptr)
		delete right;

	right = sub;
}

template<typename T>
inline TBinary_Tree<T>* TBinary_Tree<T>::GetLeftSubTree() {
	return left;
}

template<typename T>
inline TBinary_Tree<T>* TBinary_Tree<T>::GetRightSubTree() {
	return right;
}

template<typename T>
inline void TBinary_Tree<T>::PreorderTraverse(comp action) {
	if (this == nullptr)	//this가 널포인터면 리턴
		return;

	action(data);	//루트 노드를 먼저
	this->GetLeftSubTree()->PreorderTraverse(action);	//왼쪽 서브 트리를 재귀
	this->GetRightSubTree()->PreorderTraverse(action);	//오른쪽 서브 트리를 재귀
}

template<typename T>
inline void TBinary_Tree<T>::InorderTraverse(comp action) {
	if (this == nullptr)	//this가 널포인터면 리턴
		return;

	this->GetLeftSubTree()->InorderTraverse(action);	//왼쪽 서브 트리를 재귀를 먼저
	action(data);	//루트 노드 사용
	this->GetRightSubTree()->InorderTraverse(action);	//오른쪽 서브 트리를 재귀
}

template<typename T>
inline void TBinary_Tree<T>::PostorderTraverse(comp action) {
	if (this == nullptr)	//this가 널포인터면 리턴
		return;

	this->GetLeftSubTree()->PostorderTraverse(action);	//왼쪽 서브 트리를 재귀를 먼저
	this->GetRightSubTree()->PostorderTraverse(action);	//오른쪽 서브 트리를 재귀
	action(data);	//루트 노드 사용
}

template<typename T>
inline void TBinary_Tree<T>::DeleteTree() {
	if (this == nullptr)	//this가 널포인터면 리턴
		return;

	this->GetLeftSubTree()->DeleteTree();	//삭제는 루트노드가 마지막에 소멸해야 하기 때문에 후위 순회로 소멸을 진행해야 한다.
	this->GetRightSubTree()->DeleteTree();
	delete this;
}