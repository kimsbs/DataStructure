#include "mazesolve.h"

int     can_move(LinkedStack* pStack, int x, int y)
{
    if(y < 0 || y >= pStack->ver)
        return(FALSE);
    if(x < 0 || x >= pStack->hor)
        return(FALSE);
    if(pStack->map[y][x] == '1')
        return(FALSE);
    if(pStack->map[y][x] == 'M' || pStack->map[y][x] == 'S')
        return(FALSE);
    return (TRUE);
}

void    push_elem(LinkedStack *pStack, int x, int y, char data)
{
    StackNode node;

    node.data = data;
    node.x = x;
    node.y = y;
    pushLS(pStack, node);
}

void	find_path(LinkedStack* pStack)
{
    int x, y;
    
    x = pStack->player[1];
    y = pStack->player[0];
    while (pStack && !(x == pStack->end[1] && y == pStack->end[0]))
    {
        //움직입시당
        if(can_move(pStack, x + 1, y) && pStack->flag < 1)
            push_elem(pStack, x + 1, y, 'r');
        else if(can_move(pStack, x - 1, y) && pStack->flag < 2)
            push_elem(pStack, x - 1, y, 'l');
        else if(can_move(pStack, x, y - 1) && pStack->flag < 3)
            push_elem(pStack, x, y - 1, 'u');
        else if(can_move(pStack, x, y + 1) && pStack->flag < 4)
            push_elem(pStack, x, y + 1, 'd');
        else
            popLS(pStack);
        // x, y 초기화.
        if(pStack->pTopElement)
        {
            x = pStack->pTopElement->x;
            y = pStack->pTopElement->y;
        }
        else
        {
            x = pStack->player[1];
            y = pStack->player[0];
        }
    }
}