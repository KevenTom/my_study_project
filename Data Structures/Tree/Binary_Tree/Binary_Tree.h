#pragma once
/*
이진 트리 ADT

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