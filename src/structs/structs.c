#include <stddef.h>
#include <stdlib.h>

#include "structs.h"

sample_t *
allocate_sample_struct(void)
{
	sample_t *result = malloc(sizeof(*result) + 5 * sizeof(int));
	// aka
	// malloc(sizeof(sample_t) + sizeof(int[5]));

	return result;
}

another_sample_t *
allocate_another_sample_struct(void)
{
	// use offsetof to subtract the padding with the number from the struct
	// and then include that
	another_sample_t *result = malloc(
	    offsetof(another_sample_t, flex) + 5 * sizeof(result->flex[0]));

	// aka remove the size allocated from the FAM while mallocing
	// malloc(sizeof(result) + (4) * sizeof(tmp.flex[0]))

	return result;
}

static void
set_x(point_t *p, int x)
{
	p->x = x;
}

static void
set_y(point_t *p, int y)
{
	p->y = y;
}

point_t *
allocate_a_point(int x, int y)
{
	point_t *result = malloc(sizeof(point_t));

	result->x = x;
	result->y = y;
	result->setx = set_x;
	result->sety = set_y;

	return result;
}
