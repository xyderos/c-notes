#include <check.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "driver.h"

static Suite *
assembly_suite(void)
{
	Suite *s = NULL;
	TCase *tc_core = NULL;

	s = suite_create("assembly");
	tc_core = tcase_create("core");

	tcase_add_test(tc_core, TEST_SWAP_IN_ASSEMBLY_SHOULD_BE_OKAY);

	suite_add_tcase(s, tc_core);

	return s;
}

int
main(void)
{

	int no_failed = 0;
	Suite *s = NULL;
	SRunner *runner = NULL;

	s = assembly_suite();
	runner = srunner_create(s);

	srunner_run_all(runner, CK_NORMAL);
	no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
