#include "global.h"

void sub_08016E30(u32 r0, u32 r1, u32 r2)
{
    r2 = 0;
    __asm__ volatile("swi 0x5" :: "r"(r0), "r"(r1), "r"(r2));
}
