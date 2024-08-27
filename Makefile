CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
EX=server

MAIN = tests/4-main.c
DEPS=depend/*.c
OBJS= depend/obj/*.o
HEADERS=include/http.h include/strings.h
SRC = src/0-server.c

all : libsv.a
	$(CC) $(SRC) -L. libsv.a -o $(EX)

libsv.a: $(SRC) $(DEPS)
	$(CC) $(CFLAGS) -c $(DEPS)
	mv *.o depend/obj
	ar rcs libsv.a $(OBJS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(EX) libsv.a

test: $(MAIN)
	$(CC) -g  $(FLAGS) $(MAIN) $(DEPS) -o main

re: fclean all
