CC = gcc
CFLAGS = -Wall -g
LIBS = -lsqlite3

multiple_databases: multiple_databases.c
	$(CC) $(CFLAGS) -o multiple_databases multiple_databases.c $(LIBS)

clean:
	rm -f multiple_databases

.PHONY: clean

