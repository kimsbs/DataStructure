#include "mazesolve.h"

int popLS(LinkedStack* pStack)
{
    StackNode *pop;
    if(!pStack || isLinkedStackEmpty(pStack))
        return (FALSE);
    int x = pStack->pTopElement->x;
    int y = pStack->pTopElement->y;
    
    pStack->map[y][x] = '0';
    pop = pStack->pTopElement;
    pStack->pTopElement = pop->pLink;
    if (pop->data == 'r')
        pStack->flag = 1;
    else if (pop->data == 'l')
        pStack->flag = 2;
    else if (pop->data == 'u')
        pStack->flag = 3;
    else // pop->data == 'd'
        pStack->flag = 4;
    free(pop);
    return(TRUE);
}