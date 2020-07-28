#pragma once
#include "BinaryTree.h"

class ExpressionTree
{
public:
	BTreeNode* makeExpTree(char exp[]);
	int evaluateExpTree(BTreeNode* node);

	void showPrefixTypeExp(BTreeNode* node);
	void showInfixTypeExp(BTreeNode* node);
	void showpostfixTypeExp(BTreeNode* node);
};