#include "global.h"
#include "functions.h"
#include "m4a.h"


struct Unk0801DA90
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern struct Unk0801DA90 gUnk_0801DA90[];


void sub_0800133C(void)
{
    u16 cnt;
    u32 n;
    struct Unk0801DA90 *p;

    cnt = (u16)(u32)gNumMusicPlayersLow;
    if (cnt != 0)
    {
        p = gUnk_0801DA90;
        n = cnt;
    loop:
        sub_080019B4((struct MusicPlayerInfo *)(p->unk0));
        p++;
        n--;
        if (n != 0)
            goto loop;
    }
}
