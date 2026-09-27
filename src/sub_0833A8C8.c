#include "global.h"
#include "functions.h"
#include "variables.h"
void sub_0833A8C8(u16 idx)
{
    u32 v = gModule_MPlayTable[gModule_SongTable[idx].unk4].unk0;
    sub_0833AFC0((struct MusicPlayerInfo *)v,(struct SongHeader *)(gModule_SongTable[idx].unk0));
}
