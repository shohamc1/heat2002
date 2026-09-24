#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xiecv */

void sub_08002578(u32 a0, struct MusicPlayerTrack *track)
{
    track->pseudoEchoVolume = *track->cmdPtr;
    track->cmdPtr++;
}
