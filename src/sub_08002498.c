#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xcmd */

extern MPlayFunc gUnk_0801D230[];

void sub_08002498(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 n = *track->cmdPtr;
    track->cmdPtr++;

    gUnk_0801D230[n](mplayInfo, track);
}
