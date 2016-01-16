#include <stdlib.h>
#include <check.h>
#include "../src/rootdb.h"

START_TEST (test_rootdb_open)
{
  int status = rootdb_open();
  ck_assert_int_eq(status, 0);
}
END_TEST

Suite * rootdb_suite(void)
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RootDB");

  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_rootdb_open);
  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void)
{
  int number_failed;
  Suite *suite;
  SRunner *suite_runner;

  suite = rootdb_suite();
  suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
