#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <openssl/sha.h>
#include <lmdb.h>

int rootdb_open(MDB_env** env, MDB_dbi *dbi, const char* path)
{
  struct stat st = {0};

  if (stat(path, &st) == -1) {
    mkdir(path, 0755);
  }

  int mdb_dbi_flags = MDB_INTEGERKEY | MDB_CREATE;
  int mdb_txn_flags = 0;

  int status;
  status = mdb_env_create(env);
  status = mdb_env_open(*env, path, 0, 0644);

  MDB_txn *txn;
  status = mdb_txn_begin(*env, NULL, mdb_txn_flags, &txn);
  status = mdb_dbi_open(txn, NULL, mdb_dbi_flags, dbi);
  if (status) {
    return status;
  }

  status = mdb_txn_commit(txn);

  return status;
}


int rootdb_put(MDB_env** env, MDB_dbi dbi, MDB_val* key, MDB_val *value)
{
  int status;
  MDB_txn *txn;

  status = mdb_txn_begin(*env, NULL, 0, &txn);
  if (status) {
    return status;
  }
  status = mdb_put(txn, dbi, key, value, 0);
  if (status) {
    return status;
  }

  status = mdb_txn_commit(txn);
  return status;
}

int rootdb_get(MDB_env** env, MDB_dbi dbi, MDB_val* key, MDB_val* value)
{
  int status;
  MDB_txn *txn;

  status = mdb_txn_begin(*env, NULL, MDB_RDONLY, &txn);
  status = mdb_get(txn, dbi, key, value);
  status = mdb_txn_commit(txn);

  return status;

}

void rootdb_close(MDB_env** env, MDB_dbi dbi)
{
  int status;
  mdb_dbi_close(*env, dbi);
  mdb_env_close(*env);
}
