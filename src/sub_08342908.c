#include "global.h"
#include "variables.h"

extern u8 gUnk_020390A8;
void sub_0834288C(void);

void *sub_0833FF44(void);
void sub_0833FF94(u32);

void sub_08342908(void)
{
    if (gUnk_020391F0 == 0)
    {
        u32 p = (u32)sub_0833FF44();
        if (p != 0)
        {
            *(u32 *)(p + 0x1C) = gUnk_020390A8;
            *(u32 *)(p + 0x18) = 100;
            *(u32 *)(p + 0x0C) = (u32)sub_0834288C;
            sub_0833FF94(p);
        }
        gUnk_020391F0 = 1;
    }
}
