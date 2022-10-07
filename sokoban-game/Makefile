##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC =		src/core_game.c		\
		src/key_finder.c	\
		src/key_moves.c		\
		src/outpouts.c		\
		src/storage_manager.c	\
		src/false_map.c		\
		src/all_boolz.c		\
		src/main.c

OBJ = 		$(SRC:.c=.o)

NAME =		my_sokoban

CFLAGS += 	-I include/ -g3

LIB = 		-L lib -lncurses -lmy

DONE =          echo -e "\033[01m\033[32mCompilation done => ${NAME}\033[00m"

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(LIB)
		rm $(OBJ)
		make clean -C lib/my
		$(DONE)

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
		$(DONE)
