# Multithreaded SQLite Application

This is a multithreaded application that demonstrates concurrent database operations using SQLite and pthreads.

## Description

The application creates 10 threads, each of which:
- Opens a connection to the SQLite database `MyDB.db`
- Inserts a value (thread ID) into the `Students` table
- Closes the database connection

## Building

```bash
make
```

## Running

```bash
./multi_threaded
```

## Cleaning

```bash
make clean
```

This will remove the executable and the database file.

## Notes

- The main thread creates the database and `Students` table before spawning worker threads
- Each thread opens its own database connection
- SQLite handles thread-safety, but each thread uses its own connection for better concurrency

