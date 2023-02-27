#include <string.h>

#include "check_type.h"

char *
check_if_a_number_is_const_int(void)
{
	const int i = 0;
	return strdup(is_const_int_good(i));
}
