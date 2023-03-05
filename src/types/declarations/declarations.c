#include "declarations.h"

#define ARBITRARY_SIZE 20

void
declarations(void)
{
	// Array comes before dereference, names is an array of size
	// ARBITRARY_SIZE of a pointer to char
	char *names
	    [ARBITRARY_SIZE] = { [0] = "hi", [12] = "hello", [4] = "what" };

	// Since parentheses override everything, the dereference operator comes
	// first, places is a pointer to an array of size ARBITRARY_SIZE of char
	char(*place)[ARBITRARY_SIZE];

	// Parentheses override everything, fp is a pointer to a function that
	// takes no arguments and returns an int
	int (*fp)(void);

	// From left to right, arr is an array of size ARBITRARY_SIZE of an
	// array of size ARBITRARY_SIZE +1 of int
	int arr[ARBITRARY_SIZE][ARBITRARY_SIZE + 1] = { { [0] = 1 },
		{ [0] = 2 } };

	// From right to left, ptr is a pointer to a pointer to an int
	int **ptr;

	// Comma separation
	int fn(void), *ptr1, (*x)(int), a[10][20], n;

	// The actual usage, since has a subscription and a dereference,
	// you first subscribe and then dereference to get the actual char
	char *c = names[1];
	char actual = *c;

	// this is invalid, well, not really since an array is essentially a
	// pointer but difficult to read and use
	char *k = *names; // equals arr[0]

	// since fp was a function pointer, we can call it with the parentheses
	// operator
	int a_random_result = fp();
}
