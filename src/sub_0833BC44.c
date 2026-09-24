#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xiecl (high copy) */

void sub_0833BC44(u32 a0, struct MusicPlayerTrack *track)
{
    track->pseudoEchoLength = *track->cmdPtr;
    track->cmdPtr++;
}
