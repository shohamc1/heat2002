#include "global.h"
#include "gba/m4a_internal.h"
#include "functions.h"
#include "variables.h"
#if PORTABLE
#include <stddef.h>
#include "gba/compat.h"
#endif

/* MPlayOpen */
void MPlayMain(void);
/* MPlayStart */

void MPlayOpen(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *tracks, u32 trackCount)
{
    struct MusicPlayerInfo *playerInfo = mplayInfo;
    struct MusicPlayerTrack *track = tracks;
    u8 count = (u8)trackCount;
    struct SoundInfo *soundInfo;

    if (count == 0)
        return;
    if (count > 0x10)
        count = 16;
    soundInfo = gSoundInfoPtr[0];
    if (soundInfo->ident != ID_NUMBER)
        return;
    soundInfo->ident = soundInfo->ident + 1;
    Clear64byte(playerInfo);
#if PORTABLE
    /* Clear64byte zeroes through the track view's cmdPtr, which on the
       GBA covers the whole 0x40-byte player; the hosted player is wider,
       so zero the tail here (MPlayMainNext/musicPlayerNext would
       otherwise hold garbage the ident check would then trust). */
    CpuFill32(0,
              (u8 *)playerInfo + offsetof(struct MusicPlayerTrack, cmdPtr),
              sizeof(struct MusicPlayerInfo) - offsetof(struct MusicPlayerTrack, cmdPtr));
#if !PLATFORM_GBA
    /* The size above only makes sense while the track view's cmdPtr
       offset fits inside the player struct; keep it checked. */
    typedef char MPlayOpenClearCheck[offsetof(struct MusicPlayerTrack, cmdPtr) <= sizeof(struct MusicPlayerInfo) ? 1 : -1];
#endif
#endif
    playerInfo->tracks = track;
    playerInfo->trackCount = count;
    playerInfo->status = MUSICPLAYER_STATUS_PAUSE;
    while (count != 0) {
        track->flags = 0;
        count--;
        track++;
    }
    if (soundInfo->MPlayMainHead != NULL) {
        playerInfo->MPlayMainNext = soundInfo->MPlayMainHead;
        playerInfo->musicPlayerNext = soundInfo->musicPlayerHead;
        soundInfo->MPlayMainHead = NULL;
    }
    soundInfo->musicPlayerHead = playerInfo;
    soundInfo->MPlayMainHead = (MPlayMainFunc)MPlayMain;
    soundInfo->ident = ID_NUMBER;
    playerInfo->ident = ID_NUMBER;
}

void MPlayStart(struct MusicPlayerInfo *mplayInfo, struct SongHeader *songHeader)
{
    register struct MusicPlayerTrack *track PIN(r4);
    struct MusicPlayerInfo *playerInfo = mplayInfo;
    struct SongHeader *song = songHeader;
    s32 i;
    u32 trackIdx;
    u16 tempo;
    u32 partOffset;
#if PORTABLE
    register uintptr_t partPtr PIN(r0);
#else
    register u32 partPtr PIN(r0);
#endif

    if (playerInfo->ident != ID_NUMBER)
        return;
    playerInfo->ident = playerInfo->ident + 1;
    playerInfo->status = 0;
    playerInfo->songHeader = song;
    playerInfo->tone = song->tone;
    playerInfo->priority = song->priority;
    playerInfo->clock = 0;
    tempo = 0x96;
    playerInfo->tempoD = tempo;
    playerInfo->tempoI = tempo;
    tempo = tempo + 0x6A;
    playerInfo->tempoU = tempo;
    playerInfo->tempoC = 0;
    playerInfo->fadeOI = 0;
    i = 0;
    track = playerInfo->tracks;
    if (i < song->trackCount && i < playerInfo->trackCount) {
        trackIdx = i;
    loopA:
        TrackStop(playerInfo, track);
        track->flags = 0xC0;
#if PORTABLE
        /* The GBA stores the track index here and reads it back as a
           pointer whose bytes the BIOS-protected low page zeroes; the
           host cannot, so the port stores the NULL the engine means.
           The part walk below reads the header's pointer array through
           its struct member instead of +8/i*4 byte arithmetic. */
        track->chan = NULL;
        track->cmdPtr = song->part[i];
#else
        track->chan = (struct SoundChannel *)trackIdx;
        partOffset = i * 4;
        partPtr = ADDR_WORD(song);
        partPtr = partPtr + 8;
        partPtr = partPtr + partOffset;
        track->cmdPtr = *(u8 **)partPtr;
#endif
        i++;
#if PORTABLE
        track++;
#else
        track = (struct MusicPlayerTrack *)((u8 *)track + 0x50);
#endif
        if (i < song->trackCount && i < playerInfo->trackCount)
            goto loopA;
    }
    if (i < playerInfo->trackCount) {
        trackIdx = 0;
    loopB:
        TrackStop(playerInfo, track);
        track->flags = trackIdx;
        i++;
#if PORTABLE
        track++;
#else
        track = (struct MusicPlayerTrack *)((u8 *)track + 0x50);
#endif
        if (i < playerInfo->trackCount)
            goto loopB;
    }
    if (song->reverb & 0x80)
        m4aSoundMode(song->reverb);
    playerInfo->ident = ID_NUMBER;
}

void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo)
{
    struct MusicPlayerInfo *playerInfo = mplayInfo;
    s32 remaining;
    struct MusicPlayerTrack *track;

    if (playerInfo->ident != ID_NUMBER)
        return;
    playerInfo->ident = playerInfo->ident + 1;
    playerInfo->status = playerInfo->status | MUSICPLAYER_STATUS_PAUSE;
    remaining = playerInfo->trackCount;
    track = playerInfo->tracks;
    while (remaining > 0) {
        TrackStop(playerInfo, track);
        remaining--;
#if PORTABLE
        track++;
#else
        track = (struct MusicPlayerTrack *)((u8 *)track + 0x50);
#endif
    }
    playerInfo->ident = ID_NUMBER;
}
