#include <check.h>

#include "../../src/declarations_and_definitions/globals/globals.h"

Suite *globals_suite(void);

START_TEST(TEST_GLOBAL_VARIABLE_SHOULD_BE_OKAY)
{
	ck_assert_int_eq(1, a_number);
}
END_TEST
