#include "global.h"
#include "variables.h"

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

void ModuleBuildStartingGrid(u8 idx)
{
    u32 *p;
    u32 x;
    u32 y;
    u8 j;

    x = gUnk_0202708C[idx].field00;
    y = gUnk_0202708C[idx].field04;
    p = gUnk_0203D4A0;
    j = 0;
    do {
        p[0] = x;
        p[1] = y;
        p[2] = gUnk_0202708C[idx].field18;
        p += 3;
        p[0] = x + gUnk_0202708C[idx].field10;
        p[1] = y + gUnk_0202708C[idx].field14;
        p[2] = gUnk_0202708C[idx].field18;
        p += 3;
        x += gUnk_0202708C[idx].field08;
        y += gUnk_0202708C[idx].field0C;
        j++;
    } while (j != 0x0C);
}
