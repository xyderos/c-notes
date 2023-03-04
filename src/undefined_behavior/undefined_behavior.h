#pragma once

// Do not unit test that, there is nothing to expect from these cases

void return_stack_memory_address(void);

void mess_aroumd_with_overlapping_memory(void);

void overflow_signed_integers(void);

void usage_of_uninitialized_value(void);

void dangling_pointer(void);

void wild_pointer(void);

void modify_string_literal(void);

void bit_shifting_with_weird_values(void);

void double_free(void);

void access_unallocated_memory(void);

void modify_const_value(void);

void bad_pointer_arithmetic(void);

void dereference_null_ptr(void);

void bad_linkage(void);

void divide_with_zero(void);

void bad_pointer_alignment(void);
