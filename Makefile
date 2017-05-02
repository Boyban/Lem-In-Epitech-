CC	=	gcc

NAME	=	lem_in

SRC	=	src/astar.c		\
		src/check_arg.c 	\
		src/get_next_line.c 	\
		src/graph.c 		\
		src/take_path.c 	\
		src/display.c 		\
		src/main.c		\
		src/basic_tools.c	\
		src/parseur.c		\
		src/my_getnbr.c		\
		src/tools_finish.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/ -W -Wall -Wextra -pedantic

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:	$(OBJ)

		$(CC) -o $(NAME) $(OBJ)

clean	:

		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
