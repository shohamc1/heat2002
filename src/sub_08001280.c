#include "global.h"
#include "gba/m4a_internal.h"
#include "functions.h"
#include "data.h"

/* m4aSongNumStartOrContinue (this revision passes info->songHeader to the
   restart, not song->header). */





void sub_08001280(u16 n)
{
    struct MusicPlayerInfo *info = (struct MusicPlayerInfo *)gUnk_0801DA90[gUnk_0801DACC[n].unk4].unk0;

    if (info->songHeader != gUnk_0801DACC[n].unk0)
        sub_08001900((struct MusicPlayerInfo *)((u32)info),(struct SongHeader *)(gUnk_0801DACC[n].unk0));
    else if ((info->status & MUSICPLAYER_STATUS_TRACK) == 0)
        sub_08001900((struct MusicPlayerInfo *)((u32)info),(struct SongHeader *)((u32)info->songHeader));
    else if (info->status & MUSICPLAYER_STATUS_PAUSE)
        sub_08001134(info);
}
