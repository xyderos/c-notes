#include <check.h>

#include "../src/assembly.h"

START_TEST(TEST_SWAP_IN_ASSEMBLY_SHOULD_BE_OKAY)
{
	int n1 = 1, n2 = 2;
	int *p1 = &n1, *p2 = &n2;
	swap(p1, p2);

	ck_assert_int_eq(2, n1);
	ck_assert_int_eq(1, n2);
}
END_TEST
