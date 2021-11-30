#include "mazesolve.h"

int		main(int argc, char **argv)
{
	LinkedStack *head;
	if(argc != 2)
	{
		printf("input : [./mazesolve] [map.ber]");
		return (0);
	}
	head = createLinkedStack();
	read_map(head, argv[1]);

	printf("hor : %d, ver : %d\n", head->hor, head->ver);
	printf("player y : %d, player x : %d\n", head->player[0], head->player[1]);
	printf("end y : %d, end x : %d\n", head->end[0], head->end[1]);
	printMaze(head->map);
	return (0);
}