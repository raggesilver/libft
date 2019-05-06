# Name here
NAME=libft_test
REC=true
CC=gcc
FLAGS=-Wall -Werror -Wextra

# Sources here
SRC=main.c
OBJ=$(SRC:.c=.o)

PRESCRIPTS=link.sh

# Dependencies here (.a files)
# Make sure those dependencies' directories are on your project's root
# i.e: dep = libft.a
# tree: . .. libft/ Makefile #...
DEP=libft.a
DDEP=$(DEP:.a=)
FDEP=$(foreach DP, $(DDEP), -L$(DP) -l$(subst lib,,$(DP)))
DEPS=$(foreach DP, $(DEP), $(DP:.a=)/$(DP))

INCS=$(foreach lib, $(DDEP), -I $(lib)/includes)

.PHONY: $(NAME) pre re fclean clean run debug ci all

all: pre $(NAME)

pre:
	$(foreach ps, $(PRESCRIPTS), ./$(ps))

$(NAME):
	$(foreach dep, $(DDEP), make -C $(dep))
	$(CC) $(FLAGS) $(SRC) $(DEPS) -o $@ $(INCS) $(FDEP)

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

TEST_ARGS=
TEST_FLAGS=--error-exitcode=1 --leak-check=full

ci: re
	valgrind $(TEST_FLAGS) ./$(NAME) $(TEST_ARGS)
