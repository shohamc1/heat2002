#include "global.h"
#include "data.h"
#include "variables.h"

extern const u8 *const gLaneCellLists[];
extern const u8 *const gLaneCellGrids[];

void sub_0800BE00(void *base, s32 arg)
{
    s32 row = arg >> 8;

    *(u32 *)((u8 *)base + 0xF0) = arg;
    *(u32 *)((u8 *)base + 0xF4) = (u32)gLanePointTables[row + gTrackId * 12];
    *(u32 *)((u8 *)base + 0xF8) = (u32)gLaneSegmentTables[row + gTrackId * 12];
    *(u32 *)((u8 *)base + 0xFC) = (u32)gLaneCellLists[row + gTrackId * 12];
    *(u32 *)&((u16 *)base)[0x80] = (u32)gLaneCellGrids[row + gTrackId * 12];
    *(u32 *)&((u16 *)base)[0xAA] = *(u16 *)gLaneLengthPtrs[row + gTrackId * 12];
}
