#ifndef _MAZE_SOLVE_
#define _MAZE_SOLVE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct StackNodeType
{
	char data;
	int	x;
	int y;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int max_move;
	int	hor;
	int	ver;
	
	int player[2]; // 0 : y , 1 : x;
	int	end[2]; // 0 : y , 1 : x;
	int	flag;
	
	char **map;
	StackNode* pTopElement;
} LinkedStack;

LinkedStack* createLinkedStack();
int 	pushLS(LinkedStack* pStack, StackNode element);
int 	popLS(LinkedStack* pStack);
void 	deleteLinkedStack(LinkedStack* pStack);
int 	isLinkedStackEmpty(LinkedStack* pStack);
void	find_path(LinkedStack* pStack);
void	printMaze(char **map);
void 	showLS(LinkedStack* pStack);

int     can_move(LinkedStack* pStack, int x, int y);

//map_read
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	read_map(LinkedStack *head, char *name);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif