#include "global.h"
#include "gba/m4a_internal.h"

/* MPlayOpen (high copy) */

extern u32 gUnk_03007FF0[];

void sub_0833ABF4(u32 r0);

void sub_0833AF48(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *tracks, u32 r2)
{
    struct MusicPlayerInfo *r7 = mplayInfo;
    struct MusicPlayerTrack *r6 = tracks;
    u8 r4 = (u8)r2;
    struct SoundInfo *soundInfo;

    if (r4 == 0)
        return;
    if (r4 > 0x10)
        r4 = 0x10;
    soundInfo = (struct SoundInfo *)gUnk_03007FF0[0];
    if (soundInfo->ident != ID_NUMBER)
        return;
    soundInfo->ident = soundInfo->ident + 1;
    sub_0833ABF4((u32)r7);
    r7->tracks = r6;
    r7->trackCount = r4;
    r7->status = MUSICPLAYER_STATUS_PAUSE;
    while (r4 != 0)
    {
        r6->flags = 0;
        r4--;
        r6++;
    }
    if (soundInfo->MPlayMainHead != NULL)
    {
        r7->MPlayMainNext = soundInfo->MPlayMainHead;
        r7->musicPlayerNext = soundInfo->musicPlayerHead;
        soundInfo->MPlayMainHead = NULL;
    }
    soundInfo->musicPlayerHead = r7;
    soundInfo->MPlayMainHead = (MPlayMainFunc)0x020017A9;
    soundInfo->ident = ID_NUMBER;
    r7->ident = ID_NUMBER;
}
