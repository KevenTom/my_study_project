#pragma once
#include"TBinary_Tree.h"	//���� ���� ��ȸ ���� Ʈ���� ���
/*
void AVL_Tree<T>::BSTInsert(T insert)
- Ʈ���� insert �����͸� �����Ѵ�.

TBinary_Tree<T>* AVL_Tree<T>::BSTSearch(T target)
- Ʈ���� target�� ã�´�. 
- Ʈ���� target�� �ִٸ� target ��� �ּҸ� ��ȯ, ���ٸ� nullptr ��ȯ

TBinary_Tree<T>* AVL_Tree<T>::BSTRemove(T target)
- Ʈ���� target�� �����Ѵ�.
- Ʈ���� target�� �ִٸ� target ��� �ּҸ� ��ȯ, ���ٸ� nullptr ��ȯ

void AVL_Tree<T>::BSTInorderTraverse(comp action)
- ���� ��ȸ�� action �Լ� �����͸� �����Ѵ�.
- comp �ڷ����� �Ű����� T�� ���� void �Լ� ������ �ڷ����̴�.
*/

template<typename T>
class AVL_Tree {
private:
	TBinary_Tree<T>* BSTree;

	int GetHeight(TBinary_Tree<T>* bst);		//Ʈ���� ��� ��� �� ���� ���� ���̸� ��ȯ
	int GetHeightDiff(TBinary_Tree<T>* bst);	//����, ������ ���� Ʈ���� ���� �μ��� ��ȯ
	TBinary_Tree<T>* RotateLL(TBinary_Tree<T>* bst);	//LLȸ��
	TBinary_Tree<T>* RotateRR(TBinary_Tree<T>* bst);	//RRȸ��
	TBinary_Tree<T>* RotateLR(TBinary_Tree<T>* bst);	//LRȸ��
	TBinary_Tree<T>* RotateRL(TBinary_Tree<T>* bst);	//RLȸ��
	void Rebalance();									//���뷱�� üũ
public:
	AVL_Tree();
	~AVL_Tree();

	TBinary_Tree<T>* BSTRoot();
	void BSTInsert(T insert);
	TBinary_Tree<T>* BSTSearch(T target);
	TBinary_Tree<T>* BSTRemove(T target);

	using comp = void(*)(T data);
	void BSTInorderTraverse(comp action);
};




