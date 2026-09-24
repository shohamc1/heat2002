#include "global.h"

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

extern struct Unk12A gUnk_0801DA90[];
extern struct Unk8B gUnk_0801DACC[];

void sub_080019B4(u32 r0);

void m4aSongNumStop(u16 a)
{
    struct Unk12A *pa = gUnk_0801DA90;
    struct Unk8B *baseB = gUnk_0801DACC;
    struct Unk8B *pb = baseB + a;

    if (*(u32 *)pa[pb->idx].ptr == pb->field0)
        sub_080019B4((u32)pa[pb->idx].ptr);
}
