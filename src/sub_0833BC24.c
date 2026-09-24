#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xrele (high copy) */

void sub_0833BC24(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.release = *track->cmdPtr;
    track->cmdPtr++;
}
