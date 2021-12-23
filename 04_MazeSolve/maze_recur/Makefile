NAME = mazesolve
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILE = createLinkedStack\
		pushLS\
		popLS\
		deleteLinkedStack\
		isLinkedStackEmpty\
		ft_func\
		ft_func2\
		ft_map_read\
		printMaze\
		showpath\
		find_path\
		move_direction\
		main

INCS = ./includes

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE))) 
OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE))) 

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
