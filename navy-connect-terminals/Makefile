##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC =		src/fill_map.c	\
		src/creat_map.c	\
		src/game.c	\
		src/outpouts.c	\
		src/atak.c	\
		src/main.c

OBJ = 		$(SRC:.c=.o)

NAME =		navy

CFLAGS += 	-I include/

LIB = 		-L lib -lmy -g3

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(LIB)
		rm $(OBJ)
		make clean -C lib/my

clean :
		make clean -C lib/my
		rm -f $(OBJ) *~
		cd src/ && rm -f $(OBJ) *~

fclean :	clean
		make fclean -C lib/my
		rm -f $(NAME)

re :		$(OBJ)
		make re -C lib/my
		gcc -o $(NAME) $(OBJ) $(LIB)
