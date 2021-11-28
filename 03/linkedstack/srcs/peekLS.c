#include "linkedstack.h"

StackNode* peekLS(LinkedStack* pStack)
{
    StackNode *peek;

    if(!pStack || isLinkedStackEmpty(pStack))
        return (NULL);
    peek = pStack->pTopElement;
    return(peek);
}