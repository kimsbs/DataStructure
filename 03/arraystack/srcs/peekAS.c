#include "arraystack.h"

ArrayStackNode* peekAS(ArrayStack* pStack)
{
    ArrayStackNode *node;

    if (!pStack || isArrayStackEmpty(pStack))
        return (NULL);
    node = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));
    node->data = pStack->pElement[pStack->currentElementCount - 1].data;
    return (node);
}