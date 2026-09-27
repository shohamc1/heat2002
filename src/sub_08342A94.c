#include "global.h"
#include "variables.h"

void sub_083429B8(void);

void *sub_0833FF44(void);
void sub_0833FF94(u32);

void sub_08342A94(void)
{
    u32 r4;

    if (gUnk_0203916C[0] == 9)
        gUnk_0203916C[0] = 6;
    if (gUnk_0203916C[0] == 0xD)
        gUnk_0203916C[0] = 0xC;
    if (gUnk_0203916C[0] == 0xE)
        gUnk_0203916C[0] = 2;
    if (gUnk_0203916C[0] == 0xF)
        gUnk_0203916C[0] = 0x10;
    if (gUnk_0203916C[0] == 0x11)
        gUnk_0203916C[0] = 5;

    gUnk_020390D4 = 1;

    r4 = (u32)sub_0833FF44();
    if (r4 != 0)
    {
        *(u32 *)(r4 + 0x18) = 0;
        *(u32 *)(r4 + 0x0C) = (u32)sub_083429B8;
        sub_0833FF94(r4);
        gUnk_0203DE24 = r4;
    }
}
