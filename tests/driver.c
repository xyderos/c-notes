#include <check.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "driver.h"

static Suite *
strings_suite(void)
{
	Suite *s = NULL;
	TCase *tc_core = NULL;

	s = suite_create("strings");
	tc_core = tcase_create("core");

	tcase_add_test(tc_core, TEST_COMMAND_PARSER_SHOULD_BE_OKAY);

	suite_add_tcase(s, tc_core);

	return s;
}

/*
int
main(void)
{

	int no_failed = 0;
	Suite *s = NULL;
	SRunner *runner = NULL;

	s = strings_suite();
	runner = srunner_create(s);

	srunner_run_all(runner, CK_NORMAL);
	no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
*/

char **
parse_command(char *command)
{
	char **tokens = malloc(sizeof(char *));
	*tokens = NULL;
	size_t n = 1;

	const char *delim = " \t";

	char *p = strtok(command, delim);

	int success = p != NULL;

	while (success) {
		char **tmp = realloc(tokens, (n + 1) * sizeof(char *));

		if (tmp == NULL) {
			free(tokens);
			tokens = NULL;

			success = 0;
		} else {
			tokens = tmp;

			tokens[n - 1] = p;
			tokens[n] = NULL;
			++n;

			p = strtok(NULL, delim);

			success = p != NULL;
		}
	}
	return tokens;
}

void
deep_copy_of_the_result(char **entries)
{
	unsigned int accumulator = 0;
	for (char **entry = entries; *entry != NULL; ++entry) {
		accumulator++;
	}

	char **tmp = malloc(accumulator * sizeof(char *));
	// char *tmp[];
	accumulator = 0;
	for (char **entry = entries; *entry != NULL; ++entry) {
		tmp[accumulator++] = strdup(*entry);
	}

	// free(entries);
	entries = tmp;

	free(tmp);
}
#if 1
int
main(void)
{
	char *original_command_from_pointer = "a couple of commands";
	// char original_command_from_array[] = "a couple of commands";

	char *copied_string = strdup(original_command_from_pointer);

	char **entries = parse_command(copied_string);
	// char **entries = parse_command(original_command_from_pointer);

	deep_copy_of_the_result(entries);
	entries[0][0] = 'e';
	//
	char **entry = entries;
	for (; *entry != NULL; entry++) {
		printf("%s \n", *entry);
		free(entry);
	}

	free(copied_string);
	free(entries);

	return 0;
}

#else
int
main()
{

	char *s1 = "abc";

	char s2[] = "def";

	printf("%x \n", &s1);

	printf("%x \n", &s2);
}
#endif