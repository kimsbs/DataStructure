#include "mazesolve.h"

LinkedStack* createLinkedStack()
{
    LinkedStack *stack;

    stack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if(!stack)
        return (NULL);
    stack->pTopElement = NULL;
    stack->ver = 0;
    stack->hor = 0;
    stack->player[0] = 0;
    stack->player[1] = 0;
    stack->end[0] = 0;
    stack->end[1] = 0;
    stack->map = NULL;
    return(stack);
}