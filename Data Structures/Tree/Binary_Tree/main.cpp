#include<iostream>
#include"Binary_Tree.h"

using namespace std;

int main() {
	Binary_Tree<int> bt1;
	Binary_Tree<int> bt2;
	Binary_Tree<int> bt3;
	Binary_Tree<int> bt4;

	bt1.SetData(1);
	bt2.SetData(2);
	bt3.SetData(3);
	bt4.SetData(4);

	bt1.MakeLeftSubTree(&bt2);
	bt1.MakeRightSubTree(&bt3);
	bt2.MakeLeftSubTree(&bt4);

	cout << bt1.getData() << endl;
	cout << bt1.GetLeftSubTree()->getData() << endl;
	cout << bt1.GetLeftSubTree()->GetLeftSubTree()->getData() << endl;

	return 0;
}