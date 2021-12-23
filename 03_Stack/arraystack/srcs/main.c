#include "arraystack.h"

void	showAS(ArrayStack *arr)
{
	int move = 0;
	while(move < arr->currentElementCount)
	{
		printf("%c ", arr->pElement[move].data);
		move++;
	}
	printf("\n");
}

int		main(void)
{
	char c;
	int  maxsize;
	char  data;
	ArrayStack *arrstack;
	ArrayStackNode *poped;
	ArrayStackNode *peeked;
	ArrayStackNode tmp;

	printf("put maxsize : ");
	scanf("%d", &maxsize);
	arrstack = createArrayStack(maxsize);

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
			if(pushAS(arrstack, tmp))
				printf("%c is pushed\n", data);
			break;
		case 'O':
			poped = popAS(arrstack);
			if(poped)
			{
				printf("%c\n", poped->data);
				free(poped);
			}
			break;
		case 'E':
			peeked = peekAS(arrstack);
			if(peeked)
			{
				printf("%c\n", peeked->data);
				free(peeked);
			}
			break;
		case 'S':
			showAS(arrstack);
			break;
		case 'D':
			deleteArrayStack(arrstack);
			system("leaks arraystack");
			return (0);
			break;
		default:
			break;
		}
	}
	return (0);
}