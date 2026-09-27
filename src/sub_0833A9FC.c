#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"





void sub_0833A9FC(void)
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
        sub_0833B074((struct MusicPlayerInfo *)(p->unk0));
        p++;
        n--;
        if (n != 0)
            goto loop;
    }
}
