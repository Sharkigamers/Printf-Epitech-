##
## EPITECH PROJECT, 2018
## Makefile_lib
## File description:
## Makefile wich will compile the lib
##

SRC	=	lib/my_putchar.c	\
		lib/my_putstr.c	\
		lib/my_put_nbr.c	\
		lib/my_binary.c	\
		lib/my_octal.c	\
		lib/my_hexa.c	\
		lib/my_sup_hexa.c	\
		lib/my_strlen.c	\
		lib/my_strcpy.c	\
		lib/my_revstr.c	\
		lib/unsigned_putnbr.c	\
		lib/my_put_long_nbr.c	\
		lib/my_put_longlong_nbr.c	\
		lib/my_put_short_nbr.c	\
		lib/my_put_char_nbr.c 	\
		lib/my_long_hexa.c	\
		src/basic_flags.c	\
		src/my_printf.c	\
		src/length_modifier.c	\
		src/non_printable_flag.c	\
		src/basic_hashtag_flags.c	\
		test/unit_test.c	\

OBJ 	=	$(SRC:.c=.o)

CPPFLAGS	=	-I ./include/

UFLAGS	=	-lcriterion --coverage

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

uni:
	gcc -o unit-tests test/unit_test.c libmy.a $(CPPFLAGS) $(UFLAGS)
	./unit-tests

clean:
	rm -f $(OBJ)

uclean:
	rm -f *.gc*
	rm -f *.gc*
	rm -f unit-tests

fclean: clean
	rm -f $(OBJ)
	rm -f a.out

re:	fclean all

.PHONY: all clean fclean re
