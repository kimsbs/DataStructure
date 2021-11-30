#include "mazesolve.h"

int pushLS(LinkedStack* pStack, StackNode element)
{
    StackNode *node;

    if(!pStack)
        return(FALSE);
    node = (StackNode *)malloc(sizeof(StackNode));
    if(!node)
        return(FALSE);
    node->data = element.data;
    node->pLink = pStack->pTopElement;
    pStack->pTopElement = node;
    return(TRUE);    
}