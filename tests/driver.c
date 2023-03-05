#include <check.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_assembly/test_assembly.h"
#include "test_bitfields/test_bitfields.h"
#include "test_declarations/test_declarations.h"
#include "test_macros/test_macros.h"
#include "test_memory/test_memory.h"
#include "test_operators/test_operators.h"
#include "test_pointers/test_pointers.h"
#include "test_streams/test_streams.h"
#include "test_strings/test_strings.h"
#include "test_structs/test_structs.h"
#include "test_types/test_types.h"

int
main(void)
{
	int no_failed = 0;
	SRunner *runner = NULL;

	runner = srunner_create(strings_suite());
	srunner_add_suite(runner, structs_suite());
	srunner_add_suite(runner, bit_operations_suite());
	srunner_add_suite(runner, bitfields_suite());
	srunner_add_suite(runner, streams_suite());
	srunner_add_suite(runner, macros_suite());
	srunner_add_suite(runner, assembly_suite());
	srunner_add_suite(runner, pointers_suite());
	srunner_add_suite(runner, memory_suite());
	srunner_add_suite(runner, globals_suite());
	srunner_add_suite(runner, types_suite());

	srunner_run_all(runner, CK_NORMAL);
	no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
