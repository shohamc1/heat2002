#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xsust */

void sub_08002550(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.sustain = *track->cmdPtr;
    track->cmdPtr++;
}
