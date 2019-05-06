
# Name here
NAME=libft.a
CC=gcc
FLAGS=-Wall -Werror -Wextra

REC=true
SLIB=true

# Sources here
SRC=ft_atoi.c \
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
	ft_strchrcnt.c \
	ft_file.c
OBJ=$(SRC:.c=.o)

PRESCRIPTS=

# Dependencies here (.a files)
# Make sure those dependencies' directories are on your project's root
# i.e: dep = libft.a
# tree: . .. libft/ Makefile #...
DEP=
DDEP=$(DEP:.a=)
FDEP=$(foreach DP, $(DDEP), -L$(DP) -l$(subst lib,,$(DP)))
DEPS=$(foreach DP, $(DEP), $(DP:.a=)/$(DP))

INCS=$(foreach lib, $(DDEP), -I $(lib)/includes)

.PHONY: all re fclean clean $(NAME) pre

all: pre $(NAME)

pre:
	$(foreach ps, $(PRESCRIPTS), ./$(ps))

$(NAME):
	$(foreach dep, $(DDEP), make -C $(dep))
ifdef SLIB
	$(CC) $(FLAGS) -c $(SRC) $(DEPS) $(INCS) $(FDEP)
	ar rc $@ $(OBJ)
	ranlib $@
else
	$(CC) $(FLAGS) $(SRC) $(DEPS) -o $@ $(INCS) $(FDEP)
endif

clean:
ifdef REC
	@$(foreach dep, $(DDEP), make -C $(dep) clean)
endif
	rm -f $(OBJ)

fclean: clean
ifdef REC
		@$(foreach dep, $(DDEP), make -C $(dep) fclean)
endif
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

debug: FLAGS += -g
debug: fclean all

# TEST_ARGS=
# TEST_FLAGS=--error-exitcode=1 --leak-check=full

ci:
	@make -C tests ci
