#include "test_operators.h"

Suite *
bit_operations_suite(void)
{
	Suite *s = NULL;
	TCase *tc_core = NULL;

	s = suite_create("bitwise_operations");
	tc_core = tcase_create("core");

	tcase_add_test(tc_core, TEST_BITWISE_AND_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_BITWISE_OR_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_BITWISE_XOR_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_BITWISE_NOT_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_SHIFT_LEFT_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_SHIFT_RIGHT_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_IS_OPTIMIZED_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_BIT_PATTERN_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_EXTRACT_BIT_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_SET_BIT_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_TOOGLE_BIT_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_CLEAR_BIT_SHOULD_BE_OKAY);

	suite_add_tcase(s, tc_core);

	return s;
}