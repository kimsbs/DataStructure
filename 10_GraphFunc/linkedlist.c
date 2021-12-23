#include "linkedgraph.h"

LinkedList* createLinkedList()
{
    LinkedList *list;

    list = (LinkedList *)malloc(sizeof(LinkedList));
    if(!list)
        return (FALSE);
    list->frontNode = NULL;
    list->rearNode = NULL;
    return(list);
}

int addLLElement(LinkedList* pList, ListNode element)
{
    ListNode *tmp;
    if (!pList)
        return (FALSE);
    tmp = (ListNode *)malloc(sizeof(ListNode));
    if (!tmp)
        return (FALSE);
    *tmp = element;
    if(!pList->frontNode)
    {
        pList->frontNode = tmp;
        pList->rearNode = tmp;
    }
    else
    {
        pList->rearNode->pRLink = tmp;
        tmp->pLLink = pList->rearNode;
        pList->rearNode = tmp;
    }
    return (TRUE);
}

int removeLLElement(LinkedList* pList, int VertexID)
{
    ListNode *tmp;
    ListNode *front;
    ListNode *next;
    
    tmp = getLLElement(pList, VertexID);
    if(!tmp)
        return (FALSE);
    if(tmp == pList->frontNode && tmp == pList->rearNode)
    {
        pList->frontNode = NULL;
        pList->rearNode = NULL;
    }
    else if(tmp == pList->frontNode)
    {
        next = tmp->pRLink;
        next->pLLink = NULL;
        pList->frontNode = next;
    }
    else if(tmp == pList->rearNode)
    {
        front = tmp->pLLink;
        front->pRLink = NULL;
        pList->rearNode = front;
    }
    else
    {
        front = tmp->pLLink;
        next = tmp->pRLink;
        front->pRLink = next;
        next->pLLink = front;
    }
    free(tmp);
    return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int VertexID)
{
    ListNode *tmp;

    tmp = pList->frontNode;
    while(tmp)
    {
        if(tmp->data == VertexID)
            return (tmp);
        tmp = tmp->pRLink;
    }
    return (tmp);
}

void clearLinkedList(LinkedList* pList)
{
    ListNode *tmpNode;
    ListNode *curr;
    
    if (!pList)
        return ;
    curr = pList->frontNode;
    while (curr)
    {
        tmpNode = curr->pRLink;
        free(curr);
        curr = 0;
        curr = tmpNode;
    }
    pList->frontNode = pList->rearNode = NULL;
}

void deleteLinkedList(LinkedList* pList)
{
    clearLinkedList(pList);
    free(pList);
    pList = NULL;
}