#pragma once
#define NULL 0

template<typename T>
class Binary_Tree
{
public:
	T data;
	Binary_Tree* left;
	Binary_Tree* right;
public:
	Binary_Tree()
		:left(NULL), right(NULL)
	{}

	T getData() {
		return data;
	}

	void SetData(T datae) {
		data = datae;
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

	void CopyTree(Binary_Tree* bt) {
		data = bt->getData();
		left = bt->GetLeftSubTree();
		right = bt->GetRightSubTree();
	}

	void DeleteTree() {
		if (this == NULL)
			return;
		this->GetLeftSubTree()->DeleteTree();
		this->GetRightSubTree()->DeleteTree();
		delete this;
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