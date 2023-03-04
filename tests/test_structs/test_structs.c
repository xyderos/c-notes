#include "test_structs.h"

Suite *structs_suite(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;

  s = suite_create("structs");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, TEST_ALLOCATING_SAMPLE_SHOULD_BE_OKAY);
  tcase_add_test(tc_core, TEST_ALLOCATING_ANOTHER_SAMPLE_SHOULD_BE_OKAY);
  tcase_add_test(tc_core, TEST_USING_FPTRS_AS_METHODS_SHOULD_BE_OKAY);

  suite_add_tcase(s, tc_core);

  return s;
}
