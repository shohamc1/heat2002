#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "structs.h"

#define GBA_CPUSET sub_08344B64
/* The cancelling offset preserves the initial base-to-p copy.
   Assigning off = 4 inside the loop keeps base + 4 out of the preheader. */
void sub_08339C0C(void);
void sub_08339B88(void);

void ModuleMPlayFadeOut(u32 mplayInfo, u16 fadeOutDelay)
{
    u32 info = mplayInfo;
    u32 ident = ((struct MusicPlayerInfo *)info)->ident;
    u32 initialFadeVol = 0x80 << 1;

    if (ident == 0x68736D53) {
        ((struct MusicPlayerInfo *)info)->fadeOC = fadeOutDelay;
        ((struct MusicPlayerInfo *)info)->fadeOI = fadeOutDelay;
        ((struct MusicPlayerInfo *)info)->fadeOV = initialFadeVol;
        /* Load-bearing: the dead store is eliminated but its use keeps t
         * alive across the branch, moving the tag pseudo from local-alloc
         * into global-alloc (v->r1, tag->r3, ptr->r2). */
        ((struct MusicPlayerInfo *)info)->ident = ident;
    }
}

void ModuleM4aSoundInit(void)
{
    u32 mplayInfo;
    struct MusicPlayer *playerEntry;
    u32 count;
    u32 entryOffset;
    u32 tableBase;
    u16 playerCount;
    u32 tracksOffset;

    CpuCopy32((u32)sub_08339C0C & ~1, IWRAM_START + 0x7000, 0x400);
    ModuleSoundInit((void *)EWRAM_START + 0x37E30);
    ModuleMPlayExtender((void *)EWRAM_START + 0x38E70);
    ModuleM4aSoundMode(0x0097D800);
    playerCount = (u16)(u32)gNumMusicPlayersHigh;
    if (playerCount != 0) {
        tableBase = (u32)gModule_MPlayTable;
        tracksOffset = playerCount;
        playerEntry = (struct MusicPlayer *)(tableBase + tracksOffset - playerCount);
        entryOffset = 0;
        count = playerCount;
    loop:
        tracksOffset = 4;
        mplayInfo = (u32)playerEntry->info;
        ModuleMPlayOpen((struct MusicPlayerInfo *)mplayInfo,
                        (struct MusicPlayerTrack *)(*(u32 *)(entryOffset + (tableBase + tracksOffset))),
                        playerEntry->numTracks);
        ((struct MusicPlayerInfo *)mplayInfo)->memAccArea = (u8 *)(EWRAM_START + 0x39030);
        playerEntry++;
        entryOffset += 12;
        count--;
        if (count != 0)
            goto loop;
    }
}

void ModuleM4aSoundMain(void)
{ sub_08339B88(); }

void ModuleM4aSongNumStart(u16 idx)
{
    struct MusicPlayerInfo *mplayInfo = gModule_MPlayTable[gModule_SongTable[idx].ms].info;
    ModuleMPlayStart(mplayInfo, gModule_SongTable[idx].header);
}
