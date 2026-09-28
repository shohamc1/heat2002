#include "global.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

extern u16 gUnk_020020B8;


u8 sub_080122B4(void)
{
    u8 buf[0x200];
    u8 v;
    u8 sel;
    s8 r;

    v = 0;
    sel = 0x40;
    ResetLinkState();
    ZeroTextLayer();
    LoadMenuBackdrop();
    BuildScreenPalette((u32)gMenuPalette, (u16 *)buf);
    /* sub_08012228: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8))sub_08012228)(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    gUnk_020020B8 = v;
    do
    {
        ReadKeys();
        ((void (*)(u8))sub_08012228)(v);
        r = sub_08012074();
        switch (r)
        {
        case 1:
            sel = 1;
            break;
        case -1:
            sel = 0;
            break;
        }
        if (gKeysPressed & 2)
            sel = 0;
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
