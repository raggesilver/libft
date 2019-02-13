FLAGS=-Wall -Werror -Wextra -std=c99
all:
	clear
	gcc $(FLAGS) -o out *.c

clean:
	rm -f *.o *.a out

run:
	./out
