#include "global.h"
#include "variables.h"


void sub_0833D210(u16 *r4)
{
    u32 r6 = 0;
    u32 r5 = 0x1F;
    u32 *r3 = gUnk_020392D0;
    u32 r7 = 0x80 << 1;

    do
    {
        u32 v = *r4;

        r4 = (u16 *)((u32)r4 + 2);
        {
            u32 r1 = v;
            u32 r2 = v;

            v &= r5;
            r1 = (s32)r1 >> 5;
            r1 &= r5;
            r2 = (s32)r2 >> 10;
            r2 &= r5;
            r3[0] = v << 16;
            r3[1] = r1 << 16;
            r3[2] = r2 << 16;
        }
        r3 = (u32 *)((u32)r3 + 12);
        r6++;
    } while (r6 != r7);
}
