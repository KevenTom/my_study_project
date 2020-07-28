//#include "ExpressionTree.h"
//#include "ClassStack.h"
//#include <iostream>
//
//BTreeNode* ExpressionTree::makeExpTree(char exp[]) {
//
//	LStack numberStack;
//	BinaryTree binarytree;
//	BTreeNode* rootNode = NULL;
//	int number = 0;
//
//	while (!exp[number] == NULL) {
//		if (isdigit(exp[number]))
//			numberStack.SPush(exp[number++]);
//		else {
//			numberStack.SPush(exp[number++]);
//			BTreeNode* newNode1 = binarytree.makeBTreeNode();
//			BTreeNode* newNode2 = binarytree.makeBTreeNode();
//			BTreeNode* newNode3 = binarytree.makeBTreeNode();
//			binarytree.setData(newNode3, numberStack.SPop());
//			binarytree.setData(newNode2, numberStack.SPop());
//			binarytree.setData(newNode1, numberStack.SPop());
//			binarytree.makerLeftSubTree(newNode3, newNode1);
//			binarytree.makerRightSubTree(newNode3, newNode2);
//			numberStack.SPush(newNode3->data);
//
//			if (rootNode != NULL) {
//				if (newNode3->left->data == rootNode->data)
//					binarytree.makerLeftSubTree(newNode3, rootNode);
//				else
//					binarytree.makerRightSubTree(newNode3, rootNode);
//				rootNode = newNode3;
//			}
//			else
//				rootNode = newNode3;
//		}
//	}
//
//	numberStack.SPop();
//	return rootNode;
//}
//
//void expData(BTreeNode* node) {
//	if (node->left == NULL)
//		return;
//
//	if (node->data == '+')
//		node->data = (node->left->data - '0') + (node->right->data - '0') + '0';
//	else if (node->data == '-')
//		node->data = (node->left->data - '0') - (node->right->data - '0') + '0';
//	else if (node->data == '*')
//		node->data = (node->left->data - '0') * (node->right->data - '0') + '0';
//	else if (node->data == '/')
//		node->data = (node->left->data - '0') / (node->right->data - '0') + '0';
//	else
//		std::cout << "오류 발생2" << std::endl;
//
//}
//
//int ExpressionTree::evaluateExpTree(BTreeNode* node) {
//	BinaryTree binarytree;
//
//	binarytree.PostoorderTraverse(node, expData);
//
//	return node->data - '0';
//}
//
//void showPrefixTypeExp(BTreeNode* node);
//void showInfixTypeExp(BTreeNode* node);
//void showpostfixTypeExp(BTreeNode* node);