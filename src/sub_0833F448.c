#include "global.h"
#include "variables.h"

extern const struct TrackSeg *gUnk_020269C0[];

void sub_0833F448(u32 r0)
{
    gModule_TrackSegs = gUnk_020269C0[r0];
    gUnk_0203B6F0 = 0x14;
}
