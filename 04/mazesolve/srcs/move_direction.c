#include "mazesolve.h"

void    dot_visited(LinkedStack* pStack, int x, int y, int flag)
{
    if(flag && pStack->map[y][x] != 'E')
        pStack->map[y][x] = '2';
    if(!flag)
        pStack->map[y][x] = '0';
}

void    move_right(LinkedStack* pStack)
{
    StackNode node;
    int x, y;

    if(is_end(pStack))
        return ;
    node.data = 'r';
    y = pStack->player[0];
    x = ++pStack->player[1];
    if (can_move(pStack))
    {
        dot_visited(pStack, x, y, 1);
        pushLS(pStack, node);
        find_path(pStack);
        if(is_end(pStack))
            return ;
        popLS(pStack);
        dot_visited(pStack, x, y, 0);
    }
    pStack->player[1]--;
}

void    move_left(LinkedStack* pStack)
{
    StackNode node;
    int x, y;

    if(is_end(pStack))
        return ;
    node.data = 'l';
    y = pStack->player[0];
    x = --pStack->player[1];
    if (can_move(pStack))
    {
        dot_visited(pStack, x, y, 1);
        pushLS(pStack, node);
        find_path(pStack);
        if(is_end(pStack))
            return ;
        popLS(pStack);
        dot_visited(pStack, x, y, 0);
    }
    pStack->player[1]++;
}

void    move_up(LinkedStack* pStack)
{
    StackNode node;
    int x, y;

    if(is_end(pStack))
        return ;
    node.data = 'u';
    y = --pStack->player[0];
    x = pStack->player[1];
    if (can_move(pStack))
    {
        dot_visited(pStack, x, y, 1);
        pushLS(pStack, node);
        find_path(pStack);
        if(is_end(pStack))
            return ;
        popLS(pStack);
        dot_visited(pStack, x, y, 0);
    }
    pStack->player[0]++;
}

void    move_down(LinkedStack* pStack)
{
    StackNode node;
    int x, y;

    if(is_end(pStack))
        return ;
    node.data = 'd';
    y = ++pStack->player[0];
    x = pStack->player[1];
    if (can_move(pStack))
    {
        dot_visited(pStack, x, y, 1);
        pushLS(pStack, node);
        find_path(pStack);
        if(is_end(pStack))
            return ;
        popLS(pStack);
        dot_visited(pStack, x, y, 0);
    }
    pStack->player[0]--;
}
