#include "mazesolve.h"

void    dot_visited(LinkedStack* pStack, int x, int y, int flag)
{
    if(flag && pStack->map[y][x] != 'E')
        pStack->map[y][x] = '2';
    if(!flag && pStack->map[y][x] != 'E')
        pStack->map[y][x] = '0';
}

void    same_func(LinkedStack* pStack, LinkedStack* sol, StackNode node, int x, int y)
{
    if (can_move(pStack))
    {
        dot_visited(pStack, x, y, 1);
        pushLS(pStack, node);
        find_path(pStack, sol);
        popLS(pStack);
        dot_visited(pStack, x, y, 0);
    }
}

void    move_right(LinkedStack* pStack, LinkedStack* sol)
{
    StackNode node;
    int x, y;

    node.data = 'r';
    y = pStack->player[0];
    x = ++pStack->player[1];
    same_func(pStack, sol, node, x, y);
    pStack->player[1]--;
}

void    move_left(LinkedStack* pStack, LinkedStack* sol)
{
    StackNode node;
    int x, y;

    node.data = 'l';
    y = pStack->player[0];
    x = --pStack->player[1];
    same_func(pStack, sol, node, x, y);
    pStack->player[1]++;
}

void    move_up(LinkedStack* pStack, LinkedStack* sol)
{
    StackNode node;
    int x, y;

    node.data = 'u';
    y = --pStack->player[0];
    x = pStack->player[1];
    same_func(pStack, sol, node, x, y);
    pStack->player[0]++;
}

void    move_down(LinkedStack* pStack, LinkedStack* sol)
{
    StackNode node;
    int x, y;

    node.data = 'd';
    y = ++pStack->player[0];
    x = pStack->player[1];
    same_func(pStack, sol, node, x, y);
    pStack->player[0]--;
}
