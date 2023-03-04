#include "test_strings.h"

Suite *strings_suite(void) {
  Suite *s = NULL;
  TCase *tc_core = NULL;

  s = suite_create("strings");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, TEST_COMMAND_PARSER_WITH_STRTOK_R_SHOULD_BE_OKAY);
  tcase_add_test(tc_core, TEST_COMMAND_PARSER_WITH_STRTOK_SHOULD_BE_OKAY);
  tcase_add_test(tc_core, ITERATING_OVER_A_STRING_SHOULD_BE_OKAY);
  tcase_add_test(tc_core, GET_FILE_NAME_WITH_STRCHR_SHOULD_BE_OKAY);
  tcase_add_test(tc_core, TRY_PARSE_LONG_SHOULD_BE_OKAY);

  suite_add_tcase(s, tc_core);

  return s;
}
