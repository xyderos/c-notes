#include <check.h>
#include <stdlib.h>

#include "../../src/streams/streams.h"

Suite *streams_suite(void);

START_TEST(TEST_LS_SHOULD_BE_OKAY)
{

	char **logs = log_results_of_command("ls");

	for (char **log = logs; *log != NULL; log++) {

		ck_assert_ptr_nonnull(log);
		free(*log);
	}

	free(logs);
}
END_TEST
