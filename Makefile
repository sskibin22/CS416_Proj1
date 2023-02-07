CC = gcc
CFLAGS = -g -pthread -Wall -fsanitize=address,undefined -std=c99
objects = stack bitops threads
all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<