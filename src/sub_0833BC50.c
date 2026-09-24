#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xleng (high copy) */

void sub_0833BC50(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.length = *track->cmdPtr;
    track->cmdPtr++;
}
