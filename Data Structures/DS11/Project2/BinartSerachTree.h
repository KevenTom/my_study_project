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
        if (tree->getData() == insert)
            return;

        if (tree->getData() == NULL) {
            tree->SetData(insert);
            return;
        }
        if (tree->GetRightSubTree() == NULL && tree->getData() < insert) {
            Binary_Tree<T>* subtree = new Binary_Tree<T>;
            tree->MakeRightSubTree(subtree);
        }
        else if (tree->GetLeftSubTree() == NULL && tree->getData() > insert) {
            Binary_Tree<T>* subtree = new Binary_Tree<T>;
            tree->MakeLeftSubTree(subtree);
        }

        if (insert > tree->getData())
            MakeSearchTree(insert, tree->GetRightSubTree());
        else
            MakeSearchTree(insert, tree->GetLeftSubTree());
    }


    Binary_Tree<T>* SearchTree(T insert, Binary_Tree<T>* tree) {
        if (tree == NULL)
            return NULL;
        
        
        if (tree->getData() == insert)
            return tree;
        else if (tree->getData() < insert)
            SearchTree(insert, tree->GetRightSubTree());
        else
            SearchTree(insert, tree->GetLeftSubTree());
    }

    void DeleteSearchTree(T insert) {
        Binary_Tree<T>* pVroot = new Binary_Tree<T>;
        Binary_Tree<T>* rootNode = pVroot;
        Binary_Tree<T>* subNode = this;
        Binary_Tree<T>* rootNode2;
        Binary_Tree<T>* subNode2;

        pVroot->MakeRightSubTree(subNode);


        while (subNode != NULL && subNode->getData() != insert) {
            rootNode = subNode;

            if (subNode->getData() < insert)
                subNode = subNode->GetRightSubTree();
            else
                subNode = subNode->GetLeftSubTree();
        }

        if (subNode == NULL)
            return;



        if (subNode->GetLeftSubTree() == NULL && subNode->GetRightSubTree() == NULL) {
            if (rootNode->GetLeftSubTree() == subNode)
                rootNode->MakeLeftSubTree(NULL);
            else
                rootNode->MakeRightSubTree(NULL);
        }

        else if (subNode->GetLeftSubTree() == NULL || subNode->GetRightSubTree() == NULL) {
            if (rootNode->GetLeftSubTree() == subNode) {
                if (subNode->GetLeftSubTree() == NULL)
                    rootNode->MakeLeftSubTree(subNode->GetRightSubTree());
                else
                    rootNode->MakeLeftSubTree(subNode->GetLeftSubTree());
            }
            else {
                if (subNode->GetLeftSubTree() == NULL)
                    rootNode->MakeRightSubTree(subNode->GetRightSubTree());
                else
                    rootNode->MakeRightSubTree(subNode->GetLeftSubTree());
            }
        }

        else {
            rootNode2 = subNode;
            subNode2 = subNode->GetRightSubTree();

            while (subNode2->GetLeftSubTree() != NULL) {
                rootNode2 = subNode2;
                subNode2 = subNode2->GetLeftSubTree();
            }

            subNode->SetData(subNode2->getData());

            if (rootNode2->GetLeftSubTree() == subNode2)
                rootNode2->MakeLeftSubTree(subNode2->GetRightSubTree());
            else
                rootNode2->MakeRightSubTree(subNode2->GetRightSubTree());

            subNode = subNode2;
        }


        delete[] subNode;
    }





    void oldDeleteSearchTree(T insert) {
        Binary_Tree<T>* rootNode = this;
        Binary_Tree<T>* subNode;

        if (rootNode == NULL)
            return;
        else if (rootNode->getData() < insert)
            subNode = rootNode->GetRightSubTree();
        else
            subNode = rootNode->GetLeftSubTree();



        while (subNode->getData() != insert) {
            if (subNode->getData() == NULL)
                return;

            if (subNode->getData() < insert) {
                rootNode = subNode;
                subNode = subNode->GetRightSubTree();
            }
            else {
                rootNode = subNode;
                subNode = subNode->GetLeftSubTree();
            }
        }



        if (subNode->GetLeftSubTree() == NULL && subNode->GetRightSubTree() == NULL) {
            delete[] subNode;

        }
        else if (subNode->GetLeftSubTree() == NULL || subNode->GetRightSubTree() == NULL) {
            if (subNode->GetLeftSubTree() == NULL)
                if (rootNode->GetLeftSubTree() == subNode) {
                    rootNode->MakeLeftSubTree(subNode->GetRightSubTree());
                    delete[] subNode;
                }
                else {
                    rootNode->MakeRightSubTree(subNode->GetRightSubTree());
                    delete[] subNode;
                }
            else
                if (rootNode->GetLeftSubTree() == subNode) {
                    rootNode->MakeLeftSubTree(subNode->GetLeftSubTree());
                    delete[] subNode;
                }
                else {
                    rootNode->MakeRightSubTree(subNode->GetLeftSubTree());
                    delete[] subNode;
                }
        }
        else {
            Binary_Tree<T>* rootNode2 = subNode;
            Binary_Tree<T>* subNode2 = subNode->GetRightSubTree();

            while (subNode2->GetLeftSubTree() != NULL) {
                rootNode2 = subNode2;
                subNode2 = subNode2->GetLeftSubTree();
            }


            rootNode2->MakeRightSubTree(subNode2->GetRightSubTree());
            subNode2->MakeLeftSubTree(subNode->GetLeftSubTree());
            subNode2->MakeRightSubTree(subNode->GetRightSubTree());

            if (rootNode->GetLeftSubTree() == subNode) {
                rootNode->MakeLeftSubTree(subNode2);
                delete[] subNode;
            }
            else {
                rootNode->MakeRightSubTree(subNode2);
                delete[] subNode;
            }

        }
    }


};
