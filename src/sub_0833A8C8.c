#include "global.h"
struct Unk0801DACC { u32 unk0; u16 unk4; };
struct Unk0801DA90 { u32 unk0; u32 unk4; u32 unk8; };
extern struct Unk0801DACC gUnk_0200CAA4[];
extern struct Unk0801DA90 gUnk_0200CA74[];
extern void sub_0833AFC0(u32 a, u32 b);
void sub_0833A8C8(u16 idx)
{
    u32 v = gUnk_0200CA74[gUnk_0200CAA4[idx].unk4].unk0;
    sub_0833AFC0(v, gUnk_0200CAA4[idx].unk0);
}
