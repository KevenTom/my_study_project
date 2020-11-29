#include<iostream>
#include"AVL_Tree.h"

using namespace std;

void ShowIntData(int data) {
	cout << data << " ";
}

int main() {
	AVL_Tree<int> avl;

	avl.BSTInsert(1);
	avl.BSTInsert(2);
	avl.BSTInsert(3);
	avl.BSTInsert(4);
	avl.BSTInsert(5);
	avl.BSTInsert(6);
	avl.BSTInsert(7);
	avl.BSTInsert(8);
	avl.BSTInsert(9);

	cout << "루트 노드 : " << avl.BSTRoot()->getData() << endl;

	TBinary_Tree<int>* clNode;
	TBinary_Tree<int>* crNode;

	clNode = avl.BSTRoot()->GetLeftSubTree();
	crNode = avl.BSTRoot()->GetRightSubTree();
	cout << "왼쪽1 : " << clNode->getData() << " 오른쪽1 : " << crNode->getData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "왼쪽2 : " << clNode->getData() << " 오른쪽2 : " << crNode->getData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "왼쪽3 : " << clNode->getData() << " 오른쪽3 : " << crNode->getData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "왼쪽4 : " << clNode->getData() << " 오른쪽4 : " << crNode->getData() << endl;



	return 0;
}