#include "global.h"

extern u8 gNumMusicPlayersLow[];

struct Unk0801DA90
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern struct Unk0801DA90 gUnk_0801DA90[];

extern void sub_08001134(u32 a);

void sub_08001374(void)
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
        sub_08001134(p->unk0);
        p++;
        n--;
        if (n != 0)
            goto loop;
    }
}
