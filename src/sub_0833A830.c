#include "global.h"
#define GBA_CPUSET sub_08344B64
#include "gba/compat.h"
#include "functions.h"
#include "m4a.h"

/* The cancelling offset preserves the initial base-to-p copy.
   Assigning off = 4 inside the loop keeps base + 4 out of the preheader. */

struct Unk0801DA90
{
    u32 unk0;
    u32 unk4;
    u8 unk8;
    u8 filler9[3];
};

extern struct Unk0801DA90 gUnk_0200CA74[];

void sub_08339C0C(void);

void sub_0833A830(void)
{
    u32 x;
    struct Unk0801DA90 *p;
    u32 n;
    u32 i;
    u32 base;
    u16 cnt;
    u32 off;

    CpuCopy32((u32)sub_08339C0C & ~1, IWRAM_START + 0x7000, 0x400);
    sub_0833AC08((void *)EWRAM_START + 0x37E30);
    sub_0833AAB8((void *)EWRAM_START + 0x38E70);
    sub_0833ADA4(0x0097D800);
    cnt = (u16)(u32)gNumMusicPlayersHigh;
    if (cnt != 0)
    {
        base = (u32)gUnk_0200CA74;
        off = cnt;
        p = (struct Unk0801DA90 *)(base + off - cnt);
        i = 0;
        n = cnt;
    loop:
        off = 4;
        x = p->unk0;
        sub_0833AF48((struct MusicPlayerInfo *)x,(struct MusicPlayerTrack *)(*(u32 *)(i + (base + off))), p->unk8);
        *(u32 *)(x + 0x18) = EWRAM_START + 0x39030;
        p++;
        i += 12;
        n--;
        if (n != 0)
            goto loop;
    }
}
