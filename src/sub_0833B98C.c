#include "global.h"
#include "gba/m4a_internal.h"

void sub_0833B8F8(struct MusicPlayerTrack *track);

/* m4aMPlayLFOSpeedSet (high copy) */

void sub_0833B98C(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u8 lfoSpeed)
{
    struct MusicPlayerTrack *track;
    u32 bit;
    s32 i;

    if (mplayInfo->ident != ID_NUMBER)
        return;
    mplayInfo->ident = mplayInfo->ident + 1;
    for (i = mplayInfo->trackCount, track = mplayInfo->tracks, bit = 1; i > 0; i--, track++, bit = bit << 1) {
        if ((trackBits & bit) != 0 && (track->flags & MPT_FLG_EXIST) != 0) {
            track->lfoSpeed = lfoSpeed;

            if (!track->lfoSpeed)
                sub_0833B8F8(track);
        }
    }
    mplayInfo->ident = ID_NUMBER;
}
