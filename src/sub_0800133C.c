#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"





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
