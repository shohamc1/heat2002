#include "global.h"
#include "gba/m4a_internal.h"

/* m4aSongNumStartOrContinue (this revision passes info->songHeader to the
   restart, not song->header). */

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

extern struct Unk0801DACC gUnk_0801DACC[];
extern struct Unk0801DA90 gUnk_0801DA90[];

extern void sub_08001900(u32 a, u32 b);
extern void sub_08001134(u32 a);

void sub_08001280(u16 n)
{
    struct MusicPlayerInfo *info = (struct MusicPlayerInfo *)gUnk_0801DA90[gUnk_0801DACC[n].unk4].unk0;

    if (info->songHeader != gUnk_0801DACC[n].unk0)
        sub_08001900((u32)info, gUnk_0801DACC[n].unk0);
    else if ((info->status & MUSICPLAYER_STATUS_TRACK) == 0)
        sub_08001900((u32)info, (u32)info->songHeader);
    else if (info->status & MUSICPLAYER_STATUS_PAUSE)
        sub_08001134((u32)info);
}
