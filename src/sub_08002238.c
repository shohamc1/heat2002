#include "global.h"
#include "gba/m4a_internal.h"

/* ClearModM */

void sub_08002238(struct MusicPlayerTrack *track)
{
    track->lfoSpeedC = 0;
    track->modM = 0;

    if (track->modT == 0)
        track->flags = MPT_FLG_PITCHG | track->flags;
    else
        track->flags = MPT_FLG_VOLCHG | track->flags;
}
