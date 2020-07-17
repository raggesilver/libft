
MAKE := $(MAKE) --no-print-directory
NAME := libft.a
CC ?= gcc

CFLAGS := -Wall -Werror -Wextra -Ofast

include config/config.mk

OBJDIR := build
SRCDIR := src
HEADIR := includes

SRCS := $(shell find $(SRCDIR) -type f -name "*.c" $(DISABLED))
OBJS := $(SRCS:%=$(OBJDIR)/%.o)
DEPS := $(SRCS:%=$(OBJDIR)/%.d)

HEAD := $(shell find $(SRCDIR) -name "*.h" -and ! -name "*_priv.h")
HEAD := $(subst $(SRCDIR),$(HEADIR),$(HEAD))
HEAD := $(HEAD) $(HEADIR)/ft_version.h

LIBS :=
LIBINCS := $(foreach lib,$(LIBS),-I$(dir $(lib))includes)

.PHONY: all re clean fclean debug $(LIBS) _$(NAME)

all: _$(NAME) Makefile

_$(NAME): $(LIBS) Makefile
	@$(MAKE) $(NAME)

$(NAME): $(HEAD) $(OBJS) Makefile
	@ar rc $@ $(OBJS) $(LIBS)
	@ranlib $@
	@echo "Compiled $(@) version $(VERSION)"

$(OBJDIR) $(HEADIR):
	@mkdir -p $@

-include $(DEPS)

$(OBJDIR)/%.c.o: %.c Makefile $(HEADIR)/ft_version.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(HEADIR) -MMD -MP -c $< -o $@ $(LIBINCS)

$(HEADIR)/%.h: Makefile
	@mkdir -p $(dir $@)
	cp $(subst $(HEADIR),$(SRCDIR),$@) $@

$(HEADIR)/ft_version.h: Makefile $(SRCDIR)/ft_version.h.in
	@echo Configuring $@
	@mkdir -p $(dir $@)
	@cp $(SRCDIR)/ft_version.h.in $@
	@sed -i 's/@VERSION@/$(VERSION)/g' $@
	@sed -i 's/@VERSION_MAJOR@/$(VERSION_MAJOR)/g' $@
	@sed -i 's/@VERSION_MINOR@/$(VERSION_MINOR)/g' $@
	@sed -i 's/@VERSION_PATCH@/$(VERSION_PATCH)/g' $@

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
