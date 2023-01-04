##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC	=	src/main.c	\
		src/research_lib.c  \
		src/research_operation.c    \
		src/research.c	\
		src/sounds.c

OBJ	=	$(SRC:.c=.o)

NAME	=	zarbidex

CFLAGS	=	-I include

CSFMLF	=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFMLF) -g

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	fclean all
