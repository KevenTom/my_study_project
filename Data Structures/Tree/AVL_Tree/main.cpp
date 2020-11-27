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


	TBinary_Tree<int>* clNode;
	TBinary_Tree<int>* crNode;

	clNode = avl.BSTRoot()->GetLeftSubTree();
	crNode = avl.BSTRoot()->GetRightSubTree();
	cout << "����1 : " << clNode->getData() << " ������1 : " << crNode->getData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "����2 : " << clNode->getData() << " ������2 : " << crNode->getData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "����3 : " << clNode->getData() << " ������3 : " << crNode->getData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "����3 : " << clNode->getData() << " ������3 : " << crNode->getData() << endl;



	return 0;
}