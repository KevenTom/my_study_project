#pragma once
/*
���� Ʈ�� ADT

void TBinary_Tree<T>::SetData(T indata)
- ��忡 indata �����͸� �����Ѵ�.

T TBinary_Tree<T>::getData()
- ��忡 ����� �����͸� ��ȯ�Ѵ�.

void TBinary_Tree<T>::MakeLeftSubTree(TBinary_Tree<T>* sub)
- sub �Ű������� ���� ���� Ʈ���� �����Ѵ�.

void TBinary_Tree<T>::MakeRightSubTree(TBinary_Tree<T>* sub)
- sub �Ű������� ������ ���� Ʈ���� �����Ѵ�.

TBinary_Tree<T>* TBinary_Tree<T>::GetLeftSubTree()
- ���� ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.

TBinary_Tree<T>* TBinary_Tree<T>::GetRightSubTree()
- ������ ���� Ʈ���� �ּ� ���� ��ȯ�Ѵ�.
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