template<typename T>
inline int AVL_Tree<T>::GetHeight(TBinary_Tree<T>* bst) {
	if (bst == nullptr)
		return 0;

	int leftH = GetHeight(bst->GetLeftSubTree());
	int rightH = GetHeight(bst->GetRightSubTree());

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

template<typename T>
inline int AVL_Tree<T>::GetHeightDiff(TBinary_Tree<T>* bst) {
	if (bst == nullptr)
		return 0;

	int lsh = GetHeight(bst->GetLeftSubTree());
	int reh = GetHeight(bst->GetRightSubTree());

	return lsh - reh;
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::RotateLL(TBinary_Tree<T>* bst) {
	TBinary_Tree<T>* pNode = bst;						//ȸ���� ����� ������
	TBinary_Tree<T>* cNode = pNode->GetLeftSubTree();	//���뷱���� ����� ������

	pNode->ChangeLeftSubTree(cNode->GetRightSubTree());	//ȸ���� ����� ���� ��带 ���뷱���� ����� ������ ���� ��ü
	cNode->ChangeRightSubTree(pNode);	//���뷱���� ����� ������ ��带 ȸ���� ���� ��ü

	return cNode;
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::RotateRR(TBinary_Tree<T>* bst) {
	TBinary_Tree<T>* pNode = bst;						//ȸ���� ����� ������
	TBinary_Tree<T>* cNode = pNode->GetRightSubTree();	//���뷱���� ����� ������

	pNode->ChangeRightSubTree(cNode->GetLeftSubTree());	//ȸ���� ����� ������ ��带 ���뷱���� ����� ���� ���� ��ü
	cNode->ChangeLeftSubTree(pNode);	//���뷱���� ����� ���� ��带 ȸ���� ���� ��ü

	return cNode;
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::RotateLR(TBinary_Tree<T>* bst) {
	TBinary_Tree<T>* pNode = bst;						//ȸ���� ����� ������
	TBinary_Tree<T>* cNode = pNode->GetLeftSubTree();	//���뷱���� ����� ������

	pNode->ChangeLeftSubTree(RotateRR(cNode));	//���뷱���� ��带 RRȸ�� �� �� ȸ���� ����� ���� ��带 ���뷱���� ���� ��ü

	return RotateLL(pNode);	//ȸ���� ��带 LLȸ��
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::RotateRL(TBinary_Tree<T>* bst) {
	TBinary_Tree<T>* pNode = bst;						//ȸ���� ����� ������
	TBinary_Tree<T>* cNode = pNode->GetRightSubTree();	//���뷱���� ����� ������

	pNode->ChangeRightSubTree(RotateLL(cNode));	//���뷱���� ��带 LLȸ�� �� �� ȸ���� ����� ������ ��带 ���뷱���� ���� ��ü

	return RotateRR(pNode);	//ȸ���� ��带 RRȸ��
}

template<typename T>
inline void AVL_Tree<T>::Rebalance() {
	int hDiff = GetHeightDiff(BSTree);	//���� �μ�

	if (hDiff > 1) {	//�����μ��� 2 �̻��̸鼭,
		if (GetHeightDiff(BSTree->GetLeftSubTree()) > 0)	//���� ���� Ʈ���� +�� LL���´ϱ�
			BSTree = RotateLL(BSTree);	//LLȸ��
		else												//�ƴ϶�� -�ϱ�
			BSTree = RotateLR(BSTree);	//LRȸ��
	}
	else if (hDiff < -1) {	//�����μ��� -2 ���ϸ鼭,
		if (GetHeightDiff(BSTree->GetRightSubTree()) < 0)	//���� ���� Ʈ���� -�� RR���´ϱ�
			BSTree = RotateRR(BSTree);	//RRȸ��
		else												//�ƴ϶�� +�ϱ�
			BSTree = RotateRL(BSTree);	//RLȸ��
	}
}




template<typename T>
inline AVL_Tree<T>::AVL_Tree() :BSTree(nullptr) {}

template<typename T>
inline AVL_Tree<T>::~AVL_Tree() {
	BSTree->DeleteTree();
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::BSTRoot() {
	return BSTree;
}

template<typename T>
inline void AVL_Tree<T>::BSTInsert(T data) {
	TBinary_Tree<T>* nNode = nullptr;
	TBinary_Tree<T>* cNode = BSTree;
	TBinary_Tree<T>* pNode = nullptr;

	while (cNode != nullptr) {
		if (cNode->getData() == data)
			return;

		pNode = cNode;

		if (cNode->getData() > data)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	nNode = new TBinary_Tree<T>;
	nNode->SetData(data);

	if (pNode != nullptr) {
		if (data < pNode->getData())
			pNode->MakeLeftSubTree(nNode);
		else
			pNode->MakeRightSubTree(nNode);
	}
	else {
		BSTree = nNode;
	}

	Rebalance();	//��� �߰� �� ���뷱��
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::BSTSearch(T target) {
	TBinary_Tree<T>* cNode = BSTree;
	T cd = cNode->getData();

	while (cNode != nullptr) {
		cd = cNode->getData();

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	return nullptr;
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::BSTRemove(T target) {
	TBinary_Tree<T>* pVRoot = new TBinary_Tree<T>;
	TBinary_Tree<T>* pNode = pVRoot;
	TBinary_Tree<T>* cNode = BSTree;
	TBinary_Tree<T>* dNode;

	pVRoot->ChangeRightSubTree(BSTree);

	while (cNode != nullptr && cNode->getData() != target) {
		pNode = cNode;

		if (target < cNode->getData())
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	if (cNode == nullptr)
		return nullptr;
	else
		dNode = cNode;

	if (dNode->GetLeftSubTree() == nullptr &&
		dNode->GetRightSubTree() == nullptr) {
		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(nullptr);
		else
			pNode->ChangeRightSubTree(nullptr);
	}
	else if (dNode->GetLeftSubTree() == nullptr ||
		dNode->GetRightSubTree() == nullptr) {
		TBinary_Tree<T>* dcNode;

		if (dNode->GetLeftSubTree() != nullptr)
			dcNode = dNode->GetLeftSubTree();
		else
			dcNode = dNode->GetRightSubTree();

		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(dcNode);
		else
			pNode->ChangeRightSubTree(dcNode);
	}
	else {
		TBinary_Tree<T>* mNode = dNode->GetRightSubTree();
		TBinary_Tree<T>* mpNode = dNode;
		T delData;

		while (mNode->GetLeftSubTree() != nullptr) {
			mpNode = mNode;
			mNode = mNode->GetLeftSubTree();
		}

		delData = dNode->getData();
		dNode->SetData(mNode->getData());

		if (mpNode->GetLeftSubTree() == mNode)
			mpNode->ChangeLeftSubTree(mNode->GetRightSubTree());
		else
			mpNode->ChangeRightSubTree(mNode->GetRightSubTree());

		dNode = mNode;
		dNode->SetData(delData);
	}

	if (pVRoot->GetRightSubTree() != BSTree)
		BSTree = pVRoot->GetRightSubTree();

	delete pVRoot;
	Rebalance();	//��� ���� �� ���뷱��
	return dNode;
}

template<typename T>
inline void AVL_Tree<T>::BSTInorderTraverse(comp action) {
	BSTree->InorderTraverse(action);
}