#include "global.h"

void sub_08016E2C(u32 r0)
{
    __asm__ volatile("swi 0x1" :: "r"(r0));
}
