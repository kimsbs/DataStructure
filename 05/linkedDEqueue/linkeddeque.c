#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
    LinkedDeque *deque;

    deque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
    if (!deque)
        return (FALSE);
    deque->pFrontNode = NULL;
    deque->pRearNode = NULL;
    return (deque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode *node;

    if (!pDeque)
        return (FALSE);
    node = (DequeNode *)malloc(sizeof(DequeNode));
    node->data = element.data;
    node->pRLink = NULL;
    node->pLLink = NULL;
    if (!pDeque->pFrontNode)
    {
        pDeque->pFrontNode = node;
        pDeque->pRearNode = node;
    }
    else
    {
        node->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode->pLLink = node;
        pDeque->pFrontNode = node;
    }
    return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode *node;

    if (!pDeque)
        return (FALSE);
    node = (DequeNode *)malloc(sizeof(DequeNode));
    node->data = element.data;
    node->pRLink = NULL;
    node->pLLink = NULL;
    if (!pDeque->pRearNode)
    {
        pDeque->pFrontNode = node;
        pDeque->pRearNode = node;
    }
    else
    {
        node->pLLink = pDeque->pRearNode;
        pDeque->pRearNode->pRLink = node;
        pDeque->pRearNode = node;
    }
    return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
    DequeNode* node;
    DequeNode* new_front;

    if (!pDeque || isLinkedDequeEmpty(pDeque))
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
        new_front->pLLink = NULL;
        pDeque->pFrontNode = new_front;
        node->pRLink = NULL;
    }
    return (node);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
    DequeNode* node;
    DequeNode* new_rear;

    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (FALSE);
    if (pDeque->pFrontNode == pDeque->pRearNode)
    {
        node = pDeque->pRearNode;
        pDeque->pFrontNode = NULL;
        pDeque->pRearNode = NULL;
    }
    else
    {
        node = pDeque->pRearNode;
        new_rear = node->pLLink;
        new_rear->pRLink = NULL;
        pDeque->pRearNode = new_rear;
        node->pLLink = NULL;
    }
    return (node);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    DequeNode* node;
    
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (FALSE);
    node = pDeque->pFrontNode;
    return (node);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
    DequeNode* node;
    
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (FALSE);
    node = pDeque->pRearNode;
    return (node);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
    DequeNode* pop;
    while (!isLinkedDequeEmpty(pDeque))
    {
        pop = deleteFrontLD(pDeque);
        pop->data = '\0';
        free(pop);
    }
    free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    if(!pDeque)
        return (FALSE);
    if(!pDeque->pFrontNode && !pDeque->pRearNode)
        return(TRUE);
    return(FALSE);
}

void displayDeque(LinkedDeque *pDeque)
{
    if (!pDeque)
        return;
    DequeNode *temp;
    int i = 0;

    temp = pDeque->pFrontNode;
    while (temp != NULL)
    {
        printf("{index: %d, data: %c}\n", i, temp->data);
        i++;
        temp = temp->pRLink;
    }
    return;
}

void    loop()
{
    LinkedDeque *pDeque;
    DequeNode *del;
    DequeNode node0;

    int number;
    pDeque = createLinkedDeque();
    while (1)
    {
        printf("1 : InsertFront 2 : InsertRear\n3 : DeleteFront 4 : DeleteRear\n5 : PeekFront   6 : PeekRear\n7 : Display     8 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("data : ");
            getchar();
            scanf("%c", &node0.data);
            insertFrontLD(pDeque, node0);
            displayDeque(pDeque);
            break;
        case 2:
            printf("data : ");
            getchar();
            scanf("%c", &node0.data);
            insertRearLD(pDeque, node0);
            displayDeque(pDeque);
            break;
        case 3:
            del = deleteFrontLD(pDeque);
            printf("%c has del!\n", del->data);
            free(del);
            displayDeque(pDeque);
            break;
        case 4:
            del = deleteRearLD(pDeque);
            printf("%c has del!\n", del->data);
            free(del);
            displayDeque(pDeque);
            break;
        case 5:
            del = peekFrontLD(pDeque);
            printf("tada %c!\n", del->data);
            break;
        case 6:
            del = peekRearLD(pDeque);
            printf("tada %c!\n", del->data);
            break;
        case 7:
            displayDeque(pDeque);
            break;
        case 8:
            deleteLinkedDeque(pDeque);
            return ;
        default:
            break;
        }
    }
    return ;
}

int main()
{
    loop();
    system("leaks a");
}