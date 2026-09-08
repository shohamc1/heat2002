#include "global.h"

void sub_08016E10(u32 src, u32 dest, u32 control)
{
    register u32 r0 __asm__("r0") = src;
    register u32 r1 __asm__("r1") = dest;
    register u32 r2 __asm__("r2") = control;

    __asm__ volatile("swi 0x0B" :: "r"(r0), "r"(r1), "r"(r2) : "memory");
}
