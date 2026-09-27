#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
extern u8 gUnk_0202EF14;
u8 sub_0801465C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(5, (u16 *)buf);
    sub_08014614(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014614(v);
        if (gKeysPressed & 1) {
            sel = v;
            gUnk_0202EF14 = v;
        }
    retry:
/* old prototype u8 MenuMoveVertical(...): the s16 return shuffles the
        r5/r6 allocation for v and sel */
        v = ((u8 (*)(u16, s8, u32, u32))MenuMoveVertical)(gKeysPressed, v, 0, 3);
        if (gUnk_0202EF08[v] == 0)
            goto retry;
        if (gKeysPressed & 2)
            sel = 0;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
