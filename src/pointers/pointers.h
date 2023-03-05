#pragma once

#include <stddef.h>
typedef enum op { ADD = '+', SUB = '-' } op_t;

typedef struct point point_t;

struct point {
	int x, y;
};

extern point_t *global_point;

point_t *deep_copy(const point_t *const);

point_t *shallow_copy(const point_t *const);

void sort(void *arr, size_t l);

int calculator(int, int, op_t);

void constness(void);
