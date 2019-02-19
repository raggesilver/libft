
NAME=libft.a

FLAGS=-Wall -Werror -Wextra

FILES=$(shell find * -name "ft_*.c")

OBJECTS=$(FILES:.c=.o)

INCDIR=.

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I$(INCDIR) -o $@ -c $<

$(NAME): $(OBJECTS)
	ar rc $@ $^
	ranlib $@

check:
	norminette ft_*.c libft.h

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

run:
	./out

re: fclean all

test: all
	gcc -o out test.c -L. -lft
	./out
	rm -f out

.PHONY: all re fclean clean test
.PRECIOUS: author