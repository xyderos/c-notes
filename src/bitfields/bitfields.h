#pragma once

#include <stdint.h>

typedef struct bits {
	unsigned int accelerator_is_on : 1;
	unsigned int cruise_control_is_on : 1;
	unsigned int air_conditioner_is_on : 1;
	unsigned int airbags_are_on : 1;
	unsigned int engine_is_on : 1;
} bits_t;

// neat hack
typedef struct memory_address_info {
	union {
		bits_t bits;
		unsigned int data;
	};
} memory_address_info_t;

void write_engine_is_on(memory_address_info_t *info);

// check endianess and platform specific info when declaring a bit field
typedef union {
	struct details {
#if defined(LITTLE_ENDIAN)
		uint8_t comms : 1;
		uint8_t hw : 1;
		uint8_t _reserved : 6;
#else
		uint8_t _reserved : 6;
		uint8_t hw : 1;
		uint8_t comms : 1;
#endif
	};
	uint8_t data;
} hw_status_t;

// keepin mind that since storage allignment is not specified, there might also
// be other possible layouts
struct a_possible_allignment_layout {
	// 2 bytes
	short s;
	// 1 byte
	char c;
	// 1 bit
	int bit : 1;
	// since 2 +1 = 3 bytes and we want to add a bit and 4 bits also, there
	// will be some padding from the compiler of 3 bits
	int nibble : 4;
	// 7 bits
	int sept : 7;
};

// final size is 2 bytes
struct unnamed_bit_fields_in_structs {
	unsigned char c1 : 1;
	// although you specify a 2 bit unnamed field
	unsigned char : 2;
	unsigned char c2 : 2;
	// causes c3 to start from char boundary, so you essentially skip 3 bits
	// until c3
	unsigned char : 0;
	unsigned char c3 : 4;
	// 3 padding bits after c4
	unsigned char c4 : 1;
};
