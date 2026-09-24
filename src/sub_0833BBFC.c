#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xdeca (high copy) */

void sub_0833BBFC(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.decay = *track->cmdPtr;
    track->cmdPtr++;
}
