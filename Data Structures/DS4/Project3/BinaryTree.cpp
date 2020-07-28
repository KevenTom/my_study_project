#include"BinaryTree.h"
#include<iostream>

BTreeNode* BinaryTree::makeBTreeNode() {
	BTreeNode* newNode = new BTreeNode;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BTData BinaryTree::getData(BTreeNode* node) {
	return node->data;
}

void BinaryTree::setData(BTreeNode* node, BTData data) {
	node->data = data;
}

BTreeNode* BinaryTree::getLeftSubTree(BTreeNode* node) {
	return node->left;
}

BTreeNode* BinaryTree::getRightSubTree(BTreeNode* node) {
	return node->right;
}

void BinaryTree::makerLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL)
		delete main->left;

	main->left = sub;
}

void BinaryTree::makerRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL)
		delete main->right;

	main->right = sub;
}

void BinaryTree::InorderTraverse(BTreeNode* node, VisitFuncPtr action) {
	if (node == NULL)
		return;

	InorderTraverse(node->left, action);
	action(node->data);
	InorderTraverse(node->right, action);
}

void BinaryTree::PreorderTraverse(BTreeNode* node, VisitFuncPtr action) {
	if (node == NULL)
		return;

	action(node->data);
	PreorderTraverse(node->left, action);
	PreorderTraverse(node->right, action);
}

void BinaryTree::PostoorderTraverse(BTreeNode* node, VisitFuncPtr action) {
	if (node == NULL)
		return;

	PostoorderTraverse(node->left, action);
	PostoorderTraverse(node->right, action);
	action(node->data);
}

void BinaryTree::DeleteTree(BTreeNode* node) {
	if (node == NULL)
		return;

	DeleteTree(node->left);
	DeleteTree(node->right);

	std::cout << "del tree data: " << node->data << std::endl;
	delete node;
}