#include "global.h"
#include "variables.h"

struct Unk83_A {
    u16 f9 : 9;
    u16 : 7;
};

struct Unk83_B {
    u8 f6 : 6;
    u8 g2 : 2;
};

struct Unk83_C {
    u16 f10 : 10;
    u16 : 6;
};


void sub_0836419C(s16 a, u8 b)
{
    struct Unk83_B *q;
    u8 *p;
    u8 *r;

    p = (u8 *)gIsland_OamBuffer;
    ((struct Unk83_A *)(p + 0x12))->f9 = a;
    q = (struct Unk83_B *)(p + 0x13);
    p[0x10] = b;
    r = p + 0x14;
    q->g2 = 2;
    ((struct Unk83_C *)r)->f10 = 0;
}
