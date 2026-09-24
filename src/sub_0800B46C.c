#include "global.h"

extern u32 gUnk_0202CC08[];
extern u32 gUnk_0202CC1C[];
extern u32 gUnk_0202CC00[];

s32 sub_08017230(s32 a, s32 b);
s32 sub_080172C8(s32 a, s32 b);
void RemoveTask(u32 a);
void FreeTask(u32 a);

struct Unk0800B46C
{
    u8 pad00[0x18];
    s32 f18;
};

void sub_0800B46C(struct Unk0800B46C *e)
{
    u8 buf[0x60];
    u8 *p0;
    u8 *p1;
    u8 *p3;
    u8 *p4;
    u8 *q6;
    u8 *q7;
    u8 *q8;
    u32 z;
    s32 digit;
    s32 v1;
    s32 v2;
    s32 v3;

    p0 = buf;
    v1 = gUnk_0202CC08[0];
    digit = sub_080172C8(sub_08017230(v1, 10), 10) + 0x30;
    z = 0;
    p0[0] = digit;
    p1 = buf;
    p1[1] = sub_080172C8(v1, 10) + 0x30;
    buf[2] = 0x3A;
    p3 = buf;
    v2 = gUnk_0202CC1C[0];
    p3[3] = sub_080172C8(sub_08017230(v2, 10), 10) + 0x30;
    p4 = buf;
    p4[4] = sub_080172C8(v2, 10) + 0x30;
    buf[5] = 0x3A;
    q6 = buf;
    v3 = gUnk_0202CC00[0];
    q6[6] = sub_080172C8(sub_08017230(v3, 100), 10) + 0x30;
    q7 = buf;
    q7[7] = sub_080172C8(sub_08017230(v3, 10), 10) + 0x30;
    q8 = buf;
    q8[8] = sub_080172C8(v3, 10) + 0x30;
    buf[9] = z;
    e->f18 = e->f18 - 2;
    if (e->f18 == 0)
    {
        RemoveTask((u32)e);
        FreeTask((u32)e);
    }
}
