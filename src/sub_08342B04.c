#include "global.h"
#include "variables.h"


void *sub_0833FF44(void);
void sub_0833FF94(u32);
void sub_083429E8(void);

void sub_08342B04(void)
{
    u8 t;
    u32 p;

    gModule_RaceStarted = 0;
    gModule_RaceEndState = 0;
    t = gModule_GameMode[0] - 3;
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
