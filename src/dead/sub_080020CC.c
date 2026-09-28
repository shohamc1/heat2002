#include "global.h"
#include "gba/m4a_internal.h"

/* m4aMPlayTempoControl */

void sub_080020CC(struct MusicPlayerInfo *mplayInfo, u16 tempo)
{
    u32 ident = mplayInfo->ident;

    if (ident == ID_NUMBER)
    {
        mplayInfo->tempoU = tempo;
        mplayInfo->tempoI = (mplayInfo->tempoD * mplayInfo->tempoU) >> 8;
        mplayInfo->ident = ident;
    }
}

/* m4aMPlayVolumeControl */

void sub_080020F4(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u16 volume)
{
    struct MusicPlayerTrack *track;
    u32 bit;
    s32 i;

    if (mplayInfo->ident != ID_NUMBER)
        return;
    mplayInfo->ident = mplayInfo->ident + 1;
    for (i = mplayInfo->trackCount, track = mplayInfo->tracks, bit = 1; i > 0; i--, track++, bit = bit << 1) {
        if ((trackBits & bit) != 0 && (track->flags & MPT_FLG_EXIST) != 0) {
            track->volX = volume / 4;
            track->flags = track->flags | MPT_FLG_VOLCHG;
        }
    }
    mplayInfo->ident = ID_NUMBER;
}
