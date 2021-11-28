#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
    LinkedStack *stack;

    stack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if(!stack)
        return (NULL);
    stack->currentElementCount = 0;
    stack->pTopElement = NULL;
    return(stack);
}