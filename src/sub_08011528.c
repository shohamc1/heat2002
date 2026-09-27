#include "global.h"
#include "functions.h"

extern u16 gUnk_0202EF40[];
extern u16 gUnk_020020A0[];
extern u8 gLinkPlayerId[];


u8 sub_08011528(void)
{
    u8 buf[0x200];
    s8 sel;
    u16 keys;
    u8 v;

    ResetLinkState();
    gUnk_0202EF40[0] = 0;
    gUnk_0202EF40[4] = 0;
    gUnk_0202EF40[8] = 0;
    gUnk_0202EF40[12] = 0;
    v = 0;
    SortLinkCarsByTime();
    sub_08011C9C(0, (u16 *)buf);
    sub_0801137C();
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do
    {
        keys = gUnk_020020A0[0];
        if (ExchangeLinkInput() != 0)
        {
            sel = 5;
        }
        else
        {
            keys = (keys ^ gUnk_020020A0[0]) & gUnk_020020A0[0];
            sub_0801137C();
            if (gLinkPlayerId[0] != 0)
                DrawTextCenteredHighlight((u8 *)(GetString(0x58)), 0x0E, 1);
            else
                DrawTextCenteredHighlight((u8 *)(GetString(0x0F)), 0x0E, 1);
            if (keys & 9)
                sel = v;
            WaitForVBlank();
        }
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
