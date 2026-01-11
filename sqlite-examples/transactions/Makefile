CC = gcc
CFLAGS = -Wall -g
LIBS = -lsqlite3

transactions: transactions.c
	$(CC) $(CFLAGS) -o transactions transactions.c $(LIBS)

clean:
	rm -f transactions

.PHONY: clean

