#pragma once
/*
���� Ʈ�� ADT

void Binary_Tree<T>::SetData(T indata)
- ��忡 indata �����͸� �����Ѵ�.

T Binary_Tree<T>::getData()
- ��忡 ����� �����͸� ��ȯ�Ѵ�.

void Binary_Tree<T>::MakeLeftSubTree(Binary_Tree<T>* sub)
- sub �Ű������� ���� ���� Ʈ���� �����Ѵ�.

void Binary_Tree<T>::MakeRightSubTree(Binary_Tree<T>* sub)
- sub �Ű������� ������ ���� Ʈ���� �����Ѵ�.

Binary_Tree<T>* Binary_Tree<T>::GetLeftSubTree()
- ���� ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.

Binary_Tree<T>* Binary_Tree<T>::GetRightSubTree()
- ������ ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.
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