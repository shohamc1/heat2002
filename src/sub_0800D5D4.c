#include "global.h"

extern s16 gUnk_0801CD08[];

struct Unk0800D5D4 {
    s32 unk00;
    u8 pad04[4];
    s32 unk08;
    s32 unk0C;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[0x34 - 0x18];
    u16 unk34;
    u8 pad36[0x3C - 0x36];
    s16 unk3C;
};

void sub_0800D5D4(struct Unk0800D5D4 *a, s32 *d)
{
    s32 x, z;
    s32 v;

    v = -(a->unk34 >> 8) & 0xFF;
    d[0] = gUnk_0801CD08[v];
    d[1] = gUnk_0801CD08[v + 0x40];
    x = a->unk00;
    d[4] = x >> 8;
    z = a->unk08;
    d[5] = z >> 8;
    v = a->unk34 + a->unk3C;
    v = -(v >> 8) & 0xFF;
    d[2] = gUnk_0801CD08[v];
    d[3] = gUnk_0801CD08[v + 0x40];
    d[6] = (x + a->unk0C) >> 8;
    d[7] = (z + a->unk14) >> 8;
}
