#include "global.h"

void sub_08016E20(void)
{
    register u32 r1 __asm__("r1") = 1;

    __asm__ volatile("swi 0x25" :: "r"(r1));
}
