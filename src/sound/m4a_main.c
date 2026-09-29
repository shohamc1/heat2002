#include "global.h"
void SoundMain(void);
#include "functions.h"
#include "m4a.h"
#include "data.h"

void m4aSoundMain(void)
{ SoundMain(); }

void m4aSongNumStart(u16 idx)
{
    u32 v = gUnk_0801DA90[gUnk_0801DACC[idx].unk4].unk0;
    MPlayStart((struct MusicPlayerInfo *)v, (struct SongHeader *)(gUnk_0801DACC[idx].unk0));
}
