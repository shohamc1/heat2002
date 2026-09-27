#include "global.h"
#include "variables.h"


struct Unk0800C358 {
    u8 unk00[0x18];
    s32 unk18;
    s32 unk1C;
    u8 unk20[0xD4];
    u32 *lanePoints;
    u32 *laneSegments;
    u32 *unkFC;
    u16 *unk100;
};

u32 sub_0800C2CC(s32 a, s32 b, u32 *c, u8 *d);

u32 sub_0800C358(struct Unk0800C358 *p)
{
    u32 *table;
    u32 *tex;
    u32 best;
    u8 *cur;
    s32 y;
    s32 x;
    s32 yi;
    s32 xi;
    u8 *entry;
    u8 e;
    u32 res;
    u32 sp4;
    u32 sp8;

    table = p->laneSegments;
    tex = p->lanePoints;
    best = -1;
    gClosestLaneSegment[0] = (u32)cur;
    y = p->unk18 >> 16;
    x = p->unk1C >> 16;
    yi = p->unk18 >> 23;
    xi = p->unk1C >> 23;
    if (yi < 0)
        yi = 0;
    if (xi < 0)
        xi = 0;
    if (yi > 47)
        yi = 47;
    if (xi > 47)
        xi = 47;
    /* Offset first preserves the ROM register and address-load order. */
    entry = (u8 *)(p->unk100[xi * 48 + yi] + (u32)p->unkFC);
    while (*entry != 0xFF) {
        e = *entry;
        cur = (u8 *)table + e * 20;
        res = sub_0800C2CC(y, x, tex, cur);
        if (res <= best) {
            best = res;
            gClosestLaneSegment[0] = (u32)cur;
            gClosestLaneSegmentIndex[0] = e;
            sp4 = gClosestLanePointX[0];
            sp8 = gClosestLanePointZ[0];
        }
        entry++;
    }
    gClosestLanePointX[0] = sp4;
    gClosestLanePointZ[0] = sp8;
    return best;
}
