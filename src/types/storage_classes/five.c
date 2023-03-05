#include "five.h"

extern int five = 5;

extern int plus_two(int n);

int
plus_two_wrapper(int n)
{
	return plus_two(n);
}
