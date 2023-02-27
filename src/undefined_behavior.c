#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "undefined_behavior.h"

void
return_stack_memory_address(void)
{
	int baz = 1;
	// this is bad, allocate before return or return value
	// return &baz;
}

void
mess_aroumd_with_overlapping_memory(void)
{
	char str[19] = "This is an example";
	// this is pretty bad, messes around the internal memory
	// memcpy(str + 7, str, 10);

	// this is better
	memmove(str, str + 7, 7);
}

void
overflow_signed_integers(void)
{
	int i = INT_MAX + 1;
}

void
usage_of_uninitialized_value(void)
{
	int i;
	// either initialize or use different storage specifier
	int j = 0;
}

void
dangling_pointer(void)
{
	char *p = malloc(5);
	free(p);
	if (p == NULL) // even without dereferencing, this might be undefined
		       // behavior
	{
	}
}

void
wild_pointer(void)
{
	int *p;

	// do stuff with p

	p = calloc(sizeof(int), 1);
}

void
modify_string_literal(void)
{
	char *s = "hahaha";

	s[1] = 'o';
}

void
bit_shifting_with_weird_values(void)
{
	int x = 5 << -3; // undefined
	x = 5 >> -3;	 // undefined
	x = -5 << 3;	 // undefined
	x = 5 << 72;	 // undefined
	x = -5 >> 3;	 // implementation defined, not portable
}

void
double_free(void)
{
	int *x = malloc(sizeof(int));
	*x = 9;
	free(x);
	free(x);
}

void
access_unallocated_memory(void)
{
	int a[3];
	int *beyond = a + 3;
	*beyond = 0;
}

void
modify_const_value(void)
{
	const int readonly = 10;
	int *p;
	p = (int *)&readonly; // you thought you hacked c because you drop the
			      // const qualifier
	*p = 20; // but you got undefined behavior instead
}

void
bad_pointer_arithmetic(void)
{
	char buffer[6] = "hello";
	char *p1 = buffer - 1; // undefined behavior
	char *p2 = buffer + 5; // OK, pointing to the '\0' inside the array
	char *p3 = buffer + 6; // OK, pointing to just beyond
	char *p4 = buffer + 7; // undefined behavior
	char value = *p4;      // obviously, undefined behavior
}

void
dereference_null_ptr(void)
{
	int *pointer = NULL;
	int value = *pointer; // dereferencing happens here
}

void
bad_linkage(void)
{
	// both internal and external linkage in THE SAME TRANSLATION UNIT
	// extern int var;
	// static int var;

	// fine, before extern we have internal linkage, we keep the static
	// static int var;
	// extern int var;

	// fine, we keep the same linkage
	// static int var;
	// static int var;

	// fine, same linkage also
	// extern int var;
	// extern int var;
}

void
divide_with_zero(void)
{
	int x = 1 / 0;
}

void
bad_pointer_alignment(void)
{
	// uint32 would need an alignemnt of either 2 or 4
	//  returns an alignment of either 2 or 4. BUT THE +1 GIVES AN ODD
	//  ALIGNMENT (odd address)
	char *memory_block = calloc(sizeof(uint32_t) + 1, 1);
	// possible undefined behavior
	// uint32_t *ptr = (uint32_t *)(memory_block + 1);

	// uint32_t mvalue = *intptr;

	uint32_t mvalue = 0;

	// avoid all the hassle with memcpy
	memcpy(&mvalue, memory_block + 1, sizeof mvalue);
}
