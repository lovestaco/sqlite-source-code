# SQLite Examples

This repository contains example applications demonstrating various SQLite features and usage patterns.

## Overview

These examples illustrate different aspects of working with SQLite databases in C, including:
- Basic command-line database operations
- Working with multiple databases
- Transaction management
- Multithreaded database access

## Examples

### 1. Command Line Application (`command_line/`)

A simple command-line SQLite application that executes SQL statements and displays results.

**Features:**
- Execute arbitrary SQL statements from the command line
- Display query results in a formatted output
- Basic database operations (CREATE, INSERT, SELECT)

**Documentation:** [command_line/README.md](command_line/README.md)

**Related Blog Post:** [Direct SQL Execution and Concurrency in SQLite](https://dev.to/lovestaco/direct-sql-execution-and-concurrency-in-sqlite-405d)

### 2. Multiple Databases (`multiple_databases/`)

Demonstrates how to work with multiple SQLite databases using a single library connection.

**Features:**
- Opening a primary database
- Attaching additional databases to a connection
- Joining tables across multiple databases
- Understanding library connections vs. database connections

**Key Concept:** A single library connection can have multiple database connections associated with it. The application can access all databases via the same library connection.

**Documentation:** [multiple_databases/README.md](multiple_databases/README.md)

**Related Blog Post:** [Working with Multiple Databases, Transactions, and SQLite Internals](https://dev.to/lovestaco/working-with-multiple-databases-transactions-and-sqlite-internals-2254)

### 3. Transactions (`transactions/`)

Demonstrates transaction management in SQLite.

**Features:**
- Beginning transactions with `begin`
- Executing multiple operations within a transaction
- Committing transactions with `commit`
- Understanding rollback behavior
- Batch SQL statement execution

**Key Concept:** If any operation in a transaction fails, you can execute `rollback` instead of `commit` to undo all changes. SQLite also permits multiple SQL statements in a single `exec` API call.

**Documentation:** [transactions/README.md](transactions/README.md)

**Related Blog Post:** [Working with Multiple Databases, Transactions, and SQLite Internals](https://dev.to/lovestaco/working-with-multiple-databases-transactions-and-sqlite-internals-2254)

### 4. Multithreaded Application (`multi_threaded_application/`)

Demonstrates concurrent database operations using SQLite with pthreads.

**Features:**
- Creating multiple threads
- Each thread opening its own database connection
- Thread-safe database operations
- Concurrent inserts

**Key Concept:** SQLite handles thread-safety, but each thread should use its own connection for better concurrency.

**Documentation:** [multi_threaded_application/README.md](multi_threaded_application/README.md)

**Related Blog Post:** [Direct SQL Execution and Concurrency in SQLite](https://dev.to/lovestaco/direct-sql-execution-and-concurrency-in-sqlite-405d)

## Notes

- These examples are simplified and do not include comprehensive error checking
- In production code, always check return values from SQLite API calls
- The examples demonstrate core concepts; real applications should include proper error handling and resource management

