#include "global.h"
#include "functions.h"
#include "variables.h"



u8 sub_0801164C(void)
{
    u8 buf[0x200];
    s8 sel;
    s8 v;
    u16 old;
    u16 keys;

    ResetLinkState();
    v = 0;
    sub_08011C9C(1, (u16 *)buf);
    sub_080115D8(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do
    {
        old = gPlayerKeys[0];
        if (ExchangeLinkInput() != 0)
        {
            sel = 5;
        }
        else
        {
            keys = (gPlayerKeys[0] ^ old) & gPlayerKeys[0];
            if (keys & 9)
                sel = v;
            v = MenuMoveVertical(keys, v, 0, 3);
            sub_080115D8(v);
            WaitForVBlank();
        }
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
