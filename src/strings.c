#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "strings.h"

char **
command_parser_with_strtok(char *command, const char *const delims)
{
	char **tokens = malloc(sizeof(char *));
	*tokens = NULL;
	size_t n = 1;

	char *p = strtok(command, delims);

	int success = p != NULL;

	while (success) {
		char **tmp = realloc(tokens, (n + 1) * sizeof(char *));

		if (tmp == NULL) {
			free(tokens);
			tokens = NULL;

			success = 0;
		} else {
			tokens = tmp;

			tokens[n - 1] = strdup(p);
			tokens[n] = NULL;
			++n;

			p = strtok(NULL, delims);

			success = p != NULL;
		}
	}
	return tokens;
}

char **
command_parser_with_strtok_r(char *command, const char *const delims)
{
	char *token = NULL;
	size_t n = 1;
	char **tokens = malloc(sizeof(char *));
	*tokens = NULL;

	while ((token = strtok_r(command, delims, &command))) {

		char **tmp = realloc(tokens, (n + 1) * sizeof(char *));

		if (tmp == NULL) {
			free(tokens);
			tokens = NULL;

			break;
		} else {
			tokens = tmp;

			tokens[n - 1] = strdup(token);
			tokens[n] = NULL;
			++n;
		}
	}

	return tokens;
}

char *
the_good_way_of_iterating_over_strings(const char *const string)
{
	// always remember to add +1 when implementing raw string functions for
	// the null terminating character
	char *result = malloc(strlen(string) + 1);

	size_t i = 0;
	while (string[i] != '\0') {
		result[i] = string[i];
		i++;
	}

	result[i] = '\0';

	return result;
}

char *
get_file_name_with_strchr(const char *path)
{
	char *pend = NULL;
	if ((pend = strrchr(path, '/')) != NULL) {
		return pend + 1;
	}
	return NULL;
}

long
try_parse_long(const char *const number)
{
	char *check = 0;
	long ret = strtol(number, &check, 10);

	// no number was detected
	if (number == check) {
		return LONG_MAX;
		// some sort of overflow happened
	} else if ((ret == LONG_MAX || ret == LONG_MIN) && errno == ERANGE) {
		return LONG_MIN;
		// its safe to return that
	} else {
		return ret;
	}
}
