#include <stdio.h>
#include <pthread.h>
#include <sqlite3.h>

void* myinsert(void* arg) {
    sqlite3* db = 0;
    sqlite3_stmt* stmt = 0;
    int val = (int)(long)arg;  // Use long to avoid pointer size issues
    char SQL[100];
    int rc;

    rc = sqlite3_open("MyDB.db", &db); /* Open a database named MyDB */
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Thread[%d] fails to open the MyDB database: %s\n", val, sqlite3_errmsg(db));
        goto errorRet;
    }

    sprintf(SQL, "INSERT INTO Students VALUES(%d)", val); /* Dynamically compose a SQL */
    
    rc = sqlite3_prepare_v2(db, SQL, -1, &stmt, 0); /* Prepare the insert statement */
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Thread[%d] fails to prepare SQL: %s; return code %d\n", val, SQL, rc);
        goto errorRet;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Thread[%d] fails to execute SQL: %s; return code %d\n", val, SQL, rc);
    } else {
        printf("Thread[%d] successfully executes SQL: %s\n", val, SQL);
    }

    sqlite3_finalize(stmt);

errorRet:
    sqlite3_close(db);
    return (void*)(long)rc;
}

int main(void) {
    sqlite3* db = 0;
    char* errMsg = 0;
    int rc;
    pthread_t t[10];
    int i;

    /* Create database and table first */
    rc = sqlite3_open("MyDB.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }

    /* Create Students table if it doesn't exist */
    rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Students (id INTEGER)", 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return -1;
    }

    /* Clear existing data */
    sqlite3_exec(db, "DELETE FROM Students", 0, 0, 0);
    sqlite3_close(db);

    /* Create threads */
    for (i = 0; i < 10; i++) {
        pthread_create(&t[i], 0, myinsert, (void*)(long)i); /* pass the value of i */
    }

    /* Wait for all threads to finish */
    for (i = 0; i < 10; i++) {
        pthread_join(t[i], 0);
    }

    return 0;
}

