#include "test_macros.h"

Suite *
macros_suite(void)
{
	Suite *s = NULL;
	TCase *tc_core = NULL;

	s = suite_create("macros");
	tc_core = tcase_create("core");

	tcase_add_test(tc_core, TEST_CHECKING_TYPE_SHOULD_BE_OKAY);

	suite_add_tcase(s, tc_core);

	return s;
}