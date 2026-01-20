CC = gcc
CFLAGS = -Wall -g
LIBS = -lsqlite3

exclusive_transaction: exclusive_transaction.c
	$(CC) $(CFLAGS) -o exclusive_transaction exclusive_transaction.c $(LIBS)

clean:
	rm -f exclusive_transaction exclusive_transaction.db

.PHONY: clean

