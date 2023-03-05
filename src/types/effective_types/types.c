#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

void
effective_types(void)
{
	// effective type uint32_t, and this type never changes
	uint32_t a = 0.0;
	// effective type is uint32_t, too, since *pa is the object a
	uint32_t *pa = &a;
	// the object pointed to by q has no effective type, yet
	void *q = malloc(sizeof(uint32_t));
	// the object pointed to by q still has no effective type,
	// because nobody has written to it
	uint32_t *qb = q;
	// *qb now has effective type uint32_t because a uint32_t value was
	// written
	*qb = 37;
	// the object pointed to by r has no effective type, yet, although
	// it is initialized
	void *r = calloc(1, sizeof(uint32_t));
	// the object pointed to by r still has no effective type,
	// because nobody has written to or read from it
	uint32_t *rc = r;
	// *rc now has effective type uint32_t because a value is read
	// from it with that type. The read operation is valid because we used
	// calloc. Now the object pointed to by r (which is the same as *rc) has
	// gained an effective type, although we didn't change its value.
	uint32_t c = *rc;
	// the object pointed to by s has no effective type, yet.
	void *s = malloc(sizeof(uint32_t));
	// the object pointed to by s now has effective type uint32_t
	// because an uint32_t value is copied into it.
	memcpy(s, r, sizeof(uint32_t));
}

uint32_t
change_bytes(uint32_t a)
{
	// conversion from incompatible types needs a cast
	unsigned char *ap = (unsigned char *)&a;
	for (size_t i = 0; i < sizeof a; ++i) {
		ap[i] = 0xFF;
	}

	return a;
}

buffer_t
change_via_non_character_type(void)
{
	buffer_t a = { .c = { 0 } }; // reserve a buffer and initialize
	int *b = a.i;		     // no cast necessary
	*b = 1;

	return a;
}
