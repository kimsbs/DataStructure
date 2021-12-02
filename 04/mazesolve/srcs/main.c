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
	find_path(head);
	showPath(head);
	printMaze(head->map);
	deleteLinkedStack(head);
	//system("leaks mazesolve");
	return (0);
}