# __SRC = ft_array_push.c ft_array.c ft_array_remove.c
# __OBJ = $(__SRC:.c=.o)
# __OBJ := $(addprefix ../../,$(__OBJ))

# ../../%.o: %.c
# 	$(CC) $(FLAGS) -c $(notdir $<) -o $@ $(INCS)

# all: $(__OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $(notdir $<) -o $@ $(INCS)

-include *.d
