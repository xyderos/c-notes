#include <stdlib.h>
#include <string.h>

#include "strings.h"

char **
command_parser(char *command, const char *const delims)
{
	char *p = NULL;
	size_t n = 1, success = 0;

	// allocate memory for the result
	char **tokens = malloc(sizeof(char *));
	*tokens = NULL;

	p = strtok(command, delims);

	success = p != NULL;

	while (success) {
		char **tmp = realloc(tokens, (n + 1) * sizeof(char *));

		if (!tmp) {
			free(tokens);
			tokens = NULL;

			success = 0;
		} else {
			tokens = tmp;

			tokens[n - 1] = p;
			tokens[n] = NULL;
			++n;

			p = strtok(NULL, delims);

			success = p != NULL;
		}
	}

	return tokens;
}
