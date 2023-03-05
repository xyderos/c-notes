#include "memory.h"

void *
aligned_memory(unsigned int bytes)
{
	char *ptr = aligned_alloc(256, bytes);
	return !ptr ? NULL : ptr;
}
