# HTTP-U

A minimal HTTP web server written in raw C, with minimal external library usage.

> [!WARNING]
> The "S" in the repo name stands for memory safety and security :)

## Overview

HTTP-U is a single-threaded, blocking-I/O web server that listens for TCP
connections on port `8089` and serves static assets from the `data/` directory.
It handles socket setup, manual HTTP request parsing, and response generation
using a custom utility library (`libsv.a`).

## Project Structure

| Directory   | Purpose                | Key Files                          |
| :---------- | :--------------------- | :--------------------------------- |
| `src/`      | Server entry point     | `0-server.c`                       |
| `include/`  | Public headers         | `http.h`, `strings.h`              |
| `depend/`   | Implementation modules | `init_server.c`, `strings.c`, ...  |
| `data/`     | Static assets          | `index.html`, `not-found.html`     |

## Building

The project uses a `Makefile`. It first builds a static library `libsv.a`
from the modules in `depend/`, then links the server executable against it.

    mkdir -p depend/obj   # required once: the build moves object files here
    make                  # builds libsv.a and the `server` binary
    make test             # builds the test harness (`main`) from tests/5-main.c
    make clean            # removes object files
    make fclean           # removes objects, the binary, and libsv.a
    make re               # full rebuild

Note: the `test` target expects `tests/5-main.c`, which is not currently
checked into the repository, so `make test` fails until that harness is added.

## Running

    ./server

The server prints `Listening PORT:8089` and serves requests until stopped.

## Request-Response Lifecycle

1. `init_socket` sets up `sockaddr_in` and listens on `PORT` 8089.
2. The main loop calls `accept` for each incoming connection.
3. Raw bytes are parsed into a `request_t` via `strto_request`.
4. `get_fname` maps the route to a file in `data/`.
5. A response is built by `create_response` (using `HEADER_200`/`HEADER_404`)
   and written back to the client.
