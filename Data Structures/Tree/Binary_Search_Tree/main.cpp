#include<iostream>
#include"BSearch_Tree.h"

using namespace std;

void ShowIntData(int data) {
	cout << data << " ";
}

int main() {
	BSearch_Tree<int> bst;

	bst.BSTInsert(9);
	bst.BSTInsert(1);
	bst.BSTInsert(6);
	bst.BSTInsert(2);
	bst.BSTInsert(8);
	bst.BSTInsert(3);
	bst.BSTInsert(5);

	if (bst.BSTSearch(1) == nullptr)
		cout << "Å½»ö ½ÇÆÐ" << endl;
	else
		cout << "Å½»ö ¼º°ø : " << bst.BSTSearch(1)->getData() << endl;

	if (bst.BSTSearch(4) == nullptr)
		cout << "Å½»ö ½ÇÆÐ" << endl;
	else
		cout << "Å½»ö ¼º°ø : " << bst.BSTSearch(4)->getData() << endl;

	if (bst.BSTSearch(6) == nullptr)
		cout << "Å½»ö ½ÇÆÐ" << endl;
	else
		cout << "Å½»ö ¼º°ø : " << bst.BSTSearch(6)->getData() << endl;

	if (bst.BSTSearch(7) == nullptr)
		cout << "Å½»ö ½ÇÆÐ" << endl;
	else
		cout << "Å½»ö ¼º°ø : " << bst.BSTSearch(7)->getData() << endl;


	return 0;
}