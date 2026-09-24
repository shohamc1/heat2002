#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xdeca */

void sub_0800253C(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.decay = *track->cmdPtr;
    track->cmdPtr++;
}
