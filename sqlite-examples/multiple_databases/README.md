# Working with Multiple Databases

This example demonstrates how to work with multiple SQLite databases using a single library connection.

## Overview

The application:
1. Opens a database named `MyDB`
2. Attaches another database `MyDBExtn` as `DB1`
3. Executes a SELECT query that joins tables from both databases:
   - `Students(SID)` table from `MyDB`
   - `Courses(name, SID)` table from `MyDBExtn`

## Library Connection vs. Database Connection

A single library connection can have multiple database connections associated with it. In this example, the single library connection has two database connections, one for each database file. The application can access all databases via the same library connection.

## Building

```bash
make
```

## Running

Before running, ensure you have:
- `MyDB` database with a `Students(SID)` table
- `MyDBExtn` database with a `Courses(name, SID)` table

Then run:
```bash
./multiple_databases
```

## Cleanup

```bash
make clean
```

