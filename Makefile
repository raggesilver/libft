
NAME=libft.a

FLAGS=-Wall -Werror -Wextra

FILES=$(shell find * -name "ft_*.c")
_FILES=ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_test.c \
	  ft_tolower.c \
	  ft_toupper.c

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