#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"

void SoundMain(void);

void m4aSoundMain(void)
{ SoundMain(); }

void m4aSongNumStart(u16 idx)
{
    struct MusicPlayerInfo *v = gUnk_0801DA90[gUnk_0801DACC[idx].unk4].unk0;
    MPlayStart(v, gUnk_0801DACC[idx].unk0);
}
