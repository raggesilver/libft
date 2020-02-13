
MAKE := $(MAKE) --no-print-directory
NAME := libft.a
CC ?= gcc

CFLAGS := -Wall -Werror -Wextra -Ofast
FINAL_FLAGS :=

include config/config.mk

SHARED_NAME := $(NAME:%.a=%.so)
SHARED_VNAME := $(NAME:%.a=%).$(VERSION).so

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

.PHONY: all re clean fclean debug $(LIBS) _$(NAME) shared

all: _$(NAME) Makefile

_$(NAME): $(LIBS) Makefile
	@$(MAKE) $(NAME)

$(NAME): $(HEAD) $(OBJS) Makefile
	@ar rc $@ $(OBJS) $(LIBS)
	@ranlib $@
	@echo "Compiled $(@) version $(VERSION)"

# General rule for libft.so and libft.VERSION.so
shared: $(LIBS) Makefile
	@$(MAKE) $(NAME:%.a=%.so)

# Rule for libft.so and libft.VERSION.so
$(NAME:%.a=%.so): $(HEAD) $(OBJS) Makefile
	@$(CC) $(CFLAGS) $(FINAL_FLAGS) $(OBJS) $(LIBS) -shared -o _$@
	@mv _$@ $(@:%.so=%).$(VERSION).so
	@rm -f $@
	@ln -s $(@:%.so=%).$(VERSION).so $@
	@echo "Compiled $(@) version $(VERSION)"

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
	rm -f $(NAME:%.a=%.so)
	rm -f $(NAME:%.a=%).$(VERSION).so
	rm -rf $(HEADIR)

re: fclean
	@$(MAKE) all

debug:
	@$(MAKE) all CFLAGS="$(filter-out -Ofast,$(CFLAGS)) -g -O0"

install:
	@$(MAKE) shared
	cp -r $(HEADIR) $(PREFIX)/include/$(basename $(NAME))
	cp $(SHARED_VNAME) $(PREFIX)/lib
	cd $(PREFIX)/lib && ln -s $(SHARED_VNAME) $(SHARED_NAME)
	@echo "$(basename $(NAME)) installed"

ci:
	@$(MAKE) -C tests ci
