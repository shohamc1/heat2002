#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xswee */

void sub_080025A4(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.pan_sweep = *track->cmdPtr;
    track->cmdPtr++;
}
