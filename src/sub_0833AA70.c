#include "global.h"
#include "gba/m4a_internal.h"

/* Track immediate-reinit, high copy (ClearChain -> sub_0833ABF4). */

void sub_0833ABF4(void *a);

void sub_0833AA70(struct MusicPlayerInfo *mplayInfo)
{
    s32 trackCount = mplayInfo->trackCount;
    struct MusicPlayerTrack *track = mplayInfo->tracks;

    while (trackCount > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            if (track->flags & MPT_FLG_START)
            {
                sub_0833ABF4(track);
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
