#include "arraystack.h"

int isArrayStackEmpty(ArrayStack* pStack)
{
    if (!pStack)
        return (FALSE);
    if (pStack->currentElementCount == 0)
        return (TRUE);
    else
        return (FALSE);
}