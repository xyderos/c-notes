#include "numbers.h"

void
numbers(void)
{
	uint32_t u32 = 32; // 32-bits wide
	uint8_t u8 = 255;  // 8-bits wide
	int64_t i64 = -65; // 64 bit in two's complement representation

	signed char c = 127;		 // 1 byte
	signed short int si = 32767;	 // at least 16 bytes
	signed int i = 32767;		 // at least 16 bits
	signed long int li = 2147483647; // at least 32 bits

	int d = 42;
	int o = 052;  // octal
	int x = 0xaf; // hex

	unsigned int ui = 65535u; // unsigned
	long int lii = 65536l;	  // l long

	float f = 0.314f; // float
	double dd = 0.314;
	long double ld = 0.314l; // long double
	double cord_x = 1.;	 // fractional part is optional
	double cord_y = .1;	 // number part is optional

	// scientific notation
	double sd = 1.2e3; // scaled by 10^3, that is 1200.0
}
