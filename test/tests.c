#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../src/rootdb.h"

int main(void)
{
  MDB_env *env;
  MDB_dbi dbi;
  int status;

  status = rootdb_open(&env, &dbi, "./testingdb");
  assert(status == 0);

  char key_char[] = "hello";
  char value_char[] = "world";
  MDB_val key;
  MDB_val value;

  key.mv_size = sizeof(key_char);
  key.mv_data = key_char;
  value.mv_size = sizeof(value_char);
  value.mv_data = value_char;

  printf("key: %p %.*s, data: %p %.*s\n",
	 key.mv_data,  (int) key.mv_size,  (char *) key.mv_data,
	 value.mv_data, (int) value.mv_size, (char *) value.mv_data);

  status = rootdb_put(&env, dbi, &key, &value);
  assert(status == 0);

  MDB_val rvalue;

  status = rootdb_get(&env, dbi, &key, &rvalue);
  assert(status == 0);

  printf("key: %p %.*s, data: %p %.*s\n",
	 key.mv_data,  (int) key.mv_size,  (char *) key.mv_data,
	 rvalue.mv_data, (int) rvalue.mv_size, (char *) rvalue.mv_data);

  rootdb_close(&env, dbi);

  return 0;

}
