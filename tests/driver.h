#include <check.h>
#include <stddef.h>
#include <stdlib.h>

#include "../src/structs.h"

START_TEST(TEST_ALLOCATING_SAMPLE_SHOULD_BE_OKAY)
{
	sample_t s1;

	s1.flex[1] = 5;

	sample_t *s2 = allocate_sample_struct();

	s2->flex[1] = 5;
	// this causes undefined behaviour on x86-64 linux
	// verify that this causes internal damage by checking the output from
	// valgrind ck_assert_int_ne(s1.flex[1], s2->flex[1]);

	free(s2->flex);
	free(s2);
}
END_TEST

START_TEST(TEST_ALLOCATING_ANOTHER_SAMPLE_SHOULD_BE_OKAY)
{
	another_sample_t s1 = { 2 };

	s1.flex[1] = 5;

	another_sample_t *s2 = allocate_another_sample_struct();

	s2->flex[1] = 5;
	// this causes undefined behaviour on x86-64 linux
	// verify that this causes internal damage by checking the output from
	// valgrind ck_assert_int_ne(s1.flex[1], s2->flex[1]);

	free(s2->flex);
	free(s2);
}
END_TEST

START_TEST(TEST_USING_FPTRS_AS_METHODS_SHOULD_BE_OKAY)
{
	point_t *p = allocate_a_point(1, 1);

	p->setx(p, 2);
	p->sety(p, 2);

	ck_assert_int_eq(p->x, 2);
	ck_assert_int_eq(p->y, 2);

	free(p);
}
END_TEST
