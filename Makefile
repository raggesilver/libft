
CC = gcc
NAME = libft.a

# Comment for normal executable
IS_LIB=true

SRCDIR := src
BUILD_DIR := build

SRCS := $(shell find $(SRCDIR) -type f -name "*.c")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

HEADDIR := includes
HEAD := $(shell find $(SRCDIR) -name "*.h" -and ! -name "*_priv.h")
HEAD := $(subst $(SRCDIR),$(HEADDIR),$(HEAD))

_INC := $(shell find $(SRCDIR) -type d)
INCS := $(addprefix -I,$(_INC))

FLAGS = -Wall -Werror -Wextra

CFLAGS = $(FLAGS) -MMD -MP

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
ifdef IS_LIB
	ar rc $@ $(OBJS)
	ranlib $@
else
	$(CC) $(FLAGS) -o $@ $(OBJS) $(INCS)
endif

$(HEADDIR)/%.h:
	@mkdir -p $(dir $@)
	cp $(subst $(HEADDIR),$(SRCDIR),$@) $@

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -fr $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(HEADDIR)

re: fclean all

debug: FLAGS += -g
debug: fclean all

ci:
	@make -C tests ci

-include $(DEPS)
