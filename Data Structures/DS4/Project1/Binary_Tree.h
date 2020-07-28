#pragma once
#include<iostream>

template<typename T>
class Binary_Tree
{
	T data;
	Binary_Tree* left;
	Binary_Tree* right;
public:
	Binary_Tree()
		:left(NULL), right(NULL)
	{}

	void DeleteTree() {
		if (this == NULL)
			return;
		this->GetLeftSubTree()->DeleteTree();
		this->GetRightSubTree()->DeleteTree();
		std::cout << "데이터 제거 : " << this->getData() << std::endl;
		delete this;
	}

	void SetData(T datae) {
		data = datae;
	}

	T getData() {
		return data;
	}

	Binary_Tree* GetLeftSubTree() {
		return left;
	}

	Binary_Tree* GetRightSubTree() {
		return right;
	}

	void MakeLeftSubTree(Binary_Tree* sub) {
		left = sub;
	}

	void MakeRightSubTree(Binary_Tree* sub) {
		right = sub;
	}


};


template<typename T>
void InroderTraverse(Binary_Tree<T>* bt, void (*action) (int)) {
	if (bt == NULL)
		return;

	InroderTraverse(bt->GetLeftSubTree(), action);
	action(bt->getData());
	InroderTraverse(bt->GetRightSubTree(), action);
}

template<typename T>
void PreorderTraverse(Binary_Tree<T>* bt, void (*action) (int)) {
	if (bt == NULL)
		return;

	action(bt->getData());
	PreorderTraverse(bt->GetLeftSubTree(), action);
	PreorderTraverse(bt->GetRightSubTree(), action);
}

template<typename T>
void PostorderTraverse(Binary_Tree<T>* bt, void (*action) (int)) {
	if (bt == NULL)
		return;

	PostorderTraverse(bt->GetLeftSubTree(), action);
	PostorderTraverse(bt->GetRightSubTree(), action);
	action(bt->getData());
}