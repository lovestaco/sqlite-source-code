# Working with Transactions

This example demonstrates how to work with transactions in SQLite.

## Overview

The application:
1. Opens a database named `MyDB`
2. Attaches another database `MyDBExtn` as `DB1`
3. Begins a transaction with `begin`
4. Inserts one row into the `Students` table (SID = 2000)
5. Inserts one row into the `Courses` table ('SQLite Database', 2000)
6. Commits the transaction with `commit`
7. Closes the database

## Transaction Behavior

- If the second insert fails, you can execute `rollback` instead of `commit`, and the first insert will be undone
- INSERT statements do not need a callback function, so `0` is passed as the callback argument
- SQLite permits multiple SQL statements in a single `exec` API call
- The same batch of commands can be executed by passing this sequence in a single exec call:
  ```
  "begin; insert into Students values(2000); insert into Courses values('SQLite Database', 2000); commit"
  ```
- If the batch contains SELECT statements, the same callback function is used to process the resulting rowsets

## Building

```bash
make
```

## Running

Before running, ensure you have:
- `MyDB` database with a `Students(SID)` table
- `MyDBExtn` database with a `Courses(name, SID)` table

You can use the setup script from the `multiple_databases` example to create these databases.

Then run:
```bash
./transactions
```

## Cleanup

```bash
make clean
```

