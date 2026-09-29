#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"

void m4aSongNumStop(u16 a)
{
    const struct MusicPlayer *pa = gMPlayTable;
    const struct Song *baseB = gSongTable;
    const struct Song *pb = baseB + a;

    if (*(u32 *)pa[pb->ms].info == (u32)pb->header)
        m4aMPlayStop(pa[pb->ms].info);
}

void m4aSongNumContinue(u16 a)
{
    const struct MusicPlayer *pa = gMPlayTable;
    const struct Song *baseB = gSongTable;
    const struct Song *pb = baseB + a;

    if (*(u32 *)pa[pb->ms].info == (u32)pb->header)
        sub_08001134(pa[pb->ms].info);
}
