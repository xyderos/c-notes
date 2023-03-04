#include <check.h>

#include "../../src/bitfields/bitfields.h"

Suite *bitfields_suite(void);

START_TEST(TEST_SETTING_BIT_IN_BITFIELDS_SHOULD_BE_OKAY)
{
	memory_address_info_t mem_info;
	mem_info.data = 0x00;
	write_engine_is_on(&mem_info);

	ck_assert_int_eq(1, mem_info.bits.engine_is_on);
}
END_TEST
