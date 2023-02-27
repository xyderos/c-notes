#include <check.h>
#include <stdlib.h>

#include "../src/check_type.h"

START_TEST(TEST_CHECKING_TYPE_SHOULD_BE_OKAY)
{
	char *result = check_if_a_number_is_const_int();

	ck_assert_str_eq("a const int", result);

	free(result);
}
END_TEST