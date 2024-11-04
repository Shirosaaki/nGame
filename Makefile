##
## EPITECH PROJECT, 2024
## proc
## File description:
## proc
##

NAME	=	process

SRC		=	main.c			\
			gen.c			\
			print.c			\
			gen_all_map.c	\
			game.c

OBJ	=	$(SRC:.c=.o)

all: $(OBJ)
	make -C nlib
	gcc -o $(NAME) $(OBJ) -lncurses -L. -lnc

clean:
	make clean -C nlib
	rm -f $(OBJ)

fclean: clean
	make fclean -C nlib
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)