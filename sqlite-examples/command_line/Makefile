CC = gcc
CFLAGS = -Wall -g
LIBS = -lsqlite3

command_line: command_line.c
	$(CC) $(CFLAGS) -o command_line command_line.c $(LIBS)

clean:
	rm -f command_line

.PHONY: clean

