#include "global.h"
#include "data.h"


void sub_0800A628(s32 *a)
{
    register u32 rot asm("r9");
    u32 i;
    register s32 m asm("r1");
    s32 t1;
    s32 t2;
    register s32 sin1 asm("r5");
    register s32 cos1 asm("r4");
    register s32 j asm("r2");
    register s32 v asm("r0");
    register s32 t3 asm("r3");
    register s32 t4 asm("r2");
    register s32 sin2 asm("r8");
    s32 cos2;
    s32 val;
    register s32 *q asm("r6");
    s16 *p;
    register u32 rot2 asm("r1");
    s32 tmp;
    register s32 idx asm("r0");

    rot = (((u16 *)a)[0x1A] >> 10) << 16;
    i = rot >> 14;
    t1 = gUnk_0801CD08[i];
    t2 = gUnk_0801CD08[i + 0x40];
    m = -256;
    tmp = -(t1 * m);
    sin1 = tmp >> 8;
    tmp = t2 * m;
    cos1 = tmp >> 8;
    q = &a[0x4B];
    v = *q;
    j = (v >> 10) & 0x3F;
    j = j << 2;
    t3 = gUnk_0801CD08[j];
    idx = j;
    asm volatile("" : "+r"(idx));
    idx += 0x40;
    t4 = gUnk_0801CD08[idx];
    sin2 = -(t3 * m) >> 8;
    cos2 = (t4 * m) >> 8;
    if ((sin2 * sin1 + cos1 * cos2) >> 8 > 0x8D)
        return;
    rot2 = rot;
    i = rot2 >> 14;
    p = &gUnk_0801CD08[i];
    sin1 = gUnk_0801CD08[i + 0x40];
    cos1 = *p;
    if (sin2 * sin1 + cos1 * cos2 < 0)
        val = ((u16 *)a)[0x1A] - 0x2800;
    else
        val = ((u16 *)a)[0x1A] + 0x2800;
    *q = val;
    a[0x4B] = *(u16 *)&a[0x4B];
}
