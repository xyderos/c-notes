#include <stdlib.h>

#include "pointers.h"

point_t *global_point = NULL;
point_t *
deep_copy(const point_t *const p)
{
	point_t *other = malloc(sizeof(point_t));

	*other = *p;

	return other;
}

point_t *
shallow_copy(const point_t *const p)
{
	point_t *other = malloc(sizeof(point_t));

	other = (point_t *)p;

	return other;
}

int
compare_numbers(const void *a, const void *b)
{
	int fa = *((int *)a);
	int fb = *((int *)b);
	if (fa < fb) {
		return -1;
	}
	if (fa > fb) {
		return 1;
	}
	return 0;
}

void
sort(void *arr, size_t l)
{
	qsort(arr, l, sizeof(int), compare_numbers);
}

static int
add(int a, int b)
{
	return a + b;
}

static int
sub(int a, int b)
{
	return a - b;
}

static int (*decide_operation(op_t op))(int, int)
{
	switch (op) {
	case ADD:
		return &add;
	case SUB:
		return &sub;
	default:
		return NULL;
	}
}

int
calculator(int n1, int n2, op_t operation)
{
	int (*fp)(int, int) = NULL;

	fp = decide_operation(operation);

	return (*fp)(n1, n2);
}

void
constness(void)
{
	int b = 0, a = 0;
	const int *p1 = NULL;

	int *const p2 = &b;
	p1 = &b; // ok
		 //*p = 100; // error, read only
		 // p2 = &a; // error, cannot be reassigned

	const int *const x = &a;

	// cannot read or write
	// x = &b;
	//*x = a;

	// of course, the same logic is applied to double pointers
}
