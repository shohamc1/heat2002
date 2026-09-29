#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"

void sub_0800133C(void)
{
    u16 cnt;
    u32 n;
    struct MusicPlayer *p;

    cnt = (u16)(u32)gNumMusicPlayersLow;
    if (cnt != 0)
    {
        p = gMPlayTable;
        n = cnt;
    loop:
        m4aMPlayStop((struct MusicPlayerInfo *)(p->info));
        p++;
        n--;
        if (n != 0)
            goto loop;
    }
}

void m4aMPlayContinue(void)
{
    /* sub_08001134: the ROM call passes no argument; the matched definition takes one; call
       through a function pointer with the old prototype. */
    ((void (*)(void))sub_08001134)();
}

void sub_08001374(void)
{
    u16 cnt;
    u32 n;
    struct MusicPlayer *p;

    cnt = (u16)(u32)gNumMusicPlayersLow;
    if (cnt != 0)
    {
        p = gMPlayTable;
        n = cnt;
    loop:
        sub_08001134((struct MusicPlayerInfo *)(p->info));
        p++;
        n--;
        if (n != 0)
            goto loop;
    }
}
