#pragma once

#define TRUE 1
#define FALSE 0

typedef int BTData;

class BTreeNode {
public:
	BTData data;
	BTreeNode* left;
	BTreeNode* right;
};

class BinaryTree {

public:
	BTreeNode* makeBTreeNode();

	BTData getData(BTreeNode* node);
	void setData(BTreeNode* node, BTData data);

	BTreeNode* getLeftSubTree(BTreeNode* node);
	BTreeNode* getRightSubTree(BTreeNode* node);

	void makerLeftSubTree(BTreeNode* main, BTreeNode* sub);
	void makerRightSubTree(BTreeNode* main, BTreeNode* sub);

	using VisitFuncPtr = void(*)(BTData data);
	void InorderTraverse(BTreeNode* node, VisitFuncPtr action);
	void PreorderTraverse(BTreeNode* node, VisitFuncPtr action);
	void PostoorderTraverse(BTreeNode* node, VisitFuncPtr action);

	void DeleteTree(BTreeNode* node);
};