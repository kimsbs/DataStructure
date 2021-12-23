#include "mazesolve.h"

int pushLS(LinkedStack* pStack, StackNode element)
{
    StackNode *node;

    if(!pStack)
        return(FALSE);
        
    node = (StackNode *)malloc(sizeof(StackNode));
    if(!node)
        return(FALSE);
    node->data = element.data;
    node->x = element.x;
    node->y = element.y;
    node->pLink = pStack->pTopElement;
    pStack->pTopElement = node;
    
    pStack->map[element.y][element.x] = 'M';
    pStack->flag = 0;
    return(TRUE);    
}