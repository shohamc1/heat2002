#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"
#include "variables.h"

void SoundMainRAM(void);
extern struct CgbChannel gCgbChans[];
extern u8 gMPlayMemAccArea[];
void SoundMain(void);

void MPlayFadeOut(struct MusicPlayerInfo *r0, u16 v)
{
    struct MusicPlayerInfo *r2 = r0;
    u32 t = r2->ident;
    u32 c = 0x80 << 1;

    if (t == 0x68736D53) {
        r2->fadeOC = v;
        r2->fadeOI = v;
        r2->fadeOV = c;
        /* Load-bearing: the dead store is eliminated but its use keeps t
         * alive across the branch, moving the tag pseudo from local-alloc
         * into global-alloc (v->r1, tag->r3, ptr->r2). */
        r2->ident = t;
    }
}

/* The cancelling offset preserves the initial base-to-p copy.
   Assigning off = 4 inside the loop keeps base + 4 out of the preheader. */
void m4aSoundInit(void)
{
#if PORTABLE
    struct MusicPlayerInfo *mplayInfo;
    uintptr_t tableBase;
#else
    u32 mplayInfo;
    u32 tableBase;
#endif
    struct MusicPlayer *playerEntry;
    u32 count;
    u32 entryOffset;
    u16 playerCount;
    u32 tracksOffset;

#if !PORTABLE
    CpuCopy32((u32)SoundMainRAM & ~1, IWRAM_START + 0x7000, 0x400);
#endif
    SoundInit(&gSoundInfo);
    MPlayExtender(gCgbChans);
    m4aSoundMode(0x0097EA00);
    playerCount = (u16)(u32)gNumMusicPlayersLow;
    if (playerCount != 0) {
        tableBase = ADDR_WORD(gMPlayTable);
        tracksOffset = playerCount;
        playerEntry = (struct MusicPlayer *)(tableBase + tracksOffset - playerCount);
        entryOffset = 0;
        count = playerCount;
    loop:
        tracksOffset = 4;
#if PORTABLE
        /* The GBA branch reads the row's tracks pointer at +4 (a 12-byte
           row: two pointers and a halfword); the host's struct MusicPlayer
           is pointer-wide, so the port reads it as the field it is. */
        (void)tracksOffset;
        (void)entryOffset;
        (void)tableBase;
        mplayInfo = playerEntry->info;
        MPlayOpen(mplayInfo, playerEntry->track, playerEntry->numTracks);
        mplayInfo->memAccArea = gMPlayMemAccArea;
#else
        mplayInfo = (u32)playerEntry->info;
        MPlayOpen((struct MusicPlayerInfo *)mplayInfo,
                  (struct MusicPlayerTrack *)(*(u32 *)(entryOffset + (tableBase + tracksOffset))),
                  playerEntry->numTracks);
        ((struct MusicPlayerInfo *)mplayInfo)->memAccArea = gMPlayMemAccArea;
#endif
        playerEntry++;
        entryOffset += 12;
        count--;
        if (count != 0)
            goto loop;
    }
}

void m4aSoundMain(void)
{ SoundMain(); }

void m4aSongNumStart(u16 idx)
{
    struct MusicPlayerInfo *v = gMPlayTable[gSongTable[idx].ms].info;
    MPlayStart(v, gSongTable[idx].header);
}
