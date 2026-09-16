#include "global.h"

extern u8 gUnk_0829F2AC[];
extern u8 *gUnk_083FDDD0[];
extern u8 gUnk_0202EF20[];
extern u8 *gUnk_083FDCF0[];
extern u8 *gUnk_083FDC88[];

extern void sub_080063BC(u8 *p, u32 a1, u32 a2, u8 a3);
extern void sub_08006950(u8 *p, u32 a1, u8 a2);

void sub_08010AA4(u8 idx)
{
    u8 *p;

    p = gUnk_0829F2AC;
    sub_080063BC(p, 0, 4, 0);
    sub_08006950(gUnk_083FDDD0[idx], 4, 1);
    sub_080063BC(p, 0, 0x11, 0);
    sub_080063BC(p, 0, 0x12, 0);
    sub_080063BC(p, 0, 0x13, 0);
    if (gUnk_0202EF20[idx] != 0)
        sub_080063BC(gUnk_083FDCF0[idx], 0, 0x11, 1);
    else
        sub_080063BC(gUnk_083FDC88[idx], 0, 0x11, 1);
}
