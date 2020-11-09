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
		TBinary_Tree<T>* nNode = nullptr;	//���� ������ ���
		TBinary_Tree<T>* cNode = BSTree;	//������ ��ġ�� ã�ư��� ���� ������
		TBinary_Tree<T>* pNode = nullptr;	//cNode�� �� �ܰ� ������

		while (cNode != nullptr) {	//cNode�� ��ġ�� ã�������� �ݺ�
			if (cNode->getData() == data)	//���� Ž�� Ʈ���� ������(Ű)�� �ߺ��� ������� ����
				return;

			pNode = cNode;

			if (cNode->getData() > data)	//�� ��尡 cNode���� ������ ����, �ƴϸ� ������
				cNode = cNode->GetLeftSubTree();
			else
				cNode = cNode->GetRightSubTree();
		}

		nNode = new TBinary_Tree<T>;	//�� ��带 �����Ҵ�
		nNode->SetData(data);

		if (pNode != nullptr) {	//Pnode�� nullptr�� �ƴ϶��
			if (data < pNode->getData())	//�� ��尡 pNode���� ������ ����, �ƴϸ� ������
				pNode->MakeLeftSubTree(nNode);
			else
				pNode->MakeRightSubTree(nNode);
		}
		else {	//PNode�� ��Ʈ����� ��� BSTree�� �� ��带 ����
			BSTree = nNode;
		}
	}

	TBinary_Tree<T>* BSTSearch(T target) {
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
};