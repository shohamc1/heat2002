#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"
void sub_080164A8(void)
{
    u8 buf[0x200];
    u16 keys;
    sub_080019B4((struct MusicPlayerInfo *)0x02001F60);
    sub_080019B4((struct MusicPlayerInfo *)0x02001F20);
    sub_080045D8();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    sub_080047DC();
    ResetBgScroll();
    gIsLinkRace = 0;
    sub_08011C9C(1, (u16 *)buf);
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x75);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0x75), 0x0A, 1);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    do {
        VBlankIntrWait();
        ReadKeys();
        DrawTextCenteredHighlight(GetString(0x0F), 0x0F, 1);
    } while (!(*(u16 *)0x020005CC & 8));
    FadeToColor(0, 0x0F);
}
