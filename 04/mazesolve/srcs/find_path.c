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

void	find_path(LinkedStack* pStack)
{
    if(is_end(pStack))
            return ;
    move_right(pStack);
    if(is_end(pStack))
        return ;
    move_left(pStack);
    if(is_end(pStack))
        return ;
    move_up(pStack);
    if(is_end(pStack))
        return ;
    move_down(pStack);
    if(is_end(pStack))
        return ;
}