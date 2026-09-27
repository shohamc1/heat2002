#include "global.h"
#include "data.h"
#include "variables.h"

extern u32 gLaneCellLists[];
extern u32 gLaneCellGrids[];

void sub_0800BE00(void *base, s32 arg)
{
    s32 row = arg >> 8;

    *(u32 *)((u8 *)base + 0xF0) = arg;
    *(u32 *)((u8 *)base + 0xF4) = gLanePointTables[row + gTrackId * 12];
    *(u32 *)((u8 *)base + 0xF8) = gLaneSegmentTables[row + gTrackId * 12];
    *(u32 *)((u8 *)base + 0xFC) = gLaneCellLists[row + gTrackId * 12];
    *(u32 *)&((u16 *)base)[0x80] = gLaneCellGrids[row + gTrackId * 12];
    *(u32 *)&((u16 *)base)[0xAA] = *(u16 *)gLaneLengthPtrs[row + gTrackId * 12];
}
