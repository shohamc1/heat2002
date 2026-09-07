#include "global.h"

void sub_08016E0C(u32 src, u32 dest, u32 mode)
{
    register u32 r0 __asm__("r0") = src;
    register u32 r1 __asm__("r1") = dest;
    register u32 r2 __asm__("r2") = mode;

    __asm__ volatile("swi 0x0C" :: "r"(r0), "r"(r1), "r"(r2) : "memory");
}
