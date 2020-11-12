#pragma once
#include"TBinary_Tree.h"	//전에 만든 순회 이진 트리를 사용
/*
void BSearch_Tree<T>::BSTInsert(T insert)
- 트리에 insert 데이터를 저장한다.

TBinary_Tree<T>* BSearch_Tree<T>::BSTSearch(T target)
- 트리에 target을 찾는다. 
- 트리에 target이 있다면 target 노드 주소를 반환, 없다면 nullptr 반환

TBinary_Tree<T>* BSearch_Tree<T>::BSTRemove(T target)
- 트리에 target을 삭제한다.
- 트리에 target이 있다면 target 노드 주소를 반환, 없다면 nullptr 반환

void BSearch_Tree<T>::BSTInorderTraverse(comp action)
- 중위 순회로 action 함수 포인터를 실행한다.
- comp 자료형은 매개변수 T를 가진 void 함수 포인터 자료형이다.
*/

template<typename T>
class BSearch_Tree {
private:
	TBinary_Tree<T>* BSTree;

public:
	BSearch_Tree();
	~BSearch_Tree();

	void BSTInsert(T insert);	//트리에 데이터 저장
	TBinary_Tree<T>* BSTSearch(T target);	//트리에 target 노드 반환, 없으면 nullptr 반환
	TBinary_Tree<T>* BSTRemove(T target);	//트리에 target 데이터 삭제

	using comp = void(*)(T data);	//함수 포인터 타입 별칭
	void BSTInorderTraverse(comp action);	//중위 순회로 action 함수 포인터 실행
};

template<typename T>
inline BSearch_Tree<T>::BSearch_Tree() :BSTree(nullptr) {}

template<typename T>
inline BSearch_Tree<T>::~BSearch_Tree() {
	BSTree->DeleteTree();
}

template<typename T>
inline void BSearch_Tree<T>::BSTInsert(T data) {
	TBinary_Tree<T>* nNode = nullptr;	//새로 저장할 노드
	TBinary_Tree<T>* cNode = BSTree;	//저장할 위치를 찾아가기 위한 포인터
	TBinary_Tree<T>* pNode = nullptr;	//cNode의 전 단계 포인터

	while (cNode != nullptr) {			//cNode가 위치를 찾을때까지 반복
		if (cNode->getData() == data)	//이진 탐색 트리는 데이터(키)의 중복을 허용하지 않음
			return;

		pNode = cNode;

		if (cNode->getData() > data)	//새 노드가 cNode보다 작으면 왼쪽, 아니면 오른쪽
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	nNode = new TBinary_Tree<T>;		//새 노드를 동적할당
	nNode->SetData(data);

	if (pNode != nullptr) {				//Pnode가 nullptr이 아니라면
		if (data < pNode->getData())	//새 노드가 pNode보다 작으면 완쪽, 아니면 오른쪽
			pNode->MakeLeftSubTree(nNode);
		else
			pNode->MakeRightSubTree(nNode);
	}
	else {	//PNode가 루트노드일 경우 BSTree에 새 노드를 저장
		BSTree = nNode;
	}
}

template<typename T>
inline TBinary_Tree<T>* BSearch_Tree<T>::BSTSearch(T target) {
	TBinary_Tree<T>* cNode = BSTree;	//탐새할 위치를 찾아가기 위한 포인터
	T cd = cNode->getData();			//cNode의 데이터

	while (cNode != nullptr) {	//cNode가 nullptr을 찾을때까지 반복
		cd = cNode->getData();

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	return nullptr;	//return이 안됐다면 탐색 대상이 없다는 뜻이니까 nullptr을 반환
}

template<typename T>
inline TBinary_Tree<T>* BSearch_Tree<T>::BSTRemove(T target) {
	TBinary_Tree<T>* pVRoot = new TBinary_Tree<T>;	//루트노드도 삭제할 수 있으니까 필요한 가상 루트 노드
	TBinary_Tree<T>* pNode = pVRoot;				//삭제할 노드의 부모 노드
	TBinary_Tree<T>* cNode = BSTree;				//삭제할 노드
	TBinary_Tree<T>* dNode;							//삭제할 노드를 저장할 포인터

	pVRoot->ChangeRightSubTree(BSTree);

	while (cNode != nullptr && cNode->getData() != target) {	//삭제 대상 노드를 탐색
		pNode = cNode;

		if (target < cNode->getData())
			cNode = cNode->GetLeftSubTree();
		else
			cNode = cNode->GetRightSubTree();
	}

	if (cNode == nullptr)	//삭제할 노드가 없다면 nullptr 반환
		return nullptr;
	else					//있다면 dNode = cNode
		dNode = cNode;

	//삭제할 노드가 단말노드인 경우
	if (dNode->GetLeftSubTree() == nullptr &&
		dNode->GetRightSubTree() == nullptr) {
		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(nullptr);
		//pNode->MakeLeftSubTree(nullptr);
		else
			pNode->ChangeRightSubTree(nullptr);
			//pNode->MakeRightSubTree(nullptr);
	}
	//삭제할 노드가 자식 노드 하나인 경우
	else if (dNode->GetLeftSubTree() == nullptr ||
		dNode->GetRightSubTree() == nullptr) {
		TBinary_Tree<T>* dcNode; //삭제할 노드의 자식 노드

		if (dNode->GetLeftSubTree() != nullptr)
			dcNode = dNode->GetLeftSubTree();
		else
			dcNode = dNode->GetRightSubTree();

		if (pNode->GetLeftSubTree() == dNode)
			pNode->ChangeLeftSubTree(dcNode);
		else
			pNode->ChangeRightSubTree(dcNode);
	}
	//삭제할 노드가 이진트리인 경우
	else {
		TBinary_Tree<T>* mNode = dNode->GetRightSubTree();	//삭제할 노드의 대체 노드
		TBinary_Tree<T>* mpNode = dNode;					//대체 노드의 부모 노드
		T delData;											//데이터 백업

		while (mNode->GetLeftSubTree() != nullptr) {	//대체 노드를 찾을때까지 반복
			mpNode = mNode;
			mNode = mNode->GetLeftSubTree();
		}

		delData = dNode->getData();			//삭제할 노드에 대체 노드의 값을 입력하기 전에 데이터 백업
		dNode->SetData(mNode->getData());	//삭제할 노드에 대체 노드의 값을 입력

		if (mpNode->GetLeftSubTree() == mNode)	//대체 노드의 오른쪽 서브 트리를 대체 노드의 부모 노드와 연결
			mpNode->ChangeLeftSubTree(mNode->GetRightSubTree());
		else
			mpNode->ChangeRightSubTree(mNode->GetRightSubTree());

		dNode = mNode;	//mNode가 대체된 노드니까 dNode에 mNode를 대입
		dNode->SetData(delData);
	}

	if (pVRoot->GetRightSubTree() != BSTree)	//루트 노드가 삭제된 경우 다시 설정해줌
		BSTree = pVRoot->GetRightSubTree();

	delete pVRoot;
	return dNode;
}

template<typename T>
inline void BSearch_Tree<T>::BSTInorderTraverse(comp action) {
	BSTree->InorderTraverse(action);
}