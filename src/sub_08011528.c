#include "global.h"
#include "functions.h"
#include "variables.h"



u8 sub_08011528(void)
{
    u8 buf[0x200];
    s8 sel;
    u16 keys;
    u8 v;

    ResetLinkState();
    gLinkRecvWords[0] = 0;
    gLinkRecvWords[4] = 0;
    gLinkRecvWords[8] = 0;
    gLinkRecvWords[12] = 0;
    v = 0;
    SortLinkCarsByTime();
    sub_08011C9C(0, (u16 *)buf);
    sub_0801137C();
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do
    {
        keys = gPlayerKeys[0];
        if (ExchangeLinkInput() != 0)
        {
            sel = 5;
        }
        else
        {
            keys = (keys ^ gPlayerKeys[0]) & gPlayerKeys[0];
            sub_0801137C();
            if (gLinkPlayerId[0] != 0)
                DrawTextCenteredHighlight(GetString(0x58), 0x0E, 1);
            else
                DrawTextCenteredHighlight(GetString(0x0F), 0x0E, 1);
            if (keys & 9)
                sel = v;
            WaitForVBlank();
        }
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}
