#include "global.h"
#include "gba/m4a_internal.h"

/* m4aMPlayPitchControl (high copy) */

void sub_0833B81C(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u16 pitch)
{
    struct MusicPlayerTrack *track;
    u32 bit;
    s32 i;

    if (mplayInfo->ident != ID_NUMBER)
        return;
    mplayInfo->ident = mplayInfo->ident + 1;
    for (i = mplayInfo->trackCount, track = mplayInfo->tracks, bit = 1; i > 0; i--, track++, bit = bit << 1) {
        if ((trackBits & bit) != 0 && (track->flags & MPT_FLG_EXIST) != 0) {
            track->keyShiftX = (s16)pitch >> 8;
            track->pitX = pitch;
            track->flags = track->flags | MPT_FLG_PITCHG;
        }
    }
    mplayInfo->ident = ID_NUMBER;
}
