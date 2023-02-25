#include <check.h>
#include <stdlib.h>

#include "../src/strings.h"

START_TEST(TEST_COMMAND_PARSER_SHOULD_BE_OKAY)
{
	const char *const input = "needle,in,the,haystack";
	char **result = command_parser(input, ",");

	int acc = 0;
	for (char *c = *result; c; c = *++result) {

		if (acc == 0) {
			ck_assert_str_eq(c, "needle");
		} else if (acc == 1) {
			ck_assert_str_eq(c, "in");
		} else if (acc == 2) {
			ck_assert_str_eq(c, "the");
		} else {
			ck_assert_str_eq(c, "haystack");
		}
	}

	free(result);
}
END_TEST
