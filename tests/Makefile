##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC_TEST	=	minilibc_tests.c

OBJ_TEST	=	$(SRC_TEST:.c=.o)

SRC	=	../src/strlen.asm	\
		../src/strchr.asm	\
		../src/strrchr.asm	\
		../src/memset.asm	\
		../src/memcpy.asm	\
		../src/strcmp.asm	\
		../src/memmove.asm	\
		../src/strncmp.asm	\
		../src/strpbrk.asm	\
		../src/strcasecmp.asm	\
		../src/strstr.asm	\
		../src/strcspn.asm	\
		../src/memfrob.asm

OBJ	=	$(SRC:.asm=.o)

NAME =	unit_tests

TESTFLAGS =	--coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ_TEST) $(OBJ)
	gcc -o $(NAME) $(OBJ_TEST) $(OBJ) $(TESTFLAGS) -ldl
	cp unit_tests ../
# -ldl for linking else dlopen, dlsym and dlclose don't work

clean:
	rm -f $(NAME)
	rm -f ../$(NAME)

fclean:	clean
	rm -f unit_tests
	rm -f *~
	rm -f *.gc*
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)

re:	fclean all

.PHONY: all clean fclean re
