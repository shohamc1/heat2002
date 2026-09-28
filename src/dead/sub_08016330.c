#include "global.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

extern u8 gText_Credits[];

void sub_08011D2C(u32 a, void *b);
void sub_08006738(u8 *a);

void sub_08016330(u8 x)
{
    u8 buf[0x200];
    u16 *p;
    u16 i;
    u8 j, sel, cnt;
    u8 *q;

    p = (u16 *)0x06008000;
    FadeToColor(0, 0xF);
    sel = 0;
    if (x == 0)
        x = 1;
    cnt = x;
    if (gOptions[2] != 0)
        m4aSongNumStart(1);
    sub_08011D2C(1, buf);
    for (i = 0; i != 0x380; i++)
        *p++ = 0;
    sub_08006738(gText_Credits);
    j = 0x14;
    for (i = 0; i <= 0x13; i++) {
        DrawTextCenteredHighlight(gText_BlankRowMenu, (i + j - 0x14) % 32, 1);
        DrawTextCenteredHighlight(gCreditTexts[i + j - 0x14].text, (i + j - 0x14) % 32,
                     gCreditTexts[i + j - 0x14].highlight);
    }
    FadeToBrightenedPalette((u32)buf, 0xF);
    for (i = 0; i <= 0x13; i++)
        VBlankIntrWait();
    for (;;) {
        ReadKeys();
        if (gKeysPressed & 2)
            break;
        if (--cnt == 0) {
            cnt = x;
            if (++sel > 7) {
                sel = 0;
                j++;
                if (j == 0xB6)
                    break;
                q = gText_BlankRowMenu;
                DrawTextCenteredHighlight(q, (j - 1) % 32, 1);
                DrawTextCenteredHighlight(gCreditTexts[j - 1].text, (j - 1) % 32,
                             gCreditTexts[j - 1].highlight);
            }
            *(volatile u16 *)0x04000012 = (j - 0x14) * 8 + sel;
        }
        VBlankIntrWait();
    }
    FadeToColor(0, 0xF);
    ResetBgScroll();
}
