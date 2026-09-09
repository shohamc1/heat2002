#include "global.h"

void sub_08344B68(u32 a, u32 b)
{
    u32 c = 0;
    __asm__ volatile("swi 0x04" :: "r"(a), "r"(b), "r"(c));
}
