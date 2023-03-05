#include <stdio.h>

#include "assembly.h"

void
swap(int *n1, int *n2)
{
	int x = *n1, y = *n2, tmp = *n1;
	asm volatile("mov %1, %0\n\t" : "=r"(x) : "r"(y));
	asm volatile("mov %1, %0\n\t" : "=r"(y) : "r"(tmp));

	*n1 = x;
	*n2 = y;
}
