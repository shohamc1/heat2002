#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xatta (high copy) */

void sub_0833BBE8(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.attack = *track->cmdPtr;
    track->cmdPtr++;
}
