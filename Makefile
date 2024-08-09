CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
EXECS=server
EXECC=client

DEPS=src/string_functions.c src/fetch_request.c src/init_server.c
HEADERS=header/http.h header/strings.h
SRCS = src/2-server.c
SRCC = src/2-client.c
MAIN = test/0-main.c
HEADER = http.h

build:
	$(CC) $(CFLAGS) $(DEPS) $(HEADERS) $(SRCS) -o $(EXECS)
	$(CC) $(CFLAGS) $(DEPS) $(SRCC) $(HEADERS) -o $(EXECC)

clean:
		rm $(EXECS)
		rm $(EXECC)
main:
	$(CC) $(CFLAGS) $(MAIN) -o main
