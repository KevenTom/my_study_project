#include<iostream>
#include"TBinary_Tree.h"

using namespace std;

void ShowIntData(int data) {
	cout << data << " ";
}

int main() {
	TBinary_Tree<int>* bt1 = new TBinary_Tree<int>;
	TBinary_Tree<int>* bt2 = new TBinary_Tree<int>;
	TBinary_Tree<int>* bt3 = new TBinary_Tree<int>;
	TBinary_Tree<int>* bt4 = new TBinary_Tree<int>;
	TBinary_Tree<int>* bt5 = new TBinary_Tree<int>;
	TBinary_Tree<int>* bt6 = new TBinary_Tree<int>;

	bt1->SetData(1);
	bt2->SetData(2);
	bt3->SetData(3);
	bt4->SetData(4);
	bt5->SetData(5);
	bt6->SetData(6);

	bt1->MakeLeftSubTree(bt2);
	bt1->MakeRightSubTree(bt3);
	bt2->MakeLeftSubTree(bt4);
	bt2->MakeRightSubTree(bt5);
	bt3->MakeRightSubTree(bt6);

	bt1->PreorderTraverse(ShowIntData);
	cout << endl;
	bt1->InorderTraverse(ShowIntData);
	cout << endl;
	bt1->PostorderTraverse(ShowIntData);
	cout << endl;
	bt1->DeleteTree();

	return 0;
}