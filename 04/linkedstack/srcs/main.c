#include "linkedstack.h"

void	showLS(LinkedStack *pStack)
{
	StackNode *move;

	if(!pStack)
		return ;
	move = pStack->pTopElement;
	while(move)
	{
		printf("%c ", move->data);
		move = move->pLink;
	}
	printf("\n");
}

int		main(void)
{
	LinkedStack *stack;
	StackNode *peek;
	StackNode *pop;
	StackNode tmp;
	char data;
	char c;

	stack = createLinkedStack();
	while(1)
	{
		printf("put Push pOp pEek Delete Show: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'P':
			printf("put data : ");
			scanf(" %c", &data);
			tmp.data = data;
			pushLS(stack, tmp);
			break;
		case 'O':
			pop = popLS(stack);
			if(pop)
			{
				printf("%c\n", pop->data);
				free(pop);
			}
			break;
		case 'E':
			peek = peekLS(stack);
			if(peek)
				printf("%c\n", peek->data);
			break;
		case 'S':
			showLS(stack);
			break;
		case 'D':
			deleteLinkedStack(stack);
			system("leaks linkedstack");
			return (0);
			break;
		default:
			break;
		}
	}
	return (0);
}