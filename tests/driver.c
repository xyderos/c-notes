#include "driver.h"

#include <check.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_strings/test_strings.h"
#include "test_structs/test_structs.h"
#include "test_operators/test_operators.h"

int
main(void)
{

	int no_failed = 0;
	SRunner *runner = NULL;

	runner = srunner_create(strings_suite());
	srunner_add_suite(runner, structs_suite());
	srunner_add_suite(runner, bit_operations_suite());

	srunner_run_all(runner, CK_NORMAL);
	no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
