#include "mazesolve.h"

int		main(int argc, char **argv)
{
	LinkedStack *head;
	LinkedStack *sol;

	if(argc != 2)
	{
		printf("input : [./mazesolve] [map.ber]");
		return (0);
	}
	head = createLinkedStack();
	sol = createLinkedStack();
	read_map(head, argv[1]);
	head->max_move = head->hor * head->ver;
	find_path(head, sol);
	printf("Shortcut : ");
	showPath(sol);
	printMaze(head->map);
	deleteLinkedStack(head);
	//system("leaks mazesolve");
	return (0);
}