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
	cout << "哭率1 : " << clNode->getData() << " 坷弗率1 : " << crNode->getData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "哭率2 : " << clNode->getData() << " 坷弗率2 : " << crNode->getData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "哭率3 : " << clNode->getData() << " 坷弗率3 : " << crNode->getData() << endl;

	clNode = clNode->GetLeftSubTree();
	crNode = crNode->GetRightSubTree();
	cout << "哭率3 : " << clNode->getData() << " 坷弗率3 : " << crNode->getData() << endl;



	return 0;
}