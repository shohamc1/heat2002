#include "global.h"

extern u8 gUnk_020390D4;
extern u8 gUnk_020391F0;
extern u8 gUnk_0203916C;
extern u32 gUnk_0203DE24;

void *sub_0833FF44(void);
void sub_0833FF94(u32);
void sub_083429E8(void);

void sub_08342B04(void)
{
    u8 t;
    u32 p;

    gUnk_020390D4 = 0;
    gUnk_020391F0 = 0;
    t = gUnk_0203916C - 3;
    if (t <= 1)
    {
        p = (u32)sub_0833FF44();
        if (p != 0)
        {
            *(u32 *)(p + 0x18) = 0;
            *(u32 *)(p + 0x0C) = (u32)sub_083429E8;
            sub_0833FF94(p);
            gUnk_0203DE24 = p;
        }
    }
}
