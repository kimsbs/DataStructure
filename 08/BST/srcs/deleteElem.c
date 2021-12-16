#include "binsearchtree.h"

BinSearchTreeNode *RLlast(BinSearchTreeNode *node)
{
    BinSearchTreeNode *curr;

    curr = node->pRightChild;
    while (curr->pLeftChild)
    {
        curr = curr->pLeftChild;
    }
    return (curr);
}

void delete_Two_child(BinSearchTree *pBinSearchTree, BinSearchTreeNode *remove)
{
    BinSearchTreeNode *replace;
    BinSearchTreeNode *parent;

    replace = RLlast(remove);
    parent = replace->pParent;
    if (replace->pRightChild)
        link_PC_BST(parent, replace->pRightChild);
    else
        parent->pLeftChild = NULL;
    replace->pLeftChild = remove->pLeftChild;
    replace->pRightChild = remove->pRightChild;
    if (remove != pBinSearchTree->pRootNode)
        link_PC_BST(remove->pParent, replace);
    else
        pBinSearchTree->pRootNode = replace;

    free(remove);
    remove = NULL;
}

void delete_One_child(BinSearchTree *pBinSearchTree, BinSearchTreeNode *remove)
{
    BinSearchTreeNode *parent;
    BinSearchTreeNode *child;

    if (remove->pLeftChild)
        child = remove->pLeftChild;
    else
        child = remove->pRightChild;
    if (remove != pBinSearchTree->pRootNode)
    {
        parent = remove->pParent;
        link_PC_BST(parent, child);
    }
    else
        pBinSearchTree->pRootNode = child;
        
    free(remove);
    remove = NULL;
}

void delete_NO_child(BinSearchTree *pBinSearchTree, BinSearchTreeNode *remove)
{
    BinSearchTreeNode *parent;

    if (remove == pBinSearchTree->pRootNode)
        pBinSearchTree->pRootNode = NULL;
    else
    {
        parent = remove->pParent;
        if(parent->pLeftChild == remove)
            parent->pLeftChild = NULL;
        else
            parent->pRightChild = NULL;
    }
    free(remove);
    remove = NULL;
}

int deleteElementBST(BinSearchTree *pBinSearchTree, int key)
{
    BinSearchTreeNode *remove;

    if (!pBinSearchTree || pBinSearchTree->pRootNode == NULL)
    {
        printf("Tree is empty");
        return (FALSE);
    }
    remove = searchBST(pBinSearchTree, key);
    if (remove->key != key)
    {
        printf("key isn't exist\n");
        return (FALSE);
    }
    //no child
    if (!remove->pLeftChild && !remove->pRightChild)
        delete_NO_child(pBinSearchTree, remove);
    //two child
    else if (remove->pLeftChild && remove->pRightChild)
        delete_Two_child(pBinSearchTree, remove);
    //one child
    else
        delete_One_child(pBinSearchTree, remove);
    return (TRUE);
}