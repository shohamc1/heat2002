#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"

extern u32 gUnk_03007FF0;
extern u16 gUnk_0801D0FC[];
extern s32 sub_08017230(s32 a, s32 b);
extern void sub_0800184C(void);
void sub_08001640(u32 a)
{
    u32 r4 = (u32)SOUND_INFO_PTR;

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
            REG_TM0CNT_H = r6;
            {
                u32 t2 = REG_ADDR_TM0CNT;

                *(volatile u16 *)t2 = -sub_08017230(0x00044940, r5);
            }
        }
        sub_0800184C();
        while (*(volatile u8 *)REG_ADDR_VCOUNT == 0x9F)
            ;
        while (*(volatile u8 *)REG_ADDR_VCOUNT != 0x9F)
            ;
        REG_TM0CNT_H = TIMER_ENABLE;
    }
}
