#include "test_bitfields.h"

Suite *
bitfields_suite(void)
{
	Suite *s = NULL;
	TCase *tc_core = NULL;

	s = suite_create("bitfields");
	tc_core = tcase_create("core");

	tcase_add_test(tc_core, TEST_SETTING_BIT_IN_BITFIELDS_SHOULD_BE_OKAY);

	suite_add_tcase(s, tc_core);

	return s;
}
