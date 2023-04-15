#include "tst.h"

int main() {
  int no_failed = 0;

  Suite *suite = tests();
  SRunner *test_1 = srunner_create(suite);
  srunner_set_fork_status(test_1, CK_NOFORK);
  srunner_run_all(test_1, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_1);
  srunner_free(test_1);

  return (no_failed < 1) ? EXIT_SUCCESS : EXIT_FAILURE;
}
