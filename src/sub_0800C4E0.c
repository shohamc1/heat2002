#include "global.h"

extern u8 gUnk_020020CC;
extern s32 gUnk_083672F0[];

struct UnkStruct0800C4E0 {
    u8 pad0[2];
    s16 f2;
    u8 pad4[6];
    s16 fA;
    u8 padC[0x175];
    u8 f181;
};

s32 sub_0800C4E0(struct UnkStruct0800C4E0 *a)
{
    s32 *t;
    s32 *pp;
    s32 idx;
    s32 d;
    s32 e;
    s32 x;
    s32 y;

    t = gUnk_083672F0;
    idx = gUnk_020020CC * 8 + a->f181;
    d = t[idx * 2];
    pp = (s32 *)((idx * 2 + 1) * 4 + (u32)t);
    e = *pp;
    x = a->f2;
    y = a->fA;
    d = d - x;
    if (d < 0)
        d = -d;
    y = e - y;
    if (y < 0)
        y = -y;
    if (d > y)
        y = d;
    return y;
}
