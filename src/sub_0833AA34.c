#include "global.h"

extern u8 gNumMusicPlayersHigh[];

struct Unk0801DA90
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern struct Unk0801DA90 gUnk_0200CA74[];

extern void sub_0833A7F4(struct MusicPlayerInfo *mplayInfo);

void sub_0833AA34(void)
{
    u16 cnt;
    u32 n;
    struct Unk0801DA90 *p;

    cnt = (u16)(u32)gNumMusicPlayersHigh;
    if (cnt != 0)
    {
        p = gUnk_0200CA74;
        n = cnt;
    loop:
        sub_0833A7F4(p->unk0);
        p++;
        n--;
        if (n != 0)
            goto loop;
    }
}
