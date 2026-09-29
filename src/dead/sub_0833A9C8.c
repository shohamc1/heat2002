#include "global.h"
#include "functions.h"
#include "variables.h"
#include "m4a.h"

struct Unk12A
{
    u32 ptr;
    u32 pad[2];
};

struct Unk8B
{
    u32 field0;
    u16 idx;
    u16 pad;
};



void sub_0833A9C8(u16 a)
{
    struct Unk12A *pa = (struct Unk12A *)gModule_MPlayTable;
    struct Unk8B *baseB = (struct Unk8B *)gModule_SongTable;
    struct Unk8B *pb = baseB + a;

    if (*(u32 *)pa[pb->idx].ptr == pb->field0)
        sub_0833A7F4((struct MusicPlayerInfo *)((u32)pa[pb->idx].ptr));
}

void sub_0833A9FC(void)
{
    u16 cnt;
    u32 n;
    struct MusicPlayer *p;

    cnt = (u16)(u32)gNumMusicPlayersHigh;
    if (cnt != 0)
    {
        p = gModule_MPlayTable;
        n = cnt;
    loop:
        ModuleM4aMPlayStop((struct MusicPlayerInfo *)(p->info));
        p++;
        n--;
        if (n != 0)
            goto loop;
    }
}

void sub_0833AA28(void)
{
    /* sub_0833A7F4: the ROM call passes no argument; the matched definition takes one; call
       through a function pointer with the old prototype. */
    ((void (*)(void))sub_0833A7F4)();
}

void sub_0833AA34(void)
{
    u16 cnt;
    u32 n;
    struct MusicPlayer *p;

    cnt = (u16)(u32)gNumMusicPlayersHigh;
    if (cnt != 0)
    {
        p = gModule_MPlayTable;
        n = cnt;
    loop:
        sub_0833A7F4((struct MusicPlayerInfo *)(p->info));
        p++;
        n--;
        if (n != 0)
            goto loop;
    }
}
