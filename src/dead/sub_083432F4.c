#include "global.h"
#include "variables.h"

extern s32 gUnk_02027804;
extern s32 gUnk_02027800;

struct Unk083432F4 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
};

void sub_083432F4(struct Unk083432F4 *v)
{
    long long p1;
    s32 p2;
    s32 *xp;
    s32 t1;

    v->unk08 = (v->unk08 << 20) >> 20;
    p1 = (-(((long long)gUnk_02027804) * (((long long)v->unk00) - v->unk04))) >> 8;
    p2 = (-(((long long)gUnk_02027800) * v->unk08)) >> 8;
    t1 = (s32)p1;
    t1 += (s32)p2;
    t1 >>= 1;
    v->unk08 = ((v->unk08 + t1) << 20) >> 20;
    xp = &v->unk00;
    v->unk00 = (*xp) + v->unk08;
}

extern s32 gUnk_0202780C;
extern s32 gUnk_02027808;

struct Unk08343388 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
};

void sub_08343388(struct Unk08343388 *v)
{
    long long p1;
    s32 p2;
    s32 *xp;
    s32 t1;

    v->unk08 = (v->unk08 << 20) >> 20;
    p1 = (-(((long long)gUnk_0202780C) * (((long long)v->unk00) - v->unk04))) >> 8;
    p2 = (-(((long long)gUnk_02027808) * v->unk08)) >> 8;
    t1 = (s32)p1;
    t1 += (s32)p2;
    t1 >>= 1;
    v->unk08 = ((v->unk08 + t1) << 20) >> 20;
    xp = &v->unk00;
    v->unk00 = (*xp) + v->unk08;
}

u8 sub_08343464(s32 x, s32 y);

u8 sub_0834341C(u8 *a1, s32 a2, s32 a3)
{
    if ((*(u32 *)&gModule_FrameCounter) == *(u32 *)(a1 + 0x138))
        return *(u8 *)(a1 + 0x134);
    *(u32 *)(a1 + 0x134) = sub_08343464(a2, a3);
    *(u32 *)(a1 + 0x138) = (*(u32 *)&gModule_FrameCounter);
    return *(u8 *)(a1 + 0x134);
}
