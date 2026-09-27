#include "global.h"
#include "gba/io_reg.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

u8 StandingsScreen(void)
{
    void *p;
    u8 buf[0x200];
    u8 mode;
    s8 v;
    s8 sel;
    mode = 0;
    SortCarsByPoints();
    v = 0;
    ZeroTextLayer();
    sub_0800F498();
    p = gResultsScreenPalette;
    sub_0800F328((u32)p, (u16 *)buf);
    sub_08014104(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014104(mode);
        if (gKeysPressed & A_BUTTON)
            sel = v;
        if ((gKeysPressed & DPAD_UP) && mode == 1) {
            mode = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && mode == 0) {
            mode = 1;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        v = MenuMoveVertical(gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
