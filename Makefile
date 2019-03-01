##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for compilation
##

UT_DIR	=	./tests/

UT_SRC	=	$(UT_DIR)test.c\

UT	=	units

SRC_DIR	=	./src/

SRC	=	$(SRC_DIR)realloc.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)malloc.c \
		$(SRC_DIR)free.c \
		$(SRC_DIR)show_alloc_mem.c

CFLAGS	=	-W -Wall -Wextra -Werror

LDFLAGS	=  -lcriterion -lgcov --coverage -fprofile-arcs -ftest-coverage

OBJ	=	$(SRC:.c=.o)

MAIN = main.c

NAME	=	libmy_malloc.so


all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -fPIC -shared
	rm -f $(OBJ)

gdb:
	g++ -o $(NAME) $(SRC) $(MAIN) $(CFLAGS) -g3

tests_run:
	gcc -o $(UT) $(UT_SRC) $(LDFLAGS)
	./$(UT)

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f $(OBJ)
		rm -f $(UT_DIR)*.gcno
		rm -f $(UT_DIR)*.gcda
		rm -f $(UT_DIR)*~
		rm -f $(SRC_DIR)*.gcno
	    rm -f $(SRC_DIR)*.gcda
	    rm -f $(SRC_DIR)*~
	    rm -f *.gcno
	    rm -f *.gcda
	    rm -f *~

re: 	fclean all
