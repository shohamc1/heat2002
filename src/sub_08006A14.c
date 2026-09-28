#include "global.h"
#include "variables.h"
#include "data.h"


void sub_08006A14(u32 arg0)
{
    (*(u32 *)&gTrackSegs) = (u32)gTrackSegTables[arg0];
    gDefaultCountdownSeconds = 0x14;
}
