#include "arraystack.h"

ArrayStackNode* popAS(ArrayStack* pStack)
{
    ArrayStackNode *node;

    if (!pStack || isArrayStackEmpty(pStack))
        return (NULL);
    node = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));
    node->data = pStack->pElement[pStack->currentElementCount - 1].data;
    pStack->currentElementCount--;
    return (node);
}