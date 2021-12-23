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
	head->max_move = head->hor * head->ver;
	printMaze(head->map);
	find_path(head);
	showLS(head);
	printMaze(head->map);
	deleteLinkedStack(head);
	//system("leaks mazesolve");
	return (0);
}