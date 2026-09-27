#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"
#include "gba/syscall.h"


struct Tbl8 {
    u32 p;
    u32 unk;
};


u8 sub_08010E04(u8 a)
{
    u8 unused[0xC];

    GetString(0x9C);
    /* sub_080065A8: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(void))sub_080065A8)();
    DrawText(gText_BlankRowMenu, 0, 6, 0);
    {
        struct Tbl8 *tbl = (struct Tbl8 *)gDriverRoster;

        DrawTextCenteredHighlight((u8 *)tbl[a].p, 6, 1);
    }
    CpuCopy16(gDriverCarPalettes[a], OBJ_PLTT, OBJ_PLTT_SIZE);
    RLUnCompVram(*(u32 *)gDriverCarGfxLeftTiles[a], OBJ_VRAM0);
    RLUnCompVram(*(u32 *)gDriverCarGfxRightTiles[a], OBJ_VRAM0 + 0x1000);
    sub_08010194(0x38, 0x40, 0);
    sub_08010194(0x78, 0x40, 0x80);
}
