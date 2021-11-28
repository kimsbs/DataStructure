#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack *stack;

    stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    if (!stack)
        return (NULL);
    stack->maxElementCount = maxElementCount;
    stack->currentElementCount = 0;
    stack->pElement = (ArrayStackNode *)calloc(maxElementCount, sizeof(ArrayStackNode));
    return (stack);
}
