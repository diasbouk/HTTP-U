CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
EXECS=server
EXECC=client

DEPS=depend/string_functions.c depend/fetch_request.c depend/init_server.c
HEADERS=header/http.h header/strings.h
SRCS = src/0-server.c
SRCC = src/0-client.c
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
