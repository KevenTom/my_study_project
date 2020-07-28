#include"ExpressionTree.h"
#include<iostream>

using namespace std;

int main() {
	ExpressionTree expressiontree;

	char exp[] = "12+7*";
	BTreeNode* bt1 = expressiontree.makeExpTree(exp);

	expressiontree.showPrefixTypeExp(bt1); cout << '\n';

	expressiontree.showInfixTypeExp(bt1); cout << '\n';

	expressiontree.showpostfixTypeExp(bt1); cout << '\n';

	cout << expressiontree.evaluateExpTree(bt1) << endl;

	return 0;
}