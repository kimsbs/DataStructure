#include "linkedstack.h"

StackNode* popLS(LinkedStack* pStack)
{
    StackNode *pop;

    if(!pStack || isLinkedStackEmpty(pStack))
        return(NULL);
    pop = pStack->pTopElement;
    pStack->pTopElement = pop->pLink;
    pStack->currentElementCount--;
    return(pop);
}