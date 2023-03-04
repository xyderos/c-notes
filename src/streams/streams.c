#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "streams.h"

char **
log_results_of_command(const char *const command)
{
	FILE *stream = NULL;
	char *buffer = NULL;
	size_t nof_bytes = 0, n = 1;
	char **lines = malloc(sizeof(char *));

	stream = popen(command, "r");

	while (getline(&buffer, &nof_bytes, stream) != -1) {

		char **tmp = realloc(lines, (n + 1) * sizeof(char *));

		if (tmp == NULL) {
			free(lines);
			lines = NULL;

			break;
		}
		lines = tmp;

		lines[n - 1] = strdup(buffer);
		lines[n] = NULL;
		++n;
	}

	fclose(stream);
	free(buffer);

	return lines;
}
