#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"
#include "m4a.h"

extern u8 gText_ViewLicensingInfo[];
extern u8 gText_BlankRow12_4[];

extern u8 gOptionsMenuMinValues[];
extern u8 gOptionsMenuMaxValues[];

void DrawOptionsMenu(u32 a)
{
    u8 *p;

    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(52));

    DrawText(GetString(53), 3, 5, a == 0);

    DrawText(GetString(56), 3, 7, a == 1);

    DrawText(GetString(58), 3, 9, a == 2);

    DrawText(GetString(59), 3, 11, a == 3);

    DrawText(GetString(191), 3, 13, a == 4);
    p = gText_ViewLicensingInfo;
    DrawText(p, 3, 15, a == 5);
    p = gText_BlankRow12_4;
    DrawText(p, 21, 5, a == 0);
    DrawText(GetString(gOptions[0] + 61), 21, 5, a == 0);
    DrawText(GetString(gOptions[1] + 182), 21, 7, a == 1);
    DrawText(GetString(gOptions[2] + 65), 21, 9, a == 2);
    DrawText(GetString(gOptions[3] + 65), 21, 11, a == 3);
    DrawText(GetString(gOptions[4] + 65), 21, 13, a == 4);
}

u8 OptionsMenu(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    LoadMenuScreen(7, (u16 *)buf);
    DrawOptionsMenu(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 64;
    do {
        ReadKeys();
        DrawOptionsMenu(v);
        if (gKeysPressed & 1) {
            if (v == 5) {
                ShowCreditsPage1();
                ShowCreditsPage2();
                ShowCreditsPage3();
                return sel;
            }
            sel = v;
        }
        if (gKeysPressed & 2)
            sel = 1;
        v = MenuMoveVertical(gKeysPressed, v, 0, 5);
        gOptions[v] = MenuMoveHorizontal(gKeysPressed, gOptions[v], gOptionsMenuMinValues[v], gOptionsMenuMaxValues[v]);
        if (v == 2) {
            if ((gKeysPressed & 0x30) && gOptions[2] != 0)
                StartMenuMusic();
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
