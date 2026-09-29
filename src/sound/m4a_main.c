#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"

void SoundMainRAM(void);
extern struct SoundInfo gSoundInfo;
extern struct CgbChannel gCgbChans[];
extern u8 gMPlayMemAccArea[];
void SoundMain(void);

void MPlayFadeOut(u32 r0, u16 v)
{
    u32 r2 = r0;
    u32 t = ((struct MusicPlayerInfo *)r2)->ident;
    u32 c = 0x80 << 1;

    if (t == 0x68736D53) {
        ((struct MusicPlayerInfo *)r2)->fadeOC = v;
        ((struct MusicPlayerInfo *)r2)->fadeOI = v;
        ((struct MusicPlayerInfo *)r2)->fadeOV = c;
        /* Load-bearing: the dead store is eliminated but its use keeps t
         * alive across the branch, moving the tag pseudo from local-alloc
         * into global-alloc (v->r1, tag->r3, ptr->r2). */
        ((struct MusicPlayerInfo *)r2)->ident = t;
    }
}

/* The cancelling offset preserves the initial base-to-p copy.
   Assigning off = 4 inside the loop keeps base + 4 out of the preheader. */
void m4aSoundInit(void)
{
    u32 mplayInfo;
    struct MusicPlayer *playerEntry;
    u32 count;
    u32 entryOffset;
    u32 tableBase;
    u16 playerCount;
    u32 tracksOffset;

    CpuCopy32((u32)SoundMainRAM & ~1, IWRAM_START + 0x7000, 0x400);
    SoundInit(&gSoundInfo);
    MPlayExtender(gCgbChans);
    m4aSoundMode(0x0097EA00);
    playerCount = (u16)(u32)gNumMusicPlayersLow;
    if (playerCount != 0) {
        tableBase = (u32)gMPlayTable;
        tracksOffset = playerCount;
        playerEntry = (struct MusicPlayer *)(tableBase + tracksOffset - playerCount);
        entryOffset = 0;
        count = playerCount;
    loop:
        tracksOffset = 4;
        mplayInfo = (u32)playerEntry->info;
        MPlayOpen((struct MusicPlayerInfo *)mplayInfo,
                  (struct MusicPlayerTrack *)(*(u32 *)(entryOffset + (tableBase + tracksOffset))),
                  playerEntry->numTracks);
        ((struct MusicPlayerInfo *)mplayInfo)->memAccArea = gMPlayMemAccArea;
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
