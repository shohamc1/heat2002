#include "global.h"
#include "functions.h"
#include "variables.h"
void sub_0833A8C8(u16 idx)
{
    u32 v = gUnk_0200CA74[gUnk_0200CAA4[idx].unk4].unk0;
    sub_0833AFC0((struct MusicPlayerInfo *)v,(struct SongHeader *)(gUnk_0200CAA4[idx].unk0));
}
