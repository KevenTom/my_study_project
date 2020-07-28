#include"ExpressionTree.h"
#include<iostream>

using namespace std;

void ShowIntData(int data) {
	if (0 <= data && data <= 9)
		cout << data << " ";
	else
		cout << (char)data << " ";
}

int main() {
	char exp[] = "12+7*";

	ExpressionTree<int>* expressiontree = new ExpressionTree<int>(exp);

	PreorderTraverse(expressiontree, ShowIntData); cout << endl;
	InroderTraverse(expressiontree, ShowIntData); cout << endl;
	PostorderTraverse(expressiontree, ShowIntData); cout << endl;

	cout << expressiontree->evaluateExpTree() << endl;

	return 0;
}