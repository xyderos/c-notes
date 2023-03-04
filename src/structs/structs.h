#pragma once

#include <stdlib.h>

typedef struct sample {
	size_t foo;
	int flex[];
} sample_t;

typedef struct another_sample {
	size_t foo;
	int flex[1];
} another_sample_t;

typedef struct point point_t;
struct point {
	void (*setx)(point_t *this, int x);
	void (*sety)(point_t *this, int y);

	int x;
	int y;
};
point_t *allocate_a_point(int x, int y);

sample_t *allocate_sample_struct(void);

another_sample_t *allocate_another_sample_struct(void);
