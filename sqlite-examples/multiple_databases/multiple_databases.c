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
    
    sqlite3_open("MyDB", &db);  /* Open a database named MyDB */
    sqlite3_exec(db, "attach database MyDBExtn as DB1", 0, 0, 0);
    sqlite3_exec(db, "select * from Students S, DB1.Courses C where S.sid = C.sid", callback, 0, 0);
    sqlite3_close(db);
    
    return 0;
}

