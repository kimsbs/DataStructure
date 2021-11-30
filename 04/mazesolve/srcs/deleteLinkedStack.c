#include "mazesolve.h"

void deleteLinkedStack(LinkedStack* pStack)
{
    StackNode *pop;
    int move = 0;

    if(!pStack)
        return ;
    pop = popLS(pStack);
    while(pop)
    {
        free(pop);
        pop = popLS(pStack);
    }
    while(pStack->map[move])
    {
        free(pStack->map[move]);
        move++;
    }
    free(pStack->map[move]);
    free(pStack);
}
