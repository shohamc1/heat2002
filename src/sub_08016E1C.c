#include "global.h"

void sub_08016E1C(u32 r0, u32 r1)
{
    __asm__ volatile("swi 18" :: "r"(r0), "r"(r1));
}
