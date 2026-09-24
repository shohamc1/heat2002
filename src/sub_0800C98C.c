#include "global.h"

extern s32 gUnk_083CA0B8;
extern s32 gUnk_083CA0B4;

struct Unk0800C98C {
    s32 unk00;
    s32 unk04;
    s32 unk08;
};

void sub_0800C98C(struct Unk0800C98C *v)
{
    long long p1;
    s32 p2;
    s32 *xp;
    s32 t1;

    v->unk08 = (v->unk08 << 20) >> 20;
    p1 = (-(((long long)gUnk_083CA0B8) * (((long long)v->unk00) - v->unk04))) >> 8;
    p2 = (-(((long long)gUnk_083CA0B4) * v->unk08)) >> 8;
    t1 = (s32)p1;
    t1 += (s32)p2;
    t1 >>= 1;
    v->unk08 = ((v->unk08 + t1) << 20) >> 20;
    xp = &v->unk00;
    v->unk00 = (*xp) + v->unk08;
}
