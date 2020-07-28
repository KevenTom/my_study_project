#include"Binary_Tree.h"
#include<iostream>

using namespace std;

void ShowIntData(int data) {
	cout << data << endl;
}


int main() {
	Binary_Tree<int>* bt1 = new Binary_Tree<int>;
	Binary_Tree<int>* bt2 = new Binary_Tree<int>;
	Binary_Tree<int>* bt3 = new Binary_Tree<int>;
	Binary_Tree<int>* bt4 = new Binary_Tree<int>;
	Binary_Tree<int>* bt5 = new Binary_Tree<int>;
	Binary_Tree<int>* bt6 = new Binary_Tree<int>;

	bt1->SetData(10);
	bt2->SetData(20);
	bt3->SetData(30);
	bt4->SetData(40);
	bt5->SetData(50);
	bt6->SetData(60);

	bt1->MakeLeftSubTree(bt2);
	bt1->MakeRightSubTree(bt3);
	bt2->MakeLeftSubTree(bt4);
	bt2->MakeRightSubTree(bt5);
	bt3->MakeRightSubTree(bt6);

	
	cout << bt1->GetLeftSubTree()->getData() << endl;
	cout << bt1->GetLeftSubTree()->GetLeftSubTree()->getData() << endl;
	cout << endl;

	InroderTraverse(bt1, ShowIntData);
	cout << endl;

	PreorderTraverse(bt1, ShowIntData);
	cout << endl;

	PostorderTraverse(bt1, ShowIntData);
	cout << endl;

	
	bt2->DeleteTree();

	return 0;
}