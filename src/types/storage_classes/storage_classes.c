#include "storage_classes.h"

int
summation(int limit)
{
	register int k = 0, sum = 0;
	for (sum = 0; k < limit; sum += k, k++) {
	}

	return sum;
}

int
array_size(register int *array)
{
	return sizeof(array);
}

int
internal_incrementation(void)
{
	static int a = 0;
	a++;

	return a;
}

int
return_extern(void)
{
	extern int five;

	return five;
}
