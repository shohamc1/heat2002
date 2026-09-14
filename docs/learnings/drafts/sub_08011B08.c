#include "global.h"

extern volatile u16 gUnk_0202ED78[];
extern u8 gUnk_0202EDD0;
struct UnkEFA0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};
extern struct UnkEFA0 gUnk_0202EFA0[];
extern u8 gUnk_0202EEF4;
extern u16 gUnk_0202EF40[4][4];
extern u8 gUnk_0202EF90;
extern u8 gUnk_020020AC;
extern void sub_08011A50(void);
extern void sub_08016E30(void);
extern void sub_08016E14(u32 a, u32 b);
extern void sub_0800048C(void);
extern void sub_0800F818(u16 a);

void sub_08011B08(void)
{
    register u8 state asm("r8");
    register u8 ff asm("r9");
    register volatile u16 *ed asm("r10");
    u16 v;
    u16 t;

    sub_08011A50();
    state = 0;
    ed = gUnk_0202ED78;
    ff = 0xFF;
    do {
        if ((*(u8 *)0x04000128 & 0x30) == 0)
            sub_08016E30();
        else
            sub_08016E14(1, 0x80);
        sub_0800048C();
        key = (u8 *)0x04000128;
        t = (((*(u32 *)key << 26) >> 30) + 1) << 12 | 0x100;
        t |= (gUnk_0202EDD0 + 1) & ff;
        ed[0] = t;
        sub_0800F818(ed[0]);
        gUnk_0202EFA0[0].unk2 |= ff;
        gUnk_0202EFA0[1].unk2 |= ff;
        gUnk_0202EFA0[2].unk2 |= ff;
        gUnk_0202EFA0[3].unk2 |= ff;
        gUnk_0202EEF4 = 0;
        v = gUnk_0202EF40[0][0];
        if ((v >> 12) == 1) {
            gUnk_0202EFA0[0].unk2 = v >> 12;
            gUnk_0202EEF4 = v >> 12;
            if ((*(u8 *)0x04000128 & 0x30) != 0)
                gUnk_0202EDD0 = v - 1;
            if ((gUnk_0202EF40[1][0] >> 12) == 2) {
                gUnk_0202EFA0[1].unk2 = v >> 12;
                gUnk_0202EEF4 = gUnk_0202EF40[1][0] >> 12;
                if ((gUnk_0202EF40[2][0] >> 12) == 3) {
                    gUnk_0202EFA0[2].unk2 = v >> 12;
                    gUnk_0202EEF4 = gUnk_0202EF40[2][0] >> 12;
                    if ((gUnk_0202EF40[3][0] >> 12) == 4) {
                        gUnk_0202EFA0[3].unk2 = v >> 12;
                        gUnk_0202EEF4 = gUnk_0202EF40[3][0] >> 12;
                    }
                }
            }
        }
        gUnk_0202EF90 = (*(u32 *)0x04000128 << 26) >> 30;
        gUnk_020020AC = gUnk_0202EEF4;
        if (gUnk_0202EEF4 <= 1)
            state = state - 1;
        gUnk_0202EF40[0][0] = 0;
        gUnk_0202EF40[1][0] = 0;
        gUnk_0202EF40[2][0] = 0;
        gUnk_0202EF40[3][0] = 0;
        state = state + 1;
    } while (state != 5);
}
