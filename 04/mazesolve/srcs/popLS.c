#include "mazesolve.h"

int popLS(LinkedStack* pStack)
{
    StackNode *pop;

    if(!pStack || isLinkedStackEmpty(pStack))
        return (FALSE);
    pop = pStack->pTopElement;
    pStack->pTopElement = pop->pLink;
    free(pop);
    return(TRUE);
}