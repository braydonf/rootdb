#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <openssl/sha.h>
#include <lmdb.h>

int rootdb_open(MDB_env* mdb_env, const char* path)
{
  struct stat st = {0};

  if (stat(path, &st) == -1) {
    mkdir(path, 0755);
  }

  int mdb_flags = MDB_INTEGERKEY | MDB_CREATE;
  int status;
  status = mdb_env_create(&mdb_env);
  status = mdb_env_open(mdb_env, path, 0, 0644);
  return status;
}
