#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
u8 sub_08014874(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 v;
    s32 sel;
    v = b;
    LoadMenuScreen(5, (u16 *)buf);
    sub_08014708(a, v);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014708(a, v);
    retry:
        v = MenuMoveVertical(gKeysPressed, v, (b >> 2) * 4, (b >> 2) * 4 + 3);
        if ((s8)gChallengeStatus[v] == -1)
            goto retry;
        if (gKeysPressed & 3)
            sel = 1;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return v;
}
