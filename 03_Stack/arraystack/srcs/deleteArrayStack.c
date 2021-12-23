#include "arraystack.h"

void deleteArrayStack(ArrayStack* pStack)
{
    if (!pStack)
        return ;
    pStack->currentElementCount = 0;
    pStack->maxElementCount = 0;
    free(pStack->pElement);
    free(pStack);
}