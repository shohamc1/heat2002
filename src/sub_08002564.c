#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xrele */

void sub_08002564(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.release = *track->cmdPtr;
    track->cmdPtr++;
}
