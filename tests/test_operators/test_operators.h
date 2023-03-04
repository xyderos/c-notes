#pragma once

#include <check.h>
#include <stdlib.h>

#include "../../src/operators/bitwise_operators.h"

Suite *bit_operations_suite(void);

START_TEST(TEST_BITWISE_AND_SHOULD_BE_OKAY)
{
	unsigned int n1 = 29, n2 = 48, expected = 16;
	unsigned int result = bitwise_and(n1, n2);

	ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(TEST_BITWISE_OR_SHOULD_BE_OKAY)
{
	unsigned int n1 = 29, n2 = 48, expected = 61;
	unsigned int result = bitwise_or(n1, n2);

	ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(TEST_BITWISE_XOR_SHOULD_BE_OKAY)
{
	unsigned int n1 = 29, n2 = 48, expected = 45;
	unsigned int result = bitwise_xor(n1, n2);

	ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(TEST_BITWISE_NOT_SHOULD_BE_OKAY)
{
	unsigned int n = 29;
	int expected = -30;
	int result = bitwise_not(n);

	ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(TEST_SHIFT_LEFT_SHOULD_BE_OKAY)
{
	unsigned int n1 = 29, n2 = 2, expected = 116;
	unsigned int result = shift_left(n1, n2);

	ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(TEST_SHIFT_RIGHT_SHOULD_BE_OKAY)
{
	unsigned int n1 = 29, n2 = 2, expected = 7;
	unsigned int result = shift_right(n1, n2);

	ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(TEST_IS_OPTIMIZED_SHOULD_BE_OKAY)
{
	unsigned char *pattern = bit_pattern(36);

	unsigned char *expected =
	    (unsigned char *)"00000000000000000000000000100100";
	ck_assert_str_eq(pattern, expected);

	free(pattern);
}
END_TEST

START_TEST(TEST_BIT_PATTERN_SHOULD_BE_OKAY)
{
	unsigned char *pattern = bit_pattern(36);

	unsigned char *expected =
	    (unsigned char *)"00000000000000000000000000100100";
	ck_assert_str_eq(pattern, expected);

	free(pattern);
}
END_TEST

START_TEST(TEST_EXTRACT_BIT_SHOULD_BE_OKAY)
{
	unsigned int n1 = 29, n2 = 0, expected = 1;
	unsigned int result = extract_bit(n1, n2);

	ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(TEST_SET_BIT_SHOULD_BE_OKAY)
{
	unsigned int n1 = 29, n2 = 1, expected = 31;
	set_bit(&n1, n2);

	ck_assert_int_eq(n1, expected);
}
END_TEST

START_TEST(TEST_TOOGLE_BIT_SHOULD_BE_OKAY)
{
	unsigned int n1 = 29, n2 = 0, expected = 28;
	toogle_bit(&n1, n2);

	ck_assert_int_eq(n1, expected);
}
END_TEST

START_TEST(TEST_CLEAR_BIT_SHOULD_BE_OKAY)
{
	unsigned int n1 = 29, n2 = 0, expected = 28;
	toogle_bit(&n1, n2);

	ck_assert_int_eq(n1, expected);
}
END_TEST
