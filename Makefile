
NAME=libft.a

FLAGS=-Wall -Werror -Wextra -g

FILES=ft_atoi.c \
	  ft_bzero.c \
	  ft_int_len.c \
	  ft_int_len_base.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_itoa_base.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_realloc.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strdupchr.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strndup.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_lstcnt.c \
	  ft_lstappend.c \
	  ft_lst_set_head_index.c \
	  ft_lst_sort.c \
	  ft_sqrt_ceil.c \
	  ft_strchrcnt.c

HEADERS=libft.h
OBJECTS=$(FILES:.c=.o)

INCDIR=includes

all: $(NAME)

$(NAME): $(INCDIR)
	$(foreach hd, $(HEADERS), cp $(hd) $(INCDIR))
	gcc $(FLAGS) -c $(FILES)
	ar rc $@ $(OBJECTS)
	ranlib $@

$(INCDIR):
	@mkdir -p $@

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
