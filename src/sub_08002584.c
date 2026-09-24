#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xiecl */

void sub_08002584(u32 a0, struct MusicPlayerTrack *track)
{
    track->pseudoEchoLength = *track->cmdPtr;
    track->cmdPtr++;
}
