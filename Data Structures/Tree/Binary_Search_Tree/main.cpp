#include<iostream>
#include"BSearch_Tree.h"

using namespace std;

void ShowIntData(int data) {
	cout << data << " ";
}

int main() {
	BSearch_Tree<int> bst;

	bst.BSTInsert(5);
	bst.BSTInsert(8);
	bst.BSTInsert(1);
	bst.BSTInsert(6);
	bst.BSTInsert(4);
	bst.BSTInsert(9);
	bst.BSTInsert(3);
	bst.BSTInsert(2);
	bst.BSTInsert(7);

	bst.BSTInorderTraverse(ShowIntData);
	cout << endl;
	delete bst.BSTRemove(3);

	bst.BSTInorderTraverse(ShowIntData);
	cout << endl;
	delete bst.BSTRemove(8);

	bst.BSTInorderTraverse(ShowIntData);
	cout << endl;
	delete bst.BSTRemove(1);

	bst.BSTInorderTraverse(ShowIntData);
	cout << endl;
	delete bst.BSTRemove(6);

	bst.BSTInorderTraverse(ShowIntData);
	cout << endl;

	return 0;
}