#include "ExpressionTree.h"
#include "ClassStack.h"
#include <iostream>

BTreeNode* ExpressionTree::makeExpTree(char exp[]) {

	LStack nodeStack;
	BinaryTree binarytree;

	for (int i = 0; i < strlen(exp); ++i) {
		BTreeNode* pNode = binarytree.makeBTreeNode();

		if (isdigit(exp[i]))
			binarytree.setData(pNode, exp[i] - '0');
		else {
			binarytree.makerRightSubTree(pNode, nodeStack.SPop());
			binarytree.makerLeftSubTree(pNode, nodeStack.SPop());
			binarytree.setData(pNode, exp[i]);
		}
		nodeStack.SPush(pNode);
	}

	return nodeStack.SPop();
}

int ExpressionTree::evaluateExpTree(BTreeNode* node) {
	BinaryTree binarytree;


	int op1, op2;

	if (binarytree.getLeftSubTree(node) == NULL && binarytree.getRightSubTree(node) == NULL)
		return binarytree.getData(node);

	op1 = evaluateExpTree(binarytree.getLeftSubTree(node));
	op2 = evaluateExpTree(binarytree.getRightSubTree(node));

	switch (binarytree.getData(node))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
	return 0;
}

void showNodeData(int data) {
	if (0 <= data && data <= 9)
		std::cout << data << " ";
	else
		std::cout << char(data) << " ";
}

void ExpressionTree::showPrefixTypeExp(BTreeNode* node) {
	BinaryTree binarytree;
	binarytree.PreorderTraverse(node, showNodeData);
}
void ExpressionTree::showInfixTypeExp(BTreeNode* node) {
	BinaryTree binarytree;
	binarytree.InorderTraverse(node, showNodeData);
}
void ExpressionTree::showpostfixTypeExp(BTreeNode* node) {
	BinaryTree binarytree;
	binarytree.PostoorderTraverse(node, showNodeData);
}