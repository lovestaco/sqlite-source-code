#include <stdio.h>
#include "sqlite3.h"

static int callback(void *unused, int argc, char **argv, char **colName) {
    int i;
    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(void) {
    sqlite3 *db = 0;
    char *errMsg = 0;
    int rc;
    
    /* Open a database */
    rc = sqlite3_open("exclusive_transaction.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
    
    /* Create tables */
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS table1 (x INTEGER, y INTEGER)", 0, 0, 0);
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS table2 (a INTEGER, b INTEGER)", 0, 0, 0);
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS table3 (c1 INTEGER, c2 INTEGER, c3 INTEGER)", 0, 0, 0);
    
    /* Begin exclusive transaction */
    printf("Beginning EXCLUSIVE transaction...\n");
    rc = sqlite3_exec(db, "BEGIN EXCLUSIVE TRANSACTION", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error beginning transaction: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }
    
    /* Execute operations within the transaction */
    printf("Inserting into table1...\n");
    sqlite3_exec(db, "INSERT INTO table1 VALUES (100)", 0, 0, 0);
    
    printf("Inserting into table2...\n");
    sqlite3_exec(db, "INSERT INTO table2 VALUES (20, 100)", 0, 0, 0);
    
    printf("Updating table1...\n");
    sqlite3_exec(db, "UPDATE table1 SET x = x + 1 WHERE y > 10", 0, 0, 0);
    
    printf("Inserting into table3...\n");
    sqlite3_exec(db, "INSERT INTO table3 VALUES (1, 2, 3)", 0, 0, 0);
    
    /* Commit transaction */
    printf("Committing transaction...\n");
    rc = sqlite3_exec(db, "COMMIT TRANSACTION", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error committing transaction: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }
    
    printf("\nTransaction committed successfully!\n\n");
    
    /* Verify the data */
    printf("Verifying inserted data:\n");
    printf("table1:\n");
    sqlite3_exec(db, "SELECT * FROM table1", callback, 0, 0);
    
    printf("table2:\n");
    sqlite3_exec(db, "SELECT * FROM table2", callback, 0, 0);
    
    printf("table3:\n");
    sqlite3_exec(db, "SELECT * FROM table3", callback, 0, 0);
    
    sqlite3_close(db);
    
    return 0;
}

