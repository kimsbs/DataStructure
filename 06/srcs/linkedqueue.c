#include "linkedqueue.h"

LinkedQueue* createLinkedQueue()
{
    LinkedQueue *deque;

    deque = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    if (!deque)
        return (FALSE);
    deque->pFrontNode = NULL;
    deque->pRearNode = NULL;
    return (deque);
}

int insert(LinkedQueue* pDeque, QueueNode element)
{
    QueueNode *node;

    if (!pDeque)
        return (FALSE);
    node = (QueueNode *)malloc(sizeof(QueueNode));
    *node = element;
    node->pRLink = NULL;
    if (!pDeque->pRearNode)
    {
        pDeque->pFrontNode = node;
        pDeque->pRearNode = node;
    }
    else
    {
        pDeque->pRearNode->pRLink = node;
        pDeque->pRearNode = node;
    }
    return (TRUE);
}

QueueNode* deletefront(LinkedQueue* pDeque)
{
    QueueNode* node;
    QueueNode* new_front;

    if (!pDeque || isLinkedqueueEmpty(pDeque))
        return (FALSE);
    if (pDeque->pFrontNode == pDeque->pRearNode)
    {
        node = pDeque->pFrontNode;
        pDeque->pFrontNode = NULL;
        pDeque->pRearNode = NULL;
    }
    else
    {
        node = pDeque->pFrontNode;
        new_front = node->pRLink;
        pDeque->pFrontNode = new_front;
        node->pRLink = NULL;
    }
    return (node);
}

QueueNode* peek(LinkedQueue* pDeque)
{
    QueueNode* node;
    
    if (!pDeque || isLinkedqueueEmpty(pDeque))
        return (FALSE);
    node = pDeque->pFrontNode;
    return (node);
}

void deleteLinkedqueue(LinkedQueue* pDeque)
{
    QueueNode* pop;
    while (!isLinkedqueueEmpty(pDeque))
    {
        pop = deletefront(pDeque);
        free(pop);
    }
    free(pDeque);
}

int isLinkedqueueEmpty(LinkedQueue* pDeque)
{
    if(!pDeque)
        return (FALSE);
    if(!pDeque->pFrontNode && !pDeque->pRearNode)
        return(TRUE);
    return(FALSE);
}