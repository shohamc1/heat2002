#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xtype */

void sub_08002514(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.type = *track->cmdPtr;
    track->cmdPtr++;
}
