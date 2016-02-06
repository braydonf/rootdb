#ifndef ROOTDB_H
#define ROOTDB_H

#include <lmdb.h>

int rootdb_open(MDB_env** env, MDB_dbi *dbi, const char* path);

int rootdb_put(MDB_env** env, MDB_dbi dbi, MDB_val* key, MDB_val* value);

int rootdb_get(MDB_env** env, MDB_dbi dbi, MDB_val* key, MDB_val* value);

int rootdb_close(MDB_env** env, MDB_dbi dbi);

#endif /* ROOTDB_H */
