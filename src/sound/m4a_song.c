#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "data.h"

void m4aSongNumStop(u16 a)
{
    struct Unk0801DA90 *pa = gUnk_0801DA90;
    struct Unk0801DACC *baseB = gUnk_0801DACC;
    struct Unk0801DACC *pb = baseB + a;

    if (*(u32 *)pa[pb->unk4].unk0 == (u32)pb->unk0)
        m4aMPlayStop(pa[pb->unk4].unk0);
}

void m4aSongNumContinue(u16 a)
{
    struct Unk0801DA90 *pa = gUnk_0801DA90;
    struct Unk0801DACC *baseB = gUnk_0801DACC;
    struct Unk0801DACC *pb = baseB + a;

    if (*(u32 *)pa[pb->unk4].unk0 == (u32)pb->unk0)
        sub_08001134(pa[pb->unk4].unk0);
}
