#include <limits.h>
#include <stdlib.h>

#include "bitwise_operators.h"

#define FIRST (unsigned int)24
#define SECOND (unsigned int)16
#define THIRD (unsigned int)8
#define BYTE (unsigned int)0xFF
#define SINGLE_BIT (unsigned int)1

unsigned int
bitwise_and(unsigned int n1, unsigned int n2)
{
	return n1 & n2;
}

unsigned int
bitwise_or(unsigned int n1, unsigned int n2)
{
	return n1 | n2;
}

unsigned int
bitwise_xor(unsigned int n1, unsigned int n2)
{
	return n1 ^ n2;
}

int
bitwise_not(unsigned int n)
{
	return (int)~n;
}

unsigned int
shift_left(unsigned int n1, unsigned int n2)
{
	return n1 << n2;
}

unsigned int
shift_right(unsigned int n1, unsigned int n2)
{
	return n1 >> n2;
}

char *
bit_pattern(unsigned int n)
{
	unsigned char *result = NULL;
	unsigned int i = 0, x = 0, word = 0;
	unsigned mask = 1;
	word = CHAR_BIT * sizeof(int);
	result = malloc(word + 1);
	mask = mask << (word - 1);
	// shift
	for (i = 1; i <= word; i++) {
		x = (n & mask) ? 1 : 0; // identify
		result[i - 1] = '0' + x;
		mask >>= 1UL; // shift mask to the right by 1 bit
	}

	return result;
}

unsigned int
is_odd_optimized(unsigned int n)
{
	return n & (unsigned int)1;
}

unsigned int
extract_byte(unsigned int number, unsigned int byte)
{
	switch (byte) {
	case 1:
		return (number >> (unsigned int)FIRST);
	case 2:
		return (number >> (unsigned int)SECOND) & BYTE;
	case 3:
		return (number >> (unsigned int)THIRD) & BYTE;
	case 4:
		return number & BYTE;

	default:
		break;
	}

	return 0;
}

void
set_byte(unsigned int *number, unsigned int byte)
{
	switch (byte) {
	case 1:
		*number |= BYTE << FIRST;
		break;
	case 2:
		*number |= BYTE << SECOND;
		break;
	case 3:
		*number |= BYTE << THIRD;
		break;
	case 4:
		*number |= BYTE;
		break;
	default:
		*number = 0;
		break;
	}
}

void
toogle_byte(unsigned int *number, unsigned int byte)
{
	switch (byte) {
	case 1:
		*number ^= BYTE << FIRST;
		break;
	case 2:
		*number ^= BYTE << SECOND;
		break;
	case 3:
		*number ^= BYTE << THIRD;
		break;
	case 4:
		*number ^= BYTE;
		break;
	default:
		*number = 0;
		break;
	}
}

void
clear_byte(unsigned int *number, unsigned int byte)
{
	switch (byte) {
	case 1:
		*number &= ~(BYTE << FIRST);
		break;
	case 2:
		*number &= ~(BYTE << SECOND);
		break;
	case 3:
		*number &= ~(BYTE << THIRD);
		break;
	case 4:
		*number &= ~(BYTE);
		break;
	default:
		*number = 0;
		break;
	}
}

unsigned int
extract_bit(unsigned int number, unsigned int bit)
{
	return (number >> bit) & SINGLE_BIT;
}

void
set_bit(unsigned int *number, unsigned int bit)
{
	*number |= SINGLE_BIT << bit;
}

void
toogle_bit(unsigned int *number, unsigned int bit)
{
	*number ^= SINGLE_BIT << bit;
}

void
clear_bit(unsigned int *number, unsigned int bit)
{
	*number &= ~(SINGLE_BIT << bit);
}
