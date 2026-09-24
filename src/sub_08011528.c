#include "global.h"

extern u16 gUnk_0202EF40[];
extern u16 gUnk_020020A0;
extern u8 gLinkPlayerId;

extern void ResetLinkState(void);
extern void SortLinkCarsByTime(void);
extern void sub_08011C9C(u8 a, void *b);
extern void sub_0801137C(void);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern s32 ExchangeLinkInput(void);
extern u32 GetString(u16 idx);
extern void DrawTextCenteredHighlight(u32 a, u32 b, u32 c);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);

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
    sub_08011C9C(0, buf);
    sub_0801137C();
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do
    {
        keys = gUnk_020020A0;
        if (ExchangeLinkInput() != 0)
        {
            sel = 5;
        }
        else
        {
            keys = (keys ^ gUnk_020020A0) & gUnk_020020A0;
            sub_0801137C();
            if (gLinkPlayerId != 0)
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
