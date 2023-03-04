#pragma once

// you can check the type of an argument using the generic macro
#define is_const_int_good(x) \
	_Generic((&x), \
 const int *: "a const int", \
 int *: "a non-const int", \
 default: "of other type")

// This is bad because in the controlling expression,
// everything is dropped after the _Generic primary expression
#define is_const_int_bad(x)                   \
	_Generic((x), const int               \
		 : "a const int", int         \
		 : "a non-const int", default \
		 : "of other type")

char *check_if_a_number_is_const_int(void);
