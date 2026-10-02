#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"

void m4aSongNumStop(u16 a)
{
    const struct MusicPlayer *pa = gMPlayTable;
    const struct Song *baseB = gSongTable;
    const struct Song *pb = baseB + a;

    if (*(struct SongHeader **)pa[pb->ms].info == pb->header)
        m4aMPlayStop(pa[pb->ms].info);
}

void m4aSongNumContinue(u16 a)
{
    const struct MusicPlayer *pa = gMPlayTable;
    const struct Song *baseB = gSongTable;
    const struct Song *pb = baseB + a;

    if (*(struct SongHeader **)pa[pb->ms].info == pb->header)
        sub_08001134(pa[pb->ms].info);
}
