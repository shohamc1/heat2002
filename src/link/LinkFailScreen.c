#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"
#include "variables.h"

void LinkFailScreen(void)
{
    u8 fadePalette[0x200];
    u16 keys;
    m4aMPlayStop(&gEngineSoundPlayer);
    m4aMPlayStop(&gBgMusicPlayer);
    ResetSpriteOrderTable();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    UpdateSprites();
    ResetBgScroll();
    gIsLinkRace = 0;
    LoadMenuScreen(1, (u16 *)fadePalette);
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(117));
    DrawTextCenteredHighlight(GetString(117), 10, 1);
    FadeToBrightenedPalette(fadePalette, 0x0F);
    do {
        VBlankIntrWait();
        ReadKeys();
        DrawTextCenteredHighlight(GetString(15), 15, 1);
    } while (!(*(u16 *)&gKeysPressed & 8));
    FadeToColor(0, 0x0F);
}
