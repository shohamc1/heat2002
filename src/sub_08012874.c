#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"



void sub_08012874(s8 a)
{
    void *p;
    u8 buf[0x200];
    s8 sel;

    ZeroTextLayer();
    sub_0800F498();
    p = gResultsScreenPalette;
    sub_0800F328((u32)p, (u16 *)buf);
    /* sub_080127E4: this file's old prototype took u8; the matched definition takes s8 */
    ((void (*)(u8))sub_080127E4)(a);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8))sub_080127E4)(a);
        if (gKeysPressed & 1)
            sel = a;
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
}
