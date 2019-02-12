FLAGS=-Wall -Werror -Wextra -std=c99
all:
	gcc $(FLAGS) -o out *.c
	./out
	norminette `find . ! \( -name "*test*" \) -name "*.c" -o -name "*.h"`

clean:
	rm -f *.o *.a out