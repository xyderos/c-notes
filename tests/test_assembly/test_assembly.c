#include "test_assembly.h"

Suite *
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
