# SQLite Example

A simple command-line SQLite application that executes SQL statements and displays results.

## Compilation

```bash
make
```

Or manually:
```bash
gcc -Wall -g -o command_line command_line.c -lsqlite3
```

## Usage

```bash
./command_line test.db "select * from name"
```

## Examples

Create a test database and table:
```bash
./command_line test.db "CREATE TABLE users (id INTEGER PRIMARY KEY, name TEXT, email TEXT)"
```

Insert data:
```bash
./command_line test.db "INSERT INTO users (name, email) VALUES ('Alice', 'alice@example.com')"
./command_line test.db "INSERT INTO users (name, email) VALUES ('Bob', 'bob@example.com')"
```

Query data:
```bash
./command_line test.db "SELECT * FROM users"
```

