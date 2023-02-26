#include <check.h>

#include "../src/globals.h"

START_TEST(TEST_GLOBAL_VARIABLE_SHOULD_BE_OKAY)
{
	ck_assert_int_eq(1, a_number);
}
END_TEST
