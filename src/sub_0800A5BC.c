#include "global.h"

struct Unk0A5BC {
    u8 pad0[0x0C];
    u32 f0C;
    u32 f10;
    u32 f14;
    u8 pad18[0x24];
    u16 f3C;
    u8 f3E;
    u16 f40;
    u8 pad42[0x106];
    u32 f148;
};

void sub_0800A5BC(struct Unk0A5BC *p)
{
    u32 a;
    u8 b;

    a = 0;
    p->f0C = a;
    p->f14 = a;
    b = 0;
    p->f3C = a;
    p->f148 = a;
    p->f40 = a;
    p->f3E = b;
}
