#pragma once

#include"TBinary_Tree.h"

template<typename T>
class BSearch_Tree {
private:
	TBinary_Tree<T>* BSTree;
public:
	BSearch_Tree() :BSTree(nullptr) {}

	TBinary_Tree<T>* BSTGetData() {
		return BSTree;
	}

	void BSTInsert(T data) {
		TBinary_Tree<T>* nNode = nullptr;	//새로 저장할 노드
		TBinary_Tree<T>* cNode = BSTree;	//저장할 위치를 찾아가기 위한 포인터
		TBinary_Tree<T>* pNode = nullptr;	//cNode의 전 단계 포인터

		while (cNode != nullptr) {	//cNode가 위치를 찾을때까지 반복
			if (cNode->getData() == data)	//이진 탐색 트리는 데이터(키)의 중복을 허용하지 않음
				return;

			pNode = cNode;

			if (cNode->getData() > data)	//새 노드가 cNode보다 작으면 왼쪽, 아니면 오른쪽
				cNode = cNode->GetLeftSubTree();
			else
				cNode = cNode->GetRightSubTree();
		}

		nNode = new TBinary_Tree<T>;	//새 노드를 동적할당
		nNode->SetData(data);

		if (pNode != nullptr) {	//Pnode가 nullptr이 아니라면
			if (data < pNode->getData())	//새 노드가 pNode보다 작으면 완쪽, 아니면 오른쪽
				pNode->MakeLeftSubTree(nNode);
			else
				pNode->MakeRightSubTree(nNode);
		}
		else {	//PNode가 루트노드일 경우 BSTree에 새 노드를 저장
			BSTree = nNode;
		}
	}

	TBinary_Tree<T>* BSTSearch(T target) {
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
};