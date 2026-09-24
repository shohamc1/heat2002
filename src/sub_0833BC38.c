#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xiecv (high copy) */

void sub_0833BC38(u32 a0, struct MusicPlayerTrack *track)
{
    track->pseudoEchoVolume = *track->cmdPtr;
    track->cmdPtr++;
}
