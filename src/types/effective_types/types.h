#pragma once

#include <stdint.h>

typedef union buf buffer_t;
union buf {
	char c[sizeof(int[25])];
	int i[25];
};

void effective_types(void);

uint32_t change_bytes(uint32_t);

buffer_t change_via_non_character_type(void);
