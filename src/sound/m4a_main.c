#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"

void SoundMainRAM(void);
extern struct SoundInfo gUnk_02000DE0;
extern struct CgbChannel gUnk_02001E20[];
extern u8 gUnk_02002020[];
void SoundMain(void);

void MPlayFadeOut(u32 r0, u16 v)
{
    u32 r2 = r0;
    u32 t = *(u32 *)(r2 + 0x34);
    u32 c = 0x80 << 1;

    if (t == 0x68736D53) {
        *(u16 *)(r2 + 0x26) = v;
        *(u16 *)(r2 + 0x24) = v;
        *(u16 *)(r2 + 0x28) = c;
        /* Load-bearing: the dead store is eliminated but its use keeps t
         * alive across the branch, moving the tag pseudo from local-alloc
         * into global-alloc (v->r1, tag->r3, ptr->r2). */
        *(u32 *)(r2 + 0x34) = t;
    }
}

/* The cancelling offset preserves the initial base-to-p copy.
   Assigning off = 4 inside the loop keeps base + 4 out of the preheader. */
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
    SoundInit(&gUnk_02000DE0);
    MPlayExtender(gUnk_02001E20);
    m4aSoundMode(0x0097EA00);
    playerCount = (u16)(u32)gNumMusicPlayersLow;
    if (playerCount != 0) {
        tableBase = (u32)gUnk_0801DA90;
        tracksOffset = playerCount;
        playerEntry = (struct Unk0801DA90 *)(tableBase + tracksOffset - playerCount);
        entryOffset = 0;
        count = playerCount;
    loop:
        tracksOffset = 4;
        mplayInfo = (u32)playerEntry->unk0;
        MPlayOpen((struct MusicPlayerInfo *)mplayInfo,
                  (struct MusicPlayerTrack *)(*(u32 *)(entryOffset + (tableBase + tracksOffset))),
                  (*(u8 *)&playerEntry->unk8));
        *(u32 *)(mplayInfo + 0x18) = (u32)gUnk_02002020;
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
    struct MusicPlayerInfo *v = gUnk_0801DA90[gUnk_0801DACC[idx].unk4].unk0;
    MPlayStart(v, gUnk_0801DACC[idx].unk0);
}
