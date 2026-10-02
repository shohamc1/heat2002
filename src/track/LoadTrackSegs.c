#include "global.h"
#include "functions.h"
#include "variables.h"
#include "data.h"

void LoadTrackSegs(u32 trackId)
{
    gTrackSegs = gTrackSegTables[trackId];
    gDefaultCountdownSeconds = 20;
}
