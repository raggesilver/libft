
MAKE := $(MAKE) --no-print-directory
NAME := libft.a
CC ?= gcc

CFLAGS := -Wall -Werror -Wextra -Ofast

OBJDIR := build
SRCDIR := src
HEADIR := includes

SRCS := $(shell find $(SRCDIR) -type f -name "*.c" $(DISABLED))
OBJS := $(SRCS:%=$(OBJDIR)/%.o)
DEPS := $(SRCS:%=$(OBJDIR)/%.d)

HEAD := $(shell find $(SRCDIR) -name "*.h" -and ! -name "*_priv.h")
HEAD := $(subst $(SRCDIR),$(HEADIR),$(HEAD))

LIBS :=
LIBINCS := $(foreach lib,$(LIBS),-I$(dir $(lib))includes)

.PHONY: all re clean fclean debug $(LIBS) _$(NAME)

all: _$(NAME) Makefile

_$(NAME): $(LIBS) Makefile
	@$(MAKE) $(NAME)

$(NAME): $(HEAD) $(OBJS) Makefile
	ar rc $@ $(OBJS) $(LIBS)
	ranlib $@

$(OBJDIR) $(HEADIR):
	@mkdir -p $@

-include $(DEPS)

$(OBJDIR)/%.c.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(LIBINCS)

$(HEADIR)/%.h: Makefile
	@mkdir -p $(dir $@)
	cp $(subst $(HEADIR),$(SRCDIR),$@) $@

$(LIBS): Makefile
	@$(MAKE) -C $(dir $@) $(MAKECMDGOALS)

clean:
	@$(foreach dep, $(LIBS), $(MAKE) -C $(dir $(dep)) clean;)
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -rf $(OBJDIR)

fclean: clean
	@$(foreach dep, $(LIBS), $(MAKE) -C $(dir $(dep)) fclean;)
	rm -f $(NAME)
	rm -rf $(HEADIR)

re: fclean
	@$(MAKE) all

debug:
	@$(MAKE) all CFLAGS="$(filter-out -Ofast,$(CFLAGS)) -g -O0"

ci:
	@$(MAKE) -C tests ci
