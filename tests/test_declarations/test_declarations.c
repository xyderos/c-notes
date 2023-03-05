#include "test_declarations.h"

Suite *
globals_suite(void)
{
	Suite *s = NULL;
	TCase *tc_core = NULL;

	s = suite_create("globals");
	tc_core = tcase_create("core");

	tcase_add_test(tc_core, TEST_GLOBAL_VARIABLE_SHOULD_BE_OKAY);

	suite_add_tcase(s, tc_core);

	return s;
}
