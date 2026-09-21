#include "global.h"

struct Unk08340210
{
    u32 field00;
    u32 field04;
    u32 field08;
    u32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
};

extern struct Unk08340210 gUnk_0202708C[];
extern u32 gUnk_0203D4A0[];

void sub_08340210(u8 idx)
{
    u32 *d;
    u32 v0;
    u32 v1;
    u8 i;

    v0 = gUnk_0202708C[idx].field00;
    v1 = gUnk_0202708C[idx].field04;
    d = gUnk_0203D4A0;
    i = 0;
    do
    {
        d[0] = v0;
        d[1] = v1;
        d[2] = gUnk_0202708C[idx].field18;
        d += 3;
        d[0] = v0 + gUnk_0202708C[idx].field10;
        d[1] = v1 + gUnk_0202708C[idx].field14;
        d[2] = gUnk_0202708C[idx].field18;
        d += 3;
        v0 += gUnk_0202708C[idx].field08;
        v1 += gUnk_0202708C[idx].field0C;
        i++;
    } while (i != 0x0C);
}
