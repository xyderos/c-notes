#pragma once

#define IS_UNSIGNED_VALUE(value) (value >= 0 && ~value >= 0)

#define ISUNSIGNED_TYPE(type) ((type)0 - 1 > 0)

unsigned int bitwise_and(unsigned int n1, unsigned int n2);

unsigned int bitwise_or(unsigned int n1, unsigned int n2);

unsigned int bitwise_xor(unsigned int n1, unsigned int n2);

int bitwise_not(unsigned int n);

unsigned int shift_left(unsigned int n1, unsigned int n2);

unsigned int shift_right(unsigned int n1, unsigned int n2);

unsigned int is_odd_optimized(unsigned int n);

char *bit_pattern(unsigned int n);

unsigned int extract_byte(unsigned int number, unsigned int byte);

void set_byte(unsigned int *number, unsigned int byte);

void toogle_byte(unsigned int *number, unsigned int byte);

void clear_byte(unsigned int *number, unsigned int byte);

unsigned int extract_bit(unsigned int number, unsigned int bit);

void set_bit(unsigned int *number, unsigned int bit);

void toogle_bit(unsigned int *number, unsigned int bit);

void clear_bit(unsigned int *number, unsigned int bit);
