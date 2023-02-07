CC = gcc
CFLAGS = -m32 -g -pthread -Wall -fsanitize=address,undefined -std=c99
LDFLAGS = -m32
objects = stack bitops threads
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<