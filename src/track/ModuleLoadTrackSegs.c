#include "global.h"
#include "variables.h"

extern const struct TrackSeg *gUnk_020269C0[];

void ModuleLoadTrackSegs(u32 trackId)
{
    gModule_TrackSegs = gUnk_020269C0[trackId];
    gUnk_0203B6F0 = 0x14;
}
