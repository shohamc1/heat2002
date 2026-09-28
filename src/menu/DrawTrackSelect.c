#include "global.h"
#include "gba/compat.h"
#include "data.h"
#include "functions.h"
#include "gba/syscall.h"
#include "variables.h"

extern const u8 gText_TrackMichigan[];
extern const u8 gText_TrackIntlSpeedway[];
extern const u8 gTrackSelectArrowPalette[];
extern const u8 gTrackSelectLeftArrowGfx[];
extern const u8 gTrackSelectRightArrowGfx[];

struct Inner
{
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
};

struct Big
{
    u8 pad[0xC];
    u32 fieldC;
    struct Inner *inner;
    u32 field14;
};

extern struct Big gTrackSelectEntries[];

void sub_0801027C(u32 tile, u32 pal, u32 c);

u8 DrawTrackSelect(u8 a, u8 b)
{
    u8 unused[0x34];
    u8 *p;

    if (b != 0) {
        GetString(0xA1);
        /* DrawBigText: this file's old local prototype differs from
           functions.h; call through the old signature (solved-walls 31). */
        ((void (*)(void))DrawBigText)();
    }
    p = (u8 *)gText_BlankRowMenu;
    DrawText(p, 0, 4, 0);
    DrawText(p, 0, 5, 0);
    if (a != 3) {
        DrawTextCenteredHighlight(gTrackSelectEntries[a].fieldC, 4, 1);
    } else {
        DrawTextCenteredHighlight(gText_TrackMichigan, 4, 1);
        DrawTextCenteredHighlight(gText_TrackIntlSpeedway, 5, 1);
    }
    CpuCopy16(gTrackSelectEntries[a].field14, OBJ_PLTT, OBJ_PLTT_SIZE);
    CpuCopy16((u32)gTrackSelectArrowPalette, OBJ_PLTT + 0x1E0, 0x20);
    RLUnCompVram(gTrackSelectEntries[a].inner->f0, OBJ_VRAM0);
    RLUnCompVram(gTrackSelectEntries[a].inner->f4, OBJ_VRAM0 + 0x1000);
    RLUnCompVram(gTrackSelectEntries[a].inner->f8, OBJ_VRAM0 + 0x2000);
    RLUnCompVram(gTrackSelectEntries[a].inner->fC, OBJ_VRAM0 + 0x3000);
    sub_08010194(0x38, 0x20, 0);
    sub_08010194(0x78, 0x20, 0x80);
    sub_08010194(0x38, 0x60, 0x80 << 1);
    sub_08010194(0x78, 0x60, 0xC0 << 1);
    if (b != 0 && (gTrackSelectFrameCount & 4) != 0) {
        RLUnCompVram((u32)gTrackSelectLeftArrowGfx, OBJ_VRAM1);
        RLUnCompVram((u32)gTrackSelectRightArrowGfx, OBJ_VRAM1 + 0x1000);
        if (a != 0)
            sub_0801027C(0x10, 0x48, 0x80 << 2);
        if (a != 0xB)
            sub_0801027C(0xD0, 0x48, 0xA0 << 2);
    }
    gTrackSelectFrameCount++;
}
