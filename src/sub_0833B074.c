#include "global.h"
#include "gba/m4a_internal.h"

/* m4aMPlayStop (high copy) */

void sub_0833A488(struct MusicPlayerInfo *, struct MusicPlayerTrack *);

void sub_0833B074(struct MusicPlayerInfo *mplayInfo)
{
    struct MusicPlayerInfo *r6 = mplayInfo;
    s32 r4;
    struct MusicPlayerTrack *r5;

    if (r6->ident != ID_NUMBER)
        return;
    r6->ident = r6->ident + 1;
    r6->status = r6->status | MUSICPLAYER_STATUS_PAUSE;
    r4 = r6->trackCount;
    r5 = r6->tracks;
    while (r4 > 0)
    {
        sub_0833A488(r6, r5);
        r4--;
        r5 = (struct MusicPlayerTrack *)((u8 *)r5 + 0x50);
    }
    r6->ident = ID_NUMBER;
}
