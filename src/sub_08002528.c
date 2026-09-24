#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xatta */

void sub_08002528(u32 a0, struct MusicPlayerTrack *track)
{
    track->tone.attack = *track->cmdPtr;
    track->cmdPtr++;
}
