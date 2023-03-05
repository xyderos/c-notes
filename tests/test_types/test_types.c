#include "test_types.h"

Suite *
types_suite(void)
{
	Suite *s = NULL;
	TCase *tc_core = NULL;

	s = suite_create("types");
	tc_core = tcase_create("core");

	tcase_add_test(tc_core, TEST_CHANGING_BYTES_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_UNION_CHANGING_BYTES_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_SUMMATION_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_INTERNAL_INCREMENTATION_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_RETURN_EXTERN_SHOULD_BE_OKAY);
	tcase_add_test(tc_core, TEST_INLINE_AND_EXTERN_FUNCTION_SHOULD_BE_OKAY);

	suite_add_tcase(s, tc_core);

	return s;
}
