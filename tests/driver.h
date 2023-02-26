#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../src/pointers.h"

point_t *global_point;

START_TEST(TEST_GLOBAL_POINTER_SHOULD_BE_NULL)
{
	ck_assert_ptr_null(global_point);
}
END_TEST

START_TEST(TEST_DEEP_COPY_SHOULD_BE_OKAY)
{
	point_t *p1 = malloc(sizeof(point_t));

	p1->x = 1;
	p1->y = 1;

	point_t *p2 = deep_copy(p1);

	ck_assert_int_eq(p2->x, p1->x);

	p2->x = 3;

	ck_assert_int_ne(p2->x, p1->x);

	free(p1);
	free(p2);
}
END_TEST

START_TEST(TEST_SHALLOW_COPY_SHOULD_BE_OKAY)
{
	point_t *p1 = malloc(sizeof(point_t));

	p1->x = 1;
	p1->y = 1;

	point_t *p2 = shallow_copy(p1);

	ck_assert_int_eq(p2->x, p1->x);

	p2->x = 3;

	ck_assert_int_eq(p2->x, p1->x);

	free(p1);
	free(p2);
}
END_TEST

START_TEST(TEST_CUSTOM_SORT_SHOULD_SORT)
{
	int *a1 = malloc(5);
	a1[0] = 4;
	a1[1] = 3;
	a1[2] = 2;

	a1[3] = 1;
	a1[4] = 0;
	sort(a1, 5);

	for (int i = 0; i < 5; i++) {
		ck_assert_int_eq(a1[i], i);
	}

	free(a1);
}
END_TEST

START_TEST(TEST_CALCULATOR_SHOULD_BE_OKAY)
{
	int result = calculator(1, 1, ADD);

	ck_assert_int_eq(result, 2);
}
END_TEST

// as long as it doesnt throw :)
START_TEST(TEST_CONSTNESS_SHOULD_BE_OKAY)
{
	constness();
}
END_TEST
