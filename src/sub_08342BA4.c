#include "global.h"
#include "functions.h"

struct Unk08342BA4
{
    u8 filler0[0x0C];
    u32 field0C;
    u8 filler10[0x18 - 0x10];
    u32 field18;
};

extern u8 gUnk_0203DE30[];
void sub_08342B54(void);

void *sub_0833FF44(void);
void sub_0833FF94(struct Unk08342BA4 *a);

void sub_08342BA4(u32 a0, u32 a1, u32 a2)
{
    u8 *p;
    u32 z;
    struct Unk08342BA4 *ret;

    p = gUnk_0203DE30;
    z = 0;
    p[2] = 0x2E;
    p[5] = 0x2E;
    p[0] = sub_08344BB8(a0, 0x0A) + 0x30;
    p[1] = sub_08344C50(a0, 0x0A) + 0x30;
    p[3] = sub_08344BB8(a1, 0x0A) + 0x30;
    p[4] = sub_08344C50(a1, 0x0A) + 0x30;
    p[6] = sub_08344BB8(a2, 0x64) + 0x30;
    p[7] = sub_08344BB8(sub_08344C50(a2, 0x64), 0x0A) + 0x30;
    p[8] = z;
    ret = sub_0833FF44();
    if (ret != 0)
    {
        ret->field18 = 0x5A;
        ret->field0C = (u32)sub_08342B54;
        sub_0833FF94(ret);
    }
}
