#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"
#include "variables.h"
void sub_080164A8(void)
{
    u8 buf[0x200];
    u16 keys;
    m4aMPlayStop((struct MusicPlayerInfo *)0x02001F60);
    m4aMPlayStop((struct MusicPlayerInfo *)0x02001F20);
    ResetSpriteOrderTable();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    UpdateSprites();
    ResetBgScroll();
    gIsLinkRace = 0;
    LoadMenuScreen(1, (u16 *)buf);
    DummyUiFontLoad(gUiFontTable[0]);
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
