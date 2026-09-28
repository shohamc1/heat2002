#include "global.h"
#include "functions.h"
#include "variables.h"



struct Unk08342C3C
{
    u8 pad00[0x18];
    s32 f18;
};

void sub_08342C3C(struct Unk08342C3C *e)
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
    v1 = gUnk_0203DE28[0];
    digit = sub_08344C50(sub_08344BB8(v1, 10), 10) + 0x30;
    z = 0;
    p0[0] = digit;
    p1 = buf;
    p1[1] = sub_08344C50(v1, 10) + 0x30;
    buf[2] = 0x3A;
    p3 = buf;
    v2 = gUnk_0203DE3C[0];
    p3[3] = sub_08344C50(sub_08344BB8(v2, 10), 10) + 0x30;
    p4 = buf;
    p4[4] = sub_08344C50(v2, 10) + 0x30;
    buf[5] = 0x3A;
    q6 = buf;
    v3 = gUnk_0203DE20[0];
    q6[6] = sub_08344C50(sub_08344BB8(v3, 100), 10) + 0x30;
    q7 = buf;
    q7[7] = sub_08344C50(sub_08344BB8(v3, 10), 10) + 0x30;
    q8 = buf;
    q8[8] = sub_08344C50(v3, 10) + 0x30;
    buf[9] = z;
    e->f18 = e->f18 - 2;
    if (e->f18 == 0)
    {
        ModuleRemoveTask((u32)e);
        ModuleFreeTask((u32)e);
    }
}
