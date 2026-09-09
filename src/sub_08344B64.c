#include "global.h"

void sub_08344B64(u32 r0, u32 r1, u32 r2)
{
    __asm__ volatile("swi 0xb" :: "r"(r0), "r"(r1), "r"(r2));
}
