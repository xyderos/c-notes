#include <check.h>
#include <stdint.h>

#include "../src/effective_types/types.h"

START_TEST(TEST_CHANGING_BUTES_SHOULD_BE_OKAY)
{
	uint32_t result = change_bytes(1);
	ck_assert_int_eq(result, UINT32_MAX);
}
END_TEST

START_TEST(TEST_UNION_CHANGING_BYTES_SHOULD_BE_OKAY)
{
	buffer_t result = change_via_non_character_type();
	ck_assert_int_eq(result.i[0], 1);
}
END_TEST
