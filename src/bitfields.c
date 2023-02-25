#include "bitfields.h"

void
write_engine_is_on(memory_address_info_t *info)
{
	info->bits.engine_is_on = 1;
}
