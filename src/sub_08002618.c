#include "global.h"
#include "variables.h"


void sub_08002618(u32 seed)
{
    register u32 s asm("r1") = seed;
    u32 *p = &gUnk_020020D4;
    u32 v;

    if (s != 0)
        v = 0x7FFFFFFF & s;
    else
        v = 1;
    *p = v;
}
