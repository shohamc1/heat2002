#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xsust (high copy) */

void sub_0833BC10(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.sustain = *track->cmdPtr;
    track->cmdPtr++;
}
