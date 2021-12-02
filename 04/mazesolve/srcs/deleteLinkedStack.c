#include "mazesolve.h"

void deleteLinkedStack(LinkedStack* pStack)
{
    int move = 0;

    if(!pStack)
        return ;
    while(popLS(pStack))
    {
    }
    while(pStack->map[move])
    {
        free(pStack->map[move]);
        move++;
    }
    free(pStack->map);
    free(pStack);
}
