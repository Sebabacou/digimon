##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-I include

CSFMLF	=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFMLF) -g

clean:
	rm -f *o
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	fclean all
