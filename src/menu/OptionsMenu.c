#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
extern u8 gOptionsMenuMinValues[];
extern u8 gOptionsMenuMaxValues[];
u8 OptionsMenu(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(7, (u16 *)buf);
    DrawOptionsMenu(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawOptionsMenu(v);
        if (gKeysPressed & 1) {
            if (v == 5) {
                sub_0800F600();
                sub_0800F6A0();
                sub_0800F740();
                return sel;
            }
            sel = v;
        }
        if (gKeysPressed & 2)
            sel = 1;
        v = MenuMoveVertical(gKeysPressed, v, 0, 5);
        gOptions[v] = MenuMoveHorizontal(gKeysPressed, gOptions[v],
                                        gOptionsMenuMinValues[v], gOptionsMenuMaxValues[v]);
        if (v == 2) {
            if ((gKeysPressed & 0x30) && gOptions[2] != 0)
                sub_080100B0();
            if ((gKeysPressed & 0x30) && gOptions[2] == 0)
                StopAllSongs();
        }
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
