CC = clang -c -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc

all: LIBMX library

LIBMX:
	mkdir obj
	$(CC) src/*.c
	mv *.o obj/

library:
	ar -rc libmx.a obj/*.o
	ranlib libmx.a

clean:
	rm -rf obj

uninstall:
	rm -rf obj
	rm -rf libmx.a

reinstall:
	make uninstall
	make
