#pragma once
#include "Binary_Tree.h"

template<typename T>
class BinartSerachTree :
    public Binary_Tree<T>
{
public:
    BinartSerachTree()
        :Binary_Tree<T>()
    {}

    void MakeSearchTree(T insert, Binary_Tree<T>* tree) {
        if (tree->right == NULL) {
            Binary_Tree<T>* subtree = new Binary_Tree<T>;
            subtree->SetData(insert);
            tree->MakeRightSubTree(subtree);
            return;
        }
        else if (tree->left == NULL) {
            Binary_Tree<T>* subtree = new Binary_Tree<T>;
            subtree->SetData(insert);
            tree->MakeLeftSubTree(subtree);
            return;
        }

        if (insert > tree->data) {
            MakeSearchTree(insert, tree->GetRightSubTree());
        }
        else {
            MakeSearchTree(insert, tree->GetLeftSubTree());
        }
    }


};
