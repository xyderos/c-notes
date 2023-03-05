#pragma once

#include <stddef.h>
typedef enum op { ADD = '+', SUB = '-' } op_t;

typedef struct p p_t;

struct p {
	int x, y;
};

extern p_t *global_point;

p_t *deep_copy(const p_t *const);

p_t *shallow_copy(const p_t *const);

void sort(void *arr, size_t l);

int calculator(int, int, op_t);

void constness(void);
