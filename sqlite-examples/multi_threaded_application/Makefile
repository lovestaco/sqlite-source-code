CC = gcc
CFLAGS = -Wall -g -pthread
LIBS = -lsqlite3 -lpthread

multi_threaded: multi_threaded.c
	$(CC) $(CFLAGS) -o multi_threaded multi_threaded.c $(LIBS)

clean:
	rm -f multi_threaded MyDB.db

.PHONY: clean

