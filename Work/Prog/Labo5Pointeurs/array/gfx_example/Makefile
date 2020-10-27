CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -g -fsanitize=leak -fsanitize=undefined  -fsanitize=address
LIBS=-lSDL2
 

all: gfx_example

gfx_example: gfx_example.c gfx.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f gfx_example
