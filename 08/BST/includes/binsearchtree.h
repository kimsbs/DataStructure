#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE		1
#define FALSE		0

typedef struct BinSearchTreeNodeType
{
	int key;
	char value;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
	struct BinSearchTreeNodeType* pParent;
}   BinSearchTreeNode;

typedef struct BinSearchTreeType
{
	BinSearchTreeNode *pRootNode;
}   BinSearchTree;

typedef struct QueueNode
{
    BinSearchTreeNode *data;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode *head;
    QNode *rear;
}QueueList;

//levelOrder
QueueList* creatQueue();
void deleteQueue(QueueList *Queue);
void enque(QueueList *Queue, BinSearchTreeNode *data);
void levelOrderTraversalBinTree(BinSearchTreeNode* pNode);

//+@
BinSearchTreeNode *createNode(BinSearchTreeNode element);
void    link_PC_BST(BinSearchTreeNode *parent, BinSearchTreeNode *child);

//Basic
BinSearchTree* createBinSearchTree();
int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element);
int deleteElementBST(BinSearchTree* pBinSearchTree, int key);
BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key);
BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key);
void deleteBinSearchTree(BinSearchTree* pBinSearchTree);
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode);

#endif