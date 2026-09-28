#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "gba/syscall.h"
#include "data.h"

extern u32 gChampionshipTrophyGfx;
extern u8 gText_Congratulations_2[];
extern u8 gText_YouCompletedTheSeason[];
extern u8 gGoldTrophyPalette[];
extern u8 gSilverTrophyPalette[];
extern u8 gBronzeTrophyPalette[];
extern u8 gText_Gold[];
extern u8 gText_Silver[];
extern u8 gText_Bronze[];


void sub_08012C4C(u32 a)
{
    u32 t;

    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x8F);
    ((void (*)(void))DrawBigText)();
    if (a <= 2) {
        DrawTextCenteredHighlight(GetString(0x91), 4, 1);
    } else {
        DrawTextCenteredHighlight(gText_Congratulations_2, 6, 1);
        DrawTextCenteredHighlight(gText_YouCompletedTheSeason, 0xA, 1);
    }
    if (a <= 2)
        RLUnCompVram(gChampionshipTrophyGfx, OBJ_VRAM0);
    if (a == 0) {
        t = (u32)gGoldTrophyPalette;
        DrawCachedSprite(0x58, 0x40, 0, t, a);
    }
    if (a == 1) {
        t = (u32)gSilverTrophyPalette;
        DrawCachedSprite(0x58, 0x40, 0, t, 0);
    }
    if (a == 2) {
        t = (u32)gBronzeTrophyPalette;
        DrawCachedSprite(0x58, 0x40, 0, t, 0);
    }
    if (a == 0)
        DrawTextCenteredHighlight(gText_Gold, 0x12, 1);
    if (a == 1)
        DrawTextCenteredHighlight(gText_Silver, 0x12, 1);
    if (a == 2)
        DrawTextCenteredHighlight(gText_Bronze, 0x12, 1);
}
