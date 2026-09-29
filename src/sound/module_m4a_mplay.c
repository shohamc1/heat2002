#include "global.h"
#include "gba/m4a_internal.h"
#include "variables.h"
#include "functions.h"

/* MPlayOpen (high copy) */
void ModuleClear64byte(void *r0);
void sub_0833A228(void);
/* MPlayStart (high copy) */
void sub_0833A488(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
/* m4aMPlayStop (high copy) */

void ModuleMPlayOpen(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *tracks, u32 trackCount)
{
    struct MusicPlayerInfo *playerInfo = mplayInfo;
    struct MusicPlayerTrack *track = tracks;
    u8 count = (u8)trackCount;
    struct SoundInfo *soundInfo;

    if (count == 0)
        return;
    if (count > 0x10)
        count = 0x10;
    soundInfo = gSoundInfoPtr[0];
    if (soundInfo->ident != ID_NUMBER)
        return;
    soundInfo->ident = soundInfo->ident + 1;
    ModuleClear64byte(playerInfo);
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
    soundInfo->MPlayMainHead = (MPlayMainFunc)sub_0833A228;
    soundInfo->ident = ID_NUMBER;
    playerInfo->ident = ID_NUMBER;
}

void ModuleMPlayStart(struct MusicPlayerInfo *mplayInfo, struct SongHeader *songHeader)
{
    register struct MusicPlayerTrack *track asm("r4");
    struct MusicPlayerInfo *playerInfo = mplayInfo;
    struct SongHeader *song = songHeader;
    s32 i;
    u32 trackIdx;
    u16 tempo;
    u32 partOffset;
    register u32 partPtr asm("r0");

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
        sub_0833A488(playerInfo, track);
        track->flags = 0xC0;
        track->chan = (struct SoundChannel *)trackIdx;
        partOffset = i * 4;
        partPtr = (u32)song;
        partPtr = partPtr + 8;
        partPtr = partPtr + partOffset;
        track->cmdPtr = *(u8 **)partPtr;
        i++;
        track = (struct MusicPlayerTrack *)((u8 *)track + 0x50);
        if (i < song->trackCount && i < playerInfo->trackCount)
            goto loopA;
    }
    if (i < playerInfo->trackCount) {
        trackIdx = 0;
    loopB:
        sub_0833A488(playerInfo, track);
        track->flags = trackIdx;
        i++;
        track = (struct MusicPlayerTrack *)((u8 *)track + 0x50);
        if (i < playerInfo->trackCount)
            goto loopB;
    }
    if (song->reverb & 0x80)
        ModuleM4aSoundMode(song->reverb);
    playerInfo->ident = ID_NUMBER;
}

void ModuleM4aMPlayStop(struct MusicPlayerInfo *mplayInfo)
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
        sub_0833A488(playerInfo, track);
        remaining--;
        track = (struct MusicPlayerTrack *)((u8 *)track + 0x50);
    }
    playerInfo->ident = ID_NUMBER;
}
