#include <stdio.h>
#include <sqlite3.h>

static int callback(void *unused, int argc, char **argv, char **colName) {
    int i;
    for(i = 0; i < argc; i++) {  // Loop over each column in the current row
        printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db = 0;
    char *errMsg = 0;
    int rc;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s DATABASE-NAME SQL-STATEMENT\n", argv[0]);
        return -1;
    }

    rc = sqlite3_open(argv[1], &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database %s: %s\n", argv[1], sqlite3_errmsg(db));
        sqlite3_close(db);
        return -2;
    }

    rc = sqlite3_exec(db, argv[2], callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL execution error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);
    return rc;
}

