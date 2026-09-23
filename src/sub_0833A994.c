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

extern struct Unk12A gUnk_0200CA74[];
extern struct Unk8B gUnk_0200CAA4[];

void sub_0833B074(u32 r0);

void sub_0833A994(u16 a)
{
    struct Unk12A *pa = gUnk_0200CA74;
    struct Unk8B *baseB = gUnk_0200CAA4;
    struct Unk8B *pb = baseB + a;

    if (*(u32 *)pa[pb->idx].ptr == pb->field0)
        sub_0833B074((u32)pa[pb->idx].ptr);
}
