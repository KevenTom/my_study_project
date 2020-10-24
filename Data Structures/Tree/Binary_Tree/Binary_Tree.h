#pragma once
/*
이진 트리 ADT

void Binary_Tree<T>::SetData(T indata)
- 노드에 indata 데이터를 저장한다.

T Binary_Tree<T>::getData()
- 노드에 저장된 데이터를 반환한다.

void Binary_Tree<T>::MakeLeftSubTree(Binary_Tree<T>* sub)
- sub 매개변수를 왼쪽 서브 트리에 연결한다.

void Binary_Tree<T>::MakeRightSubTree(Binary_Tree<T>* sub)
- sub 매개변수를 오른쪽 서브 트리에 연결한다.

Binary_Tree<T>* Binary_Tree<T>::GetLeftSubTree()
- 왼쪽 서브 트리의 주소 값을 반환한다.

Binary_Tree<T>* Binary_Tree<T>::GetRightSubTree()
- 오른쪽 서브 트리의 주소 값을 반환한다.
*/

template<typename T>
class Binary_Tree
{
	T data;
	Binary_Tree* left;
	Binary_Tree* right;
public:
	Binary_Tree();


	void SetData(T indata);
	T getData();

	void MakeLeftSubTree(Binary_Tree<T>* sub);
	void MakeRightSubTree(Binary_Tree<T>* sub);
	Binary_Tree<T>* GetLeftSubTree();
	Binary_Tree<T>* GetRightSubTree();
};

template<typename T>
inline Binary_Tree<T>::Binary_Tree() :left(nullptr), right(nullptr) {}

template<typename T>
inline void Binary_Tree<T>::SetData(T indata) {
	data = indata;
}

template<typename T>
inline T Binary_Tree<T>::getData() {
	return data;
}

template<typename T>
inline void Binary_Tree<T>::MakeLeftSubTree(Binary_Tree<T>* sub) {
	if (left != nullptr)
		delete left;

	left = sub;
}

template<typename T>
inline void Binary_Tree<T>::MakeRightSubTree(Binary_Tree<T>* sub) {
	if (right != nullptr)
		delete right;

	right = sub;
}

template<typename T>
inline Binary_Tree<T>* Binary_Tree<T>::GetLeftSubTree() {
	return left;
}

template<typename T>
inline Binary_Tree<T>* Binary_Tree<T>::GetRightSubTree() {
	return right;
}