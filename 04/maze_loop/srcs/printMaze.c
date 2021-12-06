#include "mazesolve.h"

void	printMaze(char **map)
{
    int move = 0;
    while(map[move])
    {
        printf("%s\n", map[move]);
        move++;
    }
}