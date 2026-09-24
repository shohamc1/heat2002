#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xleng */

void sub_08002590(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.length = *track->cmdPtr;
    track->cmdPtr++;
}
