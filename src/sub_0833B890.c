#include "global.h"
#include "gba/m4a_internal.h"

/* m4aMPlayPanpotControl */

void sub_0833B890(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u8 pan)
{
    struct MusicPlayerTrack *track;
    u32 bit;
    s32 i;

    if (mplayInfo->ident != ID_NUMBER)
        return;
    mplayInfo->ident = mplayInfo->ident + 1;
    for (i = mplayInfo->trackCount, track = mplayInfo->tracks, bit = 1; i > 0; i--, track++, bit = bit << 1) {
        if ((trackBits & bit) != 0 && (track->flags & MPT_FLG_EXIST) != 0) {
            track->panX = pan;
            track->flags = track->flags | MPT_FLG_VOLCHG;
        }
    }
    mplayInfo->ident = ID_NUMBER;
}
