#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

extern const u8 gTitleScreenGfx[];
extern const u16 gTitleScreenMetatileMap[];
extern const u8 gTitleScreenPalette[];
extern u8 gUnk_0202EEFC;
extern u16 gUnk_083FDE5E[];

u8 TitleScreen(void)
{
    u16 buf[0x100];
    s32 n;
    u16 i;
    u8 j;

    n = 3000;
    if (gOptions[2] != 0)
        m4aSongNumStart(1);
    gUnk_020020B4 = 1;
    WaitForVBlank();
    REG_BG2CNT = BGCNT_PRIORITY(1) | BGCNT_256COLOR | BGCNT_SCREENBASE(31);
    REG_BG0CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(28);
    REG_DISPCNT = DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON;
    CpuCopy16(gTitleScreenGfx, VRAM, 0xA280);
    CpuCopy16(gTextLayerTiles, BG_SCREEN_ADDR(24), 0x2000);
    DrawBackdropMetatileMap(gTitleScreenMetatileMap);
    i = 0;
    do {
        #if PORTABLE
        *(u16 *)(*(u8 *volatile *)&gTextLayerMapPtr[0] + 2 * i) = 0;
#else
        *(u16 *)(*(volatile u32 *)&gTextLayerMapPtr[0] + 2 * i) = 0;
#endif
        i++;
    } while (i != 896);
    CpuCopy16(gTitleScreenPalette, buf, 0x200);
    CpuCopy16(gFontPalette, &buf[0xF0], 0x20);
    CpuCopy16(gFontPalette, &buf[0xE0], 0x20);
    buf[0xEA] = RgbFromPercent(0x34, 0x34, 0x34);
    buf[0xEB] = RgbFromPercent(0x24, 0x24, 0x24);
    buf[0xEC] = RgbFromPercent(0x0E, 0x0E, 0x0E);
    buf[0xED] = RgbFromPercent(0, 0, 0);
    FadeToBrightenedPalette(buf, 0x0F);
    j = 0;
    while (!(gKeysHeld & 8) && n != 0) {
        ReadKeys();
        i = 0;
        do {
            #if PORTABLE
        *(u16 *)(*(u8 *volatile *)&gTextLayerMapPtr[0] + 2 * i) = 0;
#else
        *(u16 *)(*(volatile u32 *)&gTextLayerMapPtr[0] + 2 * i) = 0;
#endif
            i++;
        } while (i != 896);
        if ((j & 0x1F) <= 0x0E)
            DrawTextCenteredHighlight(GetString(15), 16, 1);
        j++;
        if ((gKeysHeld & 8) && gOptions[3] != 0)
            m4aSongNumStart(9);
        WaitForVBlank();
        n--;
    }
    if (n == 0)
        m4aMPlayFadeOut(&gBgMusicPlayer, 2);
    FadeToColor(0, 0x0F);
    if (n == 0)
        return 1;
    return 0;
}

void DrawMainMenuItems(u8 selected)
{
    u8 *d;
    u32 i;
    u16 *textIds;
    u32 row;

    d = &gUnk_0202EEFC;
    /* The ROM stores r0 after the call: the stub returns nothing, so the
       byte gets whatever r0 held. */
    *d = ((u8 (*)(void))DummyMainMenuHook)();
    DummyUiFontLoad(gUiFontTable[0]);
    DrawBigText(GetString(89));
    i = 0;
    row = 5;
    textIds = gUnk_083FDE5E;
    do {
        DrawTextCenteredHighlight(GetString(*textIds), row, selected == i);
        row += 2;
        textIds++;
        i++;
    } while (i != 7);
}

void DrawMainMenu(u8 selected)
{
    LoadMainMenuBackdrop();
    DrawMainMenuItems(selected);
}
