#include "test_pointers.h"

Suite *
pointers_suite(void)
{
	Suite *s = NULL;
	TCase *tc_core = NULL;

	s = suite_create("pointers");
	tc_core = tcase_create("core");

	tcase_add_test(tc_core, TEST_GLOBAL_POINTER_SHOULD_BE_NULL);
	tcase_add_test(tc_core, TEST_DEEP_COPY_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_SHALLOW_COPY_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_CUSTOM_SORT_SHOULD_SORT);
	tcase_add_test(tc_core, TEST_CALCULATOR_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_CONSTNESS_SHOULD_BE_OKAY);

	suite_add_tcase(s, tc_core);

	return s;
}
