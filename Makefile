##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/strlen.asm	\
		src/strchr.asm	\
		src/strrchr.asm	\
		src/memset.asm	\
		src/memcpy.asm	\
		src/strcmp.asm	\
		src/memmove.asm	\
		src/strncmp.asm	\
		src/strpbrk.asm	\
		src/strcasecmp.asm	\
		src/strstr.asm	\
		src/strcspn.asm	\
		src/memfrob.asm

NAME	=	libasm.so

OBJ	=	$(SRC:.asm=.o)

all:	$(NAME)

%.o:	%.asm
	nasm -f elf64 -o $@ $<

$(NAME):	$(OBJ)
	ld -shared -fPIC -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f src/*~
	rm -f *vgcore*

fclean:	clean
	rm -f $(NAME)
	make fclean -C./tests

re:	fclean all

tests_run: re
	make -C./tests
	./unit_tests

.PHONY: all clean fclean re tests_run
