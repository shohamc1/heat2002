#include "global.h"
#include "functions.h"
#include "data.h"

struct Unk12A
{
    u32 ptr;
    u32 pad[2];
};

struct Unk8B
{
    u32 field0;
    u16 idx;
    u16 pad;
};



void m4aSongNumContinue(u16 a)
{
    struct Unk12A *pa = (struct Unk12A *)gUnk_0801DA90;
    struct Unk8B *baseB = (struct Unk8B *)gUnk_0801DACC;
    struct Unk8B *pb = baseB + a;

    if (*(u32 *)pa[pb->idx].ptr == pb->field0)
        sub_08001134((struct MusicPlayerInfo *)((u32)pa[pb->idx].ptr));
}
