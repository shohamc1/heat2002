#include "global.h"

extern u8 gModule_PitStopNeeded[];
extern u8 gModule_BlankRow20[];
extern u8 gUnk_0203B6F8;

u8 sub_08340028(void);
void sub_0833EE88(u8 *a, u32 b, u32 c);

void sub_0833E59C(void)
{
    u32 p;

    if (sub_08340028() != 0 && (gUnk_0203B6F8 & 8) != 0)
    {
        p = (u32)gModule_PitStopNeeded;
        sub_0833EE88((u8 *)p, 6, 1);
    }
    else
    {
        p = (u32)gModule_BlankRow20;
        sub_0833EE88((u8 *)p, 6, 1);
    }
    gUnk_0203B6F8 = gUnk_0203B6F8 + 1;
}
