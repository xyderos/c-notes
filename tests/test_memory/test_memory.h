#include <check.h>
#include <stdlib.h>

#include "../../src/memory/memory.h"

Suite *memory_suite(void);

START_TEST(TEST_ALIGNED_MALLOC_SHOULD_BE_OKAY)
{
	void *mem = aligned_memory(1024);

	ck_assert_ptr_nonnull(mem);

	free(mem);
}
END_TEST
