#include "mazesolve.h"

int     can_move(LinkedStack* pStack)
{
    int y = pStack->player[0];
    int x = pStack->player[1];
    if(y < 0 || y >= pStack->ver)
        return(FALSE);
    if(x < 0 || x >= pStack->hor)
        return(FALSE);
    if(pStack->map[y][x] == '1')
        return(FALSE);
    if(pStack->map[y][x] == '2' || pStack->map[y][x] == 'S')
        return(FALSE);
    return (TRUE);
}

int     is_end(LinkedStack* pStack)
{
    if(pStack->player[0] == pStack->end[0] &&
        pStack->player[1] == pStack->end[1])
        return(1);
    return(0);
}

void    stack_cpy(LinkedStack* pStack , LinkedStack *sol)
{
    LinkedStack *tmp;
    StackNode *move;
    StackNode node;

    if (pStack->max_move > pStack->cnt)
    {
        move = pStack->pTopElement;
        pStack->max_move = pStack->cnt;
        deleteLinkedStack(sol);
        tmp = createLinkedStack(pStack);
        while(move)
        {
            node.data = move->data;
            pushLS(tmp, node);
            move = move->pLink;
        }
        sol = tmp;
    }
    showLS(pStack);
}

void	find_path(LinkedStack* pStack, LinkedStack *sol)
{
    if(is_end(pStack))
    {
        stack_cpy(pStack, sol);
        return ;
    }
    move_right(pStack, sol);
    move_left(pStack, sol);
    move_up(pStack, sol);
    move_down(pStack, sol);
}