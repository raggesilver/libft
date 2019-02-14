FLAGS=-Wall -Werror -Wextra -std=c99
all:
	clear
	gcc $(FLAGS) -o out *.c

check:
	norminette ft_*.c libft.h

clean:
	rm -f *.o *.a

fclean:
	rm -f out

run:
	./out
