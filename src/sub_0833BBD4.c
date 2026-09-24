#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xtype (high copy) */

void sub_0833BBD4(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.type = *track->cmdPtr;
    track->cmdPtr++;
}
