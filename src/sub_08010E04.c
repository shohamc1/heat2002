#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"
#include "gba/syscall.h"


u8 sub_08010E04(u8 a)
{
    u8 unused[0xC];

    GetString(0x9C);
    /* DrawBigText: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(void))DrawBigText)();
    DrawText(gText_BlankRowMenu, 0, 6, 0);
    DrawTextCenteredHighlight(gDriverRoster[a].name, 6, 1);
    CpuCopy16(gDriverCarPalettes[a], OBJ_PLTT, OBJ_PLTT_SIZE);
    RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[a], OBJ_VRAM0);
    RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[a], OBJ_VRAM0 + 0x1000);
    sub_08010194(0x38, 0x40, 0);
    sub_08010194(0x78, 0x40, 0x80);
}
