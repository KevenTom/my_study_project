#pragma once
#include"TBinary_Tree.h"	//전에 만든 순회 이진 트리를 사용
/*
void AVL_Tree<T>::BSTInsert(T insert)
- 트리에 insert 데이터를 저장한다.

TBinary_Tree<T>* AVL_Tree<T>::BSTSearch(T target)
- 트리에 target을 찾는다. 
- 트리에 target이 있다면 target 노드 주소를 반환, 없다면 nullptr 반환

TBinary_Tree<T>* AVL_Tree<T>::BSTRemove(T target)
- 트리에 target을 삭제한다.
- 트리에 target이 있다면 target 노드 주소를 반환, 없다면 nullptr 반환

void AVL_Tree<T>::BSTInorderTraverse(comp action)
- 중위 순회로 action 함수 포인터를 실행한다.
- comp 자료형은 매개변수 T를 가진 void 함수 포인터 자료형이다.
*/

template<typename T>
class AVL_Tree {
private:
	TBinary_Tree<T>* BSTree;

	int GetHeight(TBinary_Tree<T>* bst);		//트리의 모든 경로 중 가장 높은 높이를 반환
	int GetHeightDiff(TBinary_Tree<T>* bst);	//왼쪽, 오른쪽 서브 트리의 균형 인수를 반환
	TBinary_Tree<T>* RotateLL(TBinary_Tree<T>* bst);	//LL회전
	TBinary_Tree<T>* RotateRR(TBinary_Tree<T>* bst);	//RR회전
	TBinary_Tree<T>* RotateLR(TBinary_Tree<T>* bst);	//LR회전
	TBinary_Tree<T>* RotateRL(TBinary_Tree<T>* bst);	//RL회전
	void Rebalance();									//리밸런싱 체크
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
	TBinary_Tree<T>* pNode = bst;						//회전할 노드의 포인터
	TBinary_Tree<T>* cNode = pNode->GetLeftSubTree();	//리밸런싱할 노드의 포인터

	pNode->ChangeLeftSubTree(cNode->GetRightSubTree());	//회전할 노드의 왼쪽 노드를 리밸런싱할 노드의 오른쪽 노드로 교체
	cNode->ChangeRightSubTree(pNode);	//리밸런싱할 노드의 오른쪽 노드를 회전할 노드로 교체

	return cNode;
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::RotateRR(TBinary_Tree<T>* bst) {
	TBinary_Tree<T>* pNode = bst;						//회전할 노드의 포인터
	TBinary_Tree<T>* cNode = pNode->GetRightSubTree();	//리밸런싱할 노드의 포인터

	pNode->ChangeRightSubTree(cNode->GetLeftSubTree());	//회전할 노드의 오른쪽 노드를 리밸런싱할 노드의 왼쪽 노드로 교체
	cNode->ChangeLeftSubTree(pNode);	//리밸런싱할 노드의 왼쪽 노드를 회전할 노드로 교체

	return cNode;
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::RotateLR(TBinary_Tree<T>* bst) {
	TBinary_Tree<T>* pNode = bst;						//회전할 노드의 포인터
	TBinary_Tree<T>* cNode = pNode->GetLeftSubTree();	//리밸런싱할 노드의 포인터

	pNode->ChangeLeftSubTree(RotateRR(cNode));	//리밸런싱할 노드를 RR회전 한 후 회전할 노드의 왼쪽 노드를 리밸런싱할 노드로 교체

	return RotateLL(pNode);	//회전할 노드를 LL회전
}

template<typename T>
inline TBinary_Tree<T>* AVL_Tree<T>::RotateRL(TBinary_Tree<T>* bst) {
	TBinary_Tree<T>* pNode = bst;						//회전할 노드의 포인터
	TBinary_Tree<T>* cNode = pNode->GetRightSubTree();	//리밸런싱할 노드의 포인터

	pNode->ChangeRightSubTree(RotateLL(cNode));	//리밸런싱할 노드를 LL회전 한 후 회전할 노드의 오른쪽 노드를 리밸런싱할 노드로 교체

	return RotateRR(pNode);	//회전할 노드를 RR회전
}

template<typename T>
inline void AVL_Tree<T>::Rebalance() {
	int hDiff = GetHeightDiff(BSTree);	//균형 인수

	if (hDiff > 1) {	//균형인수가 2 이상이면서,
		if (GetHeightDiff(BSTree->GetLeftSubTree()) > 0)	//왼쪽 서브 트리가 +면 LL상태니까
			BSTree = RotateLL(BSTree);	//LL회전
		else												//아니라면 -니까
			BSTree = RotateLR(BSTree);	//LR회전
	}
	else if (hDiff < -1) {	//균형인수가 -2 이하면서,
		if (GetHeightDiff(BSTree->GetRightSubTree()) < 0)	//왼쪽 서브 트리가 -면 RR상태니까
			BSTree = RotateRR(BSTree);	//RR회전
		else												//아니라면 +니까
			BSTree = RotateRL(BSTree);	//RL회전
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

	Rebalance();	//노드 추가 후 리밸런싱
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
	Rebalance();	//노드 제거 후 리밸런싱
	return dNode;
}

template<typename T>
inline void AVL_Tree<T>::BSTInorderTraverse(comp action) {
	BSTree->InorderTraverse(action);
}