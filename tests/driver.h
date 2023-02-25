#include <check.h>
#include <stdlib.h>

#include "../src/strings.h"

START_TEST(TEST_COMMAND_PARSER_WITH_STRTOK_SHOULD_BE_OKAY)
{

	char *original_command_from_pointer = "a couple of commands";

	char *copied_string = strdup(original_command_from_pointer);

	char **entries = command_parser_with_strtok(copied_string, " ");

	free(copied_string);

	unsigned int acc = 0;
	for (char **entry = entries; *entry != NULL; entry++) {

		if (acc == 0) {
			ck_assert_str_eq(*entry, "a");
		} else if (acc == 1) {
			ck_assert_str_eq(*entry, "couple");
		} else if (acc == 2) {
			ck_assert_str_eq(*entry, "of");
		} else if (acc == 3) {
			ck_assert_str_eq(*entry, "commands");
		}
		free(*entry);
		acc++;
	}

	ck_assert_int_eq(acc, 4);

	free(entries);
}
END_TEST

START_TEST(TEST_COMMAND_PARSER_WITH_STRTOK_R_SHOULD_BE_OKAY)
{

	char *original_command_from_pointer = "a couple of commands";

	char *copied_string = strdup(original_command_from_pointer);

	char **entries = command_parser_with_strtok_r(copied_string, " ");

	free(copied_string);

	unsigned int acc = 0;
	for (char **entry = entries; *entry != NULL; entry++) {

		if (acc == 0) {
			ck_assert_str_eq(*entry, "a");
		} else if (acc == 1) {
			ck_assert_str_eq(*entry, "couple");
		} else if (acc == 2) {
			ck_assert_str_eq(*entry, "of");
		} else if (acc == 3) {
			ck_assert_str_eq(*entry, "commands");
		}
		free(*entry);
		acc++;
	}

	ck_assert_int_eq(acc, 4);

	free(entries);
}
END_TEST

START_TEST(ITERATING_OVER_A_STRING_SHOULD_BE_OKAY)
{
	char *original_command_from_pointer = "a couple of commands";

	char *result = the_good_way_of_iterating_over_strings(
	    original_command_from_pointer);

	ck_assert_str_eq(original_command_from_pointer, result);

	free(result);
}
END_TEST

START_TEST(GET_FILE_NAME_WITH_STRCHR_SHOULD_BE_OKAY)
{
	char *path = "home/xyderos/.ssh/id_rsa.pub";

	char *result = get_file_name_with_strchr(path);

	ck_assert_str_eq("id_rsa.pub", result);
}
END_TEST

START_TEST(TRY_PARSE_LONG_SHOULD_BE_OKAY)
{
	char *number = "12233";

	long result = try_parse_long(number);

	ck_assert_int_eq(12233, result);
}
END_TEST
