# Exclusive Transaction Example

This example demonstrates how to use `BEGIN EXCLUSIVE TRANSACTION` in SQLite.

## Overview

The application:
1. Creates three tables: `table1`, `table2`, and `table3`
2. Begins an exclusive transaction with `BEGIN EXCLUSIVE TRANSACTION`
3. Performs multiple operations within the transaction:
   - Inserts a row into `table1` (x=100)
   - Inserts a row into `table2` (a=20, b=100)
   - Updates `table1` (increments x where y > 10)
   - Inserts a row into `table3` (c1=1, c2=2, c3=3)
4. Commits the transaction with `COMMIT TRANSACTION`
5. Verifies the inserted data

## Exclusive Transaction Behavior

- `BEGIN EXCLUSIVE TRANSACTION` acquires an exclusive lock on the database
- No other database connection can read or write while an exclusive transaction is active
- This ensures complete isolation and prevents any concurrent access
- Useful when you need to ensure no other process interferes with your operations
- The transaction must be committed or rolled back before other connections can access the database

## Building

```bash
make
```

## Running

```bash
./exclusive_transaction
```

## Cleanup

```bash
make clean
```

