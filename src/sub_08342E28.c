#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

u32 sub_08341644(s32 x, s32 y, s32 *out);

struct Tbl {
    u8 pad[0xC4];
    s32 unkC4[4];
    s32 unkD4[4];
    u8 pad2[0x190 - 0xE4];
};

void sub_08342E28(u32 a)
{
    struct Tbl *tbl;
    s32 out[2];
    s32 v0;
    s32 v1;
    s32 idx;
    s32 s1;
    s32 s2;
    s32 ry;
    s32 dx;
    s32 dy;
    s32 t;

    tbl = (struct Tbl *)((u8 *)gModule_Cars + *(u8 *)(a + 0x34) * 0x190);
    v0 = tbl->unkC4[*(s32 *)(a + 0x1C) + 2];
    v1 = tbl->unkD4[*(s32 *)(a + 0x1C) + 2];
    idx = *(u16 *)((u8 *)tbl + 0x34) >> 8;
    s1 = gUnk_0200C3E8[idx];
    s2 = gUnk_0200C3E8[idx + 0x40];
    dy = *(s32 *)(a + 0x08) + 0xFFF60000;
    ry = dy;
    dx = -(ry * s1) >> 8;
    dy = (s2 * ry) >> 8;
    if ((u8)sub_08341644(v0 + dx, v1 + dy, out) != 0)
    {
        out[0] -= 4;
        out[1] -= 6;
    }
    t = *(s32 *)(a + 0x18) + 1;
    idx = a + 0x18;
    *(s32 *)idx = t;
    *(s32 *)(a + 0x08) += 0x10000;
    if (t == 0x10)
    {
        sub_0833FFA8(a);
        sub_0833FF84(a);
    }
}
