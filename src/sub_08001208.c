#include "global.h"
struct Unk0801DACC { u32 unk0; u16 unk4; };
struct Unk0801DA90 { u32 unk0; u32 unk4; u32 unk8; };
extern struct Unk0801DACC gUnk_0801DACC[];
extern struct Unk0801DA90 gUnk_0801DA90[];
extern void sub_08001900(u32 a, u32 b);
void m4aSongNumStart(u16 idx)
{
    u32 v = gUnk_0801DA90[gUnk_0801DACC[idx].unk4].unk0;
    sub_08001900(v, gUnk_0801DACC[idx].unk0);
}
