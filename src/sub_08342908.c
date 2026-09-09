#include "global.h"

extern u8 gUnk_020391F0;
extern u8 gUnk_020390A8;
extern void gUnk_02009E0D(void);

u32 sub_0833FF44(void);
void sub_0833FF94(u32);

void sub_08342908(void)
{
    if (gUnk_020391F0 == 0)
    {
        u32 p = sub_0833FF44();
        if (p != 0)
        {
            *(u32 *)(p + 0x1C) = gUnk_020390A8;
            *(u32 *)(p + 0x18) = 100;
            *(u32 *)(p + 0x0C) = (u32)gUnk_02009E0D;
            sub_0833FF94(p);
        }
        gUnk_020391F0 = 1;
    }
}
