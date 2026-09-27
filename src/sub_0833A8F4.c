#include "global.h"
#include "gba/m4a_internal.h"
#include "functions.h"

/* m4aSongNumStartOrChange, high copy (EWRAM tables, high-engine callees). */

struct Unk0801DACC
{
    u32 unk0;
    u16 unk4;
};

struct Unk0801DA90
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern struct Unk0801DACC gUnk_0200CAA4[];
extern struct Unk0801DA90 gUnk_0200CA74[];


void sub_0833A8F4(u16 n)
{
    struct MusicPlayerInfo *info = (struct MusicPlayerInfo *)gUnk_0200CA74[gUnk_0200CAA4[n].unk4].unk0;

    if (info->songHeader != gUnk_0200CAA4[n].unk0)
        sub_0833AFC0((struct MusicPlayerInfo *)((u32)info),(struct SongHeader *)(gUnk_0200CAA4[n].unk0));
    else if ((info->status & MUSICPLAYER_STATUS_TRACK) == 0 || info->status & MUSICPLAYER_STATUS_PAUSE)
        sub_0833AFC0((struct MusicPlayerInfo *)((u32)info),(struct SongHeader *)((u32)info->songHeader));
}
