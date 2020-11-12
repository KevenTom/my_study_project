#pragma once
#include"TBinary_Tree.h"	//���� ���� ��ȸ ���� Ʈ���� ���
/*
void BSearch_Tree<T>::BSTInsert(T insert)
- Ʈ���� insert �����͸� �����Ѵ�.

TBinary_Tree<T>* BSearch_Tree<T>::BSTSearch(T target)
- Ʈ���� target�� ã�´�. 
- Ʈ���� target�� �ִٸ� target ��� �ּҸ� ��ȯ, ���ٸ� nullptr ��ȯ

TBinary_Tree<T>* BSearch_Tree<T>::BSTRemove(T target)
- Ʈ���� target�� �����Ѵ�.
- Ʈ���� target�� �ִٸ� target ��� �ּҸ� ��ȯ, ���ٸ� nullptr ��ȯ

void BSearch_Tree<T>::BSTInorderTraverse(comp action)
- ���� ��ȸ�� action �Լ� �����͸� �����Ѵ�.
- comp �ڷ����� �Ű����� T�� ���� void �Լ� ������ �ڷ����̴�.
*/

template<typename T>
class BSearch_Tree {
private:
	TBinary_Tree<T>* BSTree;

public:
	BSearch_Tree();
	~BSearch_Tree();

	void BSTInsert(T insert);	//Ʈ���� ������ ����
	TBinary_Tree<T>* BSTSearch(T target);	//Ʈ���� target ��� ��ȯ, ������ nullptr ��ȯ
	TBinary_Tree<T>* BSTRemove(T target);	//Ʈ���� target ������ ����

	using comp = void(*)(T data);	//�Լ� ������ Ÿ�� ��Ī
	void BSTInorderTraverse(comp action);	//���� ��ȸ�� action �Լ� ������ ����
};

template<typename T>
inline BSearch_Tree<T>::BSearch_Tree() :BSTree(nullptr) {}

template<typename T>
inline BSearch_Tree<T>::~BSearch_Tree() {
	BSTree->DeleteTree();
}

template<typename T>
inline void BSearch_Tree<T>::BSTInsert(T data) {
	TBinary_Tree<T>* nNode = nullptr;	//���� ������ ���
	TBinary_Tree<T>* cNode = BSTree;	//������ ��ġ�� ã�ư��� ���� ������
	TBinary_Tree<T>* pNode = nullptr;	//cNode�� �� �ܰ� ������

	while (cNode != nullptr) {			//cNode�� ��ġ�� ã�������� �ݺ�
		if (cNode->getData() == data)	//���� Ž�� Ʈ���� ������(Ű)�� �ߺ��� ������� ����
			return;

		pNode = cNode;

		if (cNode->getData() > data)	//�� ��尡 cNode���� ������ ����, �ƴϸ� ������
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	nNode = new TBinary_Tree<T>;		//�� ��带 �����Ҵ�
	nNode->SetData(data);

	if (pNode != nullptr) {				//Pnode�� nullptr�� �ƴ϶��
		if (data < pNode->getData())	//�� ��尡 pNode���� ������ ����, �ƴϸ� ������
			pNode->MakeLeftSubTree(nNode);
		else
			pNode->MakeRightSubTree(nNode);
	}
	else {	//PNode�� ��Ʈ����� ��� BSTree�� �� ��带 ����
		BSTree = nNode;
	}
}

template<typename T>
inline TBinary_Tree<T>* BSearch_Tree<T>::BSTSearch(T target) {
	TBinary_Tree<T>* cNode = BSTree;	//Ž���� ��ġ�� ã�ư��� ���� ������
	T cd = cNode->getData();			//cNode�� ������

	while (cNode != nullptr) {	//cNode�� nullptr�� ã�������� �ݺ�
		cd = cNode->getData();

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	return nullptr;	//return�� �ȵƴٸ� Ž�� ����� ���ٴ� ���̴ϱ� nullptr�� ��ȯ
}

template<typename T>
inline TBinary_Tree<T>* BSearch_Tree<T>::BSTRemove(T target) {
	TBinary_Tree<T>* pVRoot = new TBinary_Tree<T>;	//��Ʈ��嵵 ������ �� �����ϱ� �ʿ��� ���� ��Ʈ ���
	TBinary_Tree<T>* pNode = pVRoot;				//������ ����� �θ� ���
	TBinary_Tree<T>* cNode = BSTree;				//������ ���
	TBinary_Tree<T>* dNode;							//������ ��带 ������ ������

	pVRoot->ChangeRightSubTree(BSTree);

	while (cNode != nullptr && cNode->getData() != target) {	//���� ��� ��带 Ž��
		pNode = cNode;

		if (target < cNode->getData())
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	if (cNode == nullptr)	//������ ��尡 ���ٸ� nullptr ��ȯ
		return nullptr;
	else					//�ִٸ� dNode = cNode
		dNode = cNode;

	//������ ��尡 �ܸ������ ���
	if (dNode->GetLeftSubTree() == nullptr &&
		dNode->GetRightSubTree() == nullptr) {
		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(nullptr);
		//pNode->MakeLeftSubTree(nullptr);
		else
			pNode->ChangeRightSubTree(nullptr);
			//pNode->MakeRightSubTree(nullptr);
	}
	//������ ��尡 �ڽ� ��� �ϳ��� ���
	else if (dNode->GetLeftSubTree() == nullptr ||
		dNode->GetRightSubTree() == nullptr) {
		TBinary_Tree<T>* dcNode; //������ ����� �ڽ� ���

		if (dNode->GetLeftSubTree() != nullptr)
			dcNode = dNode->GetLeftSubTree();
		else
			dcNode = dNode->GetRightSubTree();

		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(dcNode);
		else
			pNode->ChangeRightSubTree(dcNode);
	}
	//������ ��尡 ����Ʈ���� ���
	else {
		TBinary_Tree<T>* mNode = dNode->GetRightSubTree();	//������ ����� ��ü ���
		TBinary_Tree<T>* mpNode = dNode;					//��ü ����� �θ� ���
		T delData;											//������ ���

		while (mNode->GetLeftSubTree() != nullptr) {	//��ü ��带 ã�������� �ݺ�
			mpNode = mNode;
			mNode = mNode->GetLeftSubTree();
		}

		delData = dNode->getData();			//������ ��忡 ��ü ����� ���� �Է��ϱ� ���� ������ ���
		dNode->SetData(mNode->getData());	//������ ��忡 ��ü ����� ���� �Է�

		if (mpNode->GetLeftSubTree() == mNode)	//��ü ����� ������ ���� Ʈ���� ��ü ����� �θ� ���� ����
			mpNode->ChangeLeftSubTree(mNode->GetRightSubTree());
		else
			mpNode->ChangeRightSubTree(mNode->GetRightSubTree());

		dNode = mNode;	//mNode�� ��ü�� ���ϱ� dNode�� mNode�� ����
		dNode->SetData(delData);
	}

	if (pVRoot->GetRightSubTree() != BSTree)	//��Ʈ ��尡 ������ ��� �ٽ� ��������
		BSTree = pVRoot->GetRightSubTree();

	delete pVRoot;
	return dNode;
}

template<typename T>
inline void BSearch_Tree<T>::BSTInorderTraverse(comp action) {
	BSTree->InorderTraverse(action);
}