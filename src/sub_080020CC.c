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
