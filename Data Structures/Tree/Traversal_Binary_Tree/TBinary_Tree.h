#pragma once
/*
��ȸ ���� Ʈ�� ADT

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

void TBinary_Tree<T>::PreorderTraverse(comp action)
void TBinary_Tree<T>::InorderTraverse(comp action)
void TBinary_Tree<T>::PostorderTraverse(comp action)
- ���� ����, ����, ���� ��ȸ�� action �Լ� �����͸� �����Ѵ�.
- comp �ڷ����� �Ű����� T�� ���� void �Լ� ������ �ڷ����̴�.

void TBinary_Tree<T>::DeleteTree()
- ���� Ʈ���� ���� ��ȸ�� delete ���ش�.
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

	using comp = void(*)(T data);	//�Լ� ������ Ÿ�� ��Ī
	void PreorderTraverse(comp action);		//���� ��ȸ �Լ�
	void InorderTraverse(comp action);		//���� ��ȸ �Լ�
	void PostorderTraverse(comp action);	//���� ��ȸ �Լ�
	void DeleteTree();	//���� Ʈ�� ���� �Լ�
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
	if (this == nullptr)	//this�� �������͸� ����
		return;

	action(data);	//��Ʈ ��带 ����
	this->GetLeftSubTree()->PreorderTraverse(action);	//���� ���� Ʈ���� ���
	this->GetRightSubTree()->PreorderTraverse(action);	//������ ���� Ʈ���� ���
}

template<typename T>
inline void TBinary_Tree<T>::InorderTraverse(comp action) {
	if (this == nullptr)	//this�� �������͸� ����
		return;

	this->GetLeftSubTree()->InorderTraverse(action);	//���� ���� Ʈ���� ��͸� ����
	action(data);	//��Ʈ ��� ���
	this->GetRightSubTree()->InorderTraverse(action);	//������ ���� Ʈ���� ���
}

template<typename T>
inline void TBinary_Tree<T>::PostorderTraverse(comp action) {
	if (this == nullptr)	//this�� �������͸� ����
		return;

	this->GetLeftSubTree()->PostorderTraverse(action);	//���� ���� Ʈ���� ��͸� ����
	this->GetRightSubTree()->PostorderTraverse(action);	//������ ���� Ʈ���� ���
	action(data);	//��Ʈ ��� ���
}

template<typename T>
inline void TBinary_Tree<T>::DeleteTree() {
	if (this == nullptr)	//this�� �������͸� ����
		return;

	this->GetLeftSubTree()->DeleteTree();	//������ ��Ʈ��尡 �������� �Ҹ��ؾ� �ϱ� ������ ���� ��ȸ�� �Ҹ��� �����ؾ� �Ѵ�.
	this->GetRightSubTree()->DeleteTree();
	delete this;
}