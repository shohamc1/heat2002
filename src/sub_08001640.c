#include "global.h"
extern u32 gUnk_03007FF0;
extern u16 gUnk_0801D0FC[];
extern s32 sub_08017230(s32 a, s32 b);
extern void sub_0800184C(void);
void sub_08001640(u32 a)
{
    u32 r4 = gUnk_03007FF0;

    a = (a & (0xF0 << 12)) >> 16;
    {
        u32 r6 = 0;

        *(u8 *)(r4 + 8) = a;
        {
            u16 r5 = gUnk_0801D0FC[a - 1];

            *(u32 *)(r4 + 0x10) = r5;
            *(u8 *)(r4 + 0xB) = sub_08017230(0xC6 << 3, r5);
            *(u32 *)(r4 + 0x14) = sub_08017230(r5 * 0x00091D1B + 0x1388, 0x2710);
            *(u32 *)(r4 + 0x18) = (sub_08017230(0x80 << 17, *(u32 *)(r4 + 0x14)) + 1) >> 1;
            *(volatile u16 *)0x04000102 = r6;
            {
                u32 t2 = 0x04000100;

                *(volatile u16 *)t2 = -sub_08017230(0x00044940, r5);
            }
        }
        sub_0800184C();
        while (*(volatile u8 *)0x04000006 == 0x9F)
            ;
        while (*(volatile u8 *)0x04000006 != 0x9F)
            ;
        *(volatile u16 *)0x04000102 = 0x80;
    }
}
