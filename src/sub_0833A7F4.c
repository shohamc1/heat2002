#include "global.h"
#include "gba/m4a_internal.h"

/* MPlayContinue (high copy).
   The ident write-back at the end is a dead store, but its use keeps the
   tag pseudo alive across the branch (tag->r3, ptr->r2), like sub_08001150
   and sub_080020CC. */

void sub_0833A7F4(struct MusicPlayerInfo *mplayInfo)
{
    u32 ident = mplayInfo->ident;

    if (ident == ID_NUMBER)
    {
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
        mplayInfo->ident = ident;
    }
}
