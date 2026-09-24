#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xswee (high copy) */

void sub_0833BC64(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.pan_sweep = *track->cmdPtr;
    track->cmdPtr++;
}
