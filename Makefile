##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile cleaned by the code review
##

NAME =		ai

SRC = 		main.c			\
		loop.c			\
		basic_command.c		\
		more_basic_command.c

OBJ = 		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS = 	-iquote ./include

LD_LIBRARY_PATH = -L.

LDFLAGS  =	-lm	\
		-lmy

LIB_PATH = 	./lib/my

all:    $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o $(NAME) $(OBJ) $(LD_LIBRARY_PATH) $(LDFLAGS)

test:
	make re
	cp ai n4s_package/
	cd n4s_package;./pipes.sh

clean:
	rm -f $(OBJ)
	rm -f libmy.a
	rm -f lib/my/libmy.a

fclean: clean
	rm -f $(NAME)
	rm -f n4s_package/$(NAME)

re: fclean all

.PHONY = all, clean, fclean, re
