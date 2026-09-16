#include "global.h"
#include "gba/m4a_internal.h"

/* MPlayStart */

void sub_08000DC8(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void sub_080016E4(u32);

void sub_08001900(struct MusicPlayerInfo *mplayInfo, struct SongHeader *songHeader)
{
    register struct MusicPlayerTrack *track asm("r4");
    struct MusicPlayerInfo *r5 = mplayInfo;
    struct SongHeader *r7 = songHeader;
    s32 r6;
    u32 r8;
    u16 v;
    u32 t;
    register u32 u asm("r0");

    if (r5->ident != ID_NUMBER)
        return;
    r5->ident = r5->ident + 1;
    r5->status = 0;
    r5->songHeader = r7;
    r5->tone = r7->tone;
    r5->priority = r7->priority;
    r5->clock = 0;
    v = 0x96;
    r5->tempoD = v;
    r5->tempoI = v;
    v = v + 0x6A;
    r5->tempoU = v;
    r5->tempoC = 0;
    r5->fadeOI = 0;
    r6 = 0;
    track = r5->tracks;
    if (r6 < r7->trackCount && r6 < r5->trackCount) {
        r8 = r6;
loopA:
        sub_08000DC8(r5, track);
        track->flags = 0xC0;
        track->chan = (struct SoundChannel *)r8;
        t = r6 * 4;
        u = (u32)r7;
        u = u + 8;
        u = u + t;
        track->cmdPtr = *(u8 **)u;
        r6++;
        track = (struct MusicPlayerTrack *)((u8 *)track + 0x50);
        if (r6 < r7->trackCount && r6 < r5->trackCount)
            goto loopA;
    }
    if (r6 < r5->trackCount) {
        r8 = 0;
loopB:
        sub_08000DC8(r5, track);
        track->flags = r8;
        r6++;
        track = (struct MusicPlayerTrack *)((u8 *)track + 0x50);
        if (r6 < r5->trackCount)
            goto loopB;
    }
    if (r7->reverb & 0x80)
        sub_080016E4(r7->reverb);
    r5->ident = ID_NUMBER;
}
