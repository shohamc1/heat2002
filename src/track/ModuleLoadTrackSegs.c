#include "global.h"
#include "variables.h"

extern const struct TrackSeg *gModule_TrackSegTables[];

void ModuleLoadTrackSegs(u32 trackId)
{
    gModule_TrackSegs = gModule_TrackSegTables[trackId];
    gUnk_0203B6F0 = 0x14;
}
