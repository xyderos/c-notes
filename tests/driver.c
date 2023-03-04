#include <check.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "test_macros/test_macros.h"

int
main(void)
{

	int no_failed = 0;
	Suite *s = NULL;
	SRunner *runner = NULL;

	s = macros_suite();
	runner = srunner_create(s);

	srunner_run_all(runner, CK_NORMAL);
	no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
