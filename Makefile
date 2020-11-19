##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/intersect.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include

LIB	=	-lm

NAME	=	104intersection

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	rm -f $(NAME)

re:	fclean all
