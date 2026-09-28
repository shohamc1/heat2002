#include "global.h"
void SoundMain(void);
#include "functions.h"
#include "data.h"

void m4aSoundMain(void)
{
    SoundMain();
}

void m4aSongNumStart(u16 idx)
{
    u32 v = gUnk_0801DA90[gUnk_0801DACC[idx].unk4].unk0;
    sub_08001900((struct MusicPlayerInfo *)v,(struct SongHeader *)(gUnk_0801DACC[idx].unk0));
}
