#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"

/* The cancelling offset preserves the initial base-to-p copy.
   Assigning off = 4 inside the loop keeps base + 4 out of the preheader. */

void SoundMainRAM(void);
extern u8 gUnk_02000DE0[];
extern u8 gUnk_02001E20[];
extern u8 gUnk_02002020[];



void m4aSoundInit(void)
{
    u32 mplayInfo;
    struct Unk0801DA90 *playerEntry;
    u32 count;
    u32 entryOffset;
    u32 tableBase;
    u16 playerCount;
    u32 tracksOffset;

    CpuCopy32((u32)SoundMainRAM & ~1, IWRAM_START + 0x7000, 0x400);
    SoundInit((struct SoundInfo *)gUnk_02000DE0);
    MPlayExtender((struct CgbChannel *)gUnk_02001E20);
    m4aSoundMode(0x0097EA00);
    playerCount = (u16)(u32)gNumMusicPlayersLow;
    if (playerCount != 0)
    {
        tableBase = (u32)gUnk_0801DA90;
        tracksOffset = playerCount;
        playerEntry = (struct Unk0801DA90 *)(tableBase + tracksOffset - playerCount);
        entryOffset = 0;
        count = playerCount;
    loop:
        tracksOffset = 4;
        mplayInfo = playerEntry->unk0;
        MPlayOpen((struct MusicPlayerInfo *)mplayInfo,(struct MusicPlayerTrack *)(*(u32 *)(entryOffset + (tableBase + tracksOffset))), (*(u8 *)&playerEntry->unk8));
        *(u32 *)(mplayInfo + 0x18) = (u32)gUnk_02002020;
        playerEntry++;
        entryOffset += 12;
        count--;
        if (count != 0)
            goto loop;
    }
}
