#include "arraystack.h"

int isArrayStackFull(ArrayStack* pStack)
{
    if (!pStack)
        return (FALSE);
    if (pStack->maxElementCount == pStack->currentElementCount)
        return (TRUE);
    else
        return (FALSE);
}