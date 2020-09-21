#pragma once
#include "Binary_Tree.h"

template<typename T>
class AVLRebalance :
    public Binary_Tree<T>
{
public:
    static AVLRebalance& instance() {
        static AVLRebalance* instance = new AVLRebalance();
        return *instance;
    }

    int GetHeight(Binary_Tree<T>* bst) {
        int leftH;
        int rightH;

        if (bst == NULL)
            return 0;

        leftH = GetHeight(bst->GetLeftSubTree());
        rightH = GetHeight(bst->GetRightSubTree());

        if (leftH > rightH)
            return leftH + 1;
        else
            return rightH + 1;
    }

    int GetHightDiff() {
        Binary_Tree<T>* bstl = this;
        Binary_Tree<T>* bstr = this;
        int lsh;
        int rsh;

        if (bstl == NULL)
            return 0;

        lsh = GetHeight(bstl->GetLeftSubTree());
        rsh = GetHeight(bstr->GetRightSubTree());

        return lsh = rsh;
    }





};