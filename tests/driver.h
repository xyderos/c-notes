#include <check.h>
#include <stdint.h>

#include "../src/effective_types/types.h"
#include "../src/storage_classes/storage_classes.h"

START_TEST(TEST_CHANGING_BYTES_SHOULD_BE_OKAY)
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

START_TEST(TEST_SUMMATION_SHOULD_BE_OKAY)
{
	int result = summation(3);
	ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(TEST_INTERNAL_INCREMENTATION_SHOULD_BE_OKAY)
{
	internal_incrementation();

	int result = internal_incrementation();

	ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(TEST_RETURN_EXTERN_SHOULD_BE_OKAY)
{
	int result = return_extern();

	ck_assert_int_eq(result, 5);
}
END_TEST