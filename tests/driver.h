#include <check.h>
#include <stdlib.h>

#include "../src/memory.h"

START_TEST(TEST_ALIGNED_MALLOC_SHOULD_BE_OKAY)
{
	void *mem = aligned_memory(1024);

	ck_assert_ptr_nonnull(mem);

	free(mem);
}
END_TEST
