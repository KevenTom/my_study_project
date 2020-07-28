#pragma once
#include"Binary_Tree.h"
#include<iostream>
#include<stack>

template<typename T>
class ExpressionTree : public Binary_Tree<T>
{
public:

	ExpressionTree(char exp[])
	{
		std::stack<Binary_Tree<T>*> s;

		for (unsigned int i = 0; i < strlen(exp); ++i) {
			Binary_Tree<T>* nd = new Binary_Tree<T>;

			if (isdigit(exp[i])) {
				nd->SetData(exp[i] - '0');
				s.push(nd);
				continue;
			}

			nd->MakeRightSubTree(s.top()); s.pop();
			nd->MakeLeftSubTree(s.top()); s.pop();
			nd->SetData(exp[i]);
			s.push(nd);
		}

		Binary_Tree<T>::CopyTree(s.top());
		delete s.top();
	}

	int evaluateExpTree() {
		if (this->GetLeftSubTree() == NULL && this->GetRightSubTree() == NULL)
			return this->getData();

		int op1 = static_cast<ExpressionTree*>(this->GetLeftSubTree())->evaluateExpTree();
		int op2 = static_cast<ExpressionTree*>(this->GetRightSubTree())->evaluateExpTree();

		switch (this->getData()) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}

		return op1;
	}
};