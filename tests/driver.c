#include <check.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "driver.h"

static Suite *
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

int
main(void)
{

	int no_failed = 0;
	Suite *s = NULL;
	SRunner *runner = NULL;

	s = pointers_suite();
	runner = srunner_create(s);

	srunner_run_all(runner, CK_NORMAL);
	no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
