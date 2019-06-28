
NAME := libft.a
# CC ?= gcc

CFLAGS := -Wall -Werror -Wextra -Ofast

OBJDIR := build
SRCDIR := src
HEADIR := includes

SRCS := $(shell find $(SRCDIR) -type f -name "*.c")
OBJS := $(SRCS:%=$(OBJDIR)/%.o)

HEAD := $(shell find $(SRCDIR) -name "*.h" -and ! -name "*_priv.h")
HEAD := $(subst $(SRCDIR),$(HEADIR),$(HEAD))

LIBS :=
LIBINCS := $(foreach lib,$(LIBS),-I$(dir $(lib))includes)

# This might not be necessary
# _INC := $(shell find $(SRCDIR) -type d)
# INCS := $(addprefix -I,$(_INC))

.PHONY: all re clean fclean debug $(LIBS) _$(NAME)

all: _$(NAME)

_$(NAME): $(LIBS)
	@$(MAKE) $(NAME)

$(NAME): $(HEADIR) $(HEAD) $(OBJDIR) $(OBJS)
	libtool -static -o $@ $(OBJS) $(LIBS)
	ranlib $@

$(OBJDIR) $(HEADIR):
	@mkdir -p $@

$(OBJDIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBINCS)

$(HEADIR)/%.h:
	@mkdir -p $(dir $@)
	cp $(subst $(HEADIR),$(SRCDIR),$@) $@

$(LIBS):
	@$(MAKE) -C $(dir $@) $(MAKECMDGOALS)

clean:
	@$(foreach dep, $(LIBS), $(MAKE) -C $(dir $(dep)) clean)
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	@$(foreach dep, $(LIBS), $(MAKE) -C $(dir $(dep)) fclean)
	rm -f $(NAME)
	rm -rf $(HEADIR)

re: fclean
	@$(MAKE) all

debug: fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) -g"

ci:
	@$(MAKE) -C tests ci
