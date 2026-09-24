#include "global.h"

extern s32 gUnk_083CA0C0;
extern s32 gUnk_083CA0BC;

struct Unk0800CA20 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
};

void sub_0800CA20(struct Unk0800CA20 *v)
{
    long long p1;
    s32 p2;
    s32 *xp;
    s32 t1;

    v->unk08 = (v->unk08 << 20) >> 20;
    p1 = (-(((long long)gUnk_083CA0C0) * (((long long)v->unk00) - v->unk04))) >> 8;
    p2 = (-(((long long)gUnk_083CA0BC) * v->unk08)) >> 8;
    t1 = (s32)p1;
    t1 += (s32)p2;
    t1 >>= 1;
    v->unk08 = ((v->unk08 + t1) << 20) >> 20;
    xp = &v->unk00;
    v->unk00 = (*xp) + v->unk08;
}
