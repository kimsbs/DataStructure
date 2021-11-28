#include "linkedstack.h"

void deleteLinkedStack(LinkedStack* pStack)
{
    StackNode *pop;

    if(!pStack)
        return ;
    pop = popLS(pStack);
    while(pop)
    {
        free(pop);
        pop = popLS(pStack);
    }
    free(pStack);
}
