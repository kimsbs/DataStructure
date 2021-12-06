#include "mazesolve.h"

static void	init_data(LinkedStack *head)
{
	int y, x;
	head->hor = ft_strlen(head->map[0]);
	while(head->map[head->ver])
        head->ver++;
	for(y = 0 ; y < head->ver ; y++)
	{
		for(x = 0 ; x < head->hor ; x++)
		{
			//i = y , j == x
			if(head->map[y][x] == 'S')
			{
				head->player[0] = y;
				head->player[1] = x;
			}
			else if(head->map[y][x] == 'E')
			{
				head->end[0] = y;
				head->end[1] = x;
			}
		}
	}
}

void	read_map(LinkedStack *head, char *name)
{
	int fd, len;
	char buf[513], *tmp;

	fd = open(name, O_RDONLY);
	if(fd <= 0)
		exit(-1);
	tmp = NULL;
	while( (len = read(fd, &buf, 512)) > 0)
	{
		buf[len] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	head->map = ft_split(tmp, '\n');
	free(tmp);
	init_data(head);
	close(fd);
}