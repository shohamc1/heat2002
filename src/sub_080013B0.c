#include "global.h"
#include "gba/m4a_internal.h"

/* Track immediate-reinit (m4aMPlayImmInit, older revision: ClearChain(track),
   bendRange=2, volX=0x40, lfoSpeed=0x16, tone.type=1). */

void sub_08001534(void *a);

void sub_080013B0(struct MusicPlayerInfo *mplayInfo)
{
    s32 trackCount = mplayInfo->trackCount;
    struct MusicPlayerTrack *track = mplayInfo->tracks;

    while (trackCount > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            if (track->flags & MPT_FLG_START)
            {
                sub_08001534(track);
                track->flags = MPT_FLG_EXIST;
                track->bendRange = 2;
                track->volX = 0x40;
                track->lfoSpeed = 0x16;
                track->tone.type = 1;
            }
        }
        trackCount--;
        track++;
    }
}
