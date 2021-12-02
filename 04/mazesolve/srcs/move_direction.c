#include "mazesolve.h"

void    move_right(LinkedStack* pStack)
{
    StackNode node;
    int x, y;
    node.data = 'r';
    y = pStack->player[0];
    x = ++pStack->player[1];
    if (can_move(pStack))
    {
        pStack->map[y][x] = '2';
        pushLS(pStack, node);
        find_path(pStack);
        if(is_end(pStack))
            return ;
        popLS(pStack);
        pStack->map[y][x] = '0';
    }
    pStack->player[1]--;
}

void    move_left(LinkedStack* pStack)
{
    StackNode node;
    int x, y;
    node.data = 'l';
    y = pStack->player[0];
    x = --pStack->player[1];
    if (can_move(pStack))
    {
        pStack->map[y][x] = '2';
        pushLS(pStack, node);
        find_path(pStack);
        if(is_end(pStack))
            return ;
        popLS(pStack);
        pStack->map[y][x] = '0';
    }
    pStack->player[1]++;
}

void    move_up(LinkedStack* pStack)
{
    int x, y;
    StackNode node;
    node.data = 'u';
    y = --pStack->player[0];
    x = pStack->player[1];
    if (can_move(pStack))
    {
        pStack->map[y][x] = '2';
        pushLS(pStack, node);
        find_path(pStack);
        if(is_end(pStack))
            return ;
        popLS(pStack);
        pStack->map[y][x] = '0';
    }
    pStack->player[0]++;
}

void    move_down(LinkedStack* pStack)
{
    StackNode node;
    int x, y;
    node.data = 'd';
    y = ++pStack->player[0];
    x = pStack->player[1];
    if (can_move(pStack))
    {
        pStack->map[y][x] = '2';
        pushLS(pStack, node);
        find_path(pStack);
        if(is_end(pStack))
            return ;
        popLS(pStack);
        pStack->map[y][x] = '0';
    }
    pStack->player[0]--;
}
