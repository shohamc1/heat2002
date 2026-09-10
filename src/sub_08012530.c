#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_0202EF00[];
extern u8 gUnk_083FDA60[];
extern u8 gUnk_083FDA67[];
extern void sub_08011C9C(u32 a, void *b);
extern void sub_080123F8(s8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_0800F600(void);
extern void sub_0800F6A0(void);
extern void sub_0800F740(void);
extern u8 sub_08011D38(u16 keys, s8 v, u32 lo, u32 hi);
extern u8 sub_08011E00(u16 keys, u8 a, u8 b, u8 c);
extern void sub_080100B0(void);
extern void sub_08010094(void);
extern void sub_08000458(void);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_08012530(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(7, buf);
    sub_080123F8(0);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_080123F8(v);
        if (gKeysPressed & 1) {
            if (v == 5) {
                sub_0800F600();
                sub_0800F6A0();
                sub_0800F740();
                return sel;
            }
            sel = v;
        }
        if (gKeysPressed & 2)
            sel = 1;
        v = sub_08011D38(gKeysPressed, v, 0, 5);
        gUnk_0202EF00[v] = sub_08011E00(gKeysPressed, gUnk_0202EF00[v],
                                        gUnk_083FDA60[v], gUnk_083FDA67[v]);
        if (v == 2) {
            if ((gKeysPressed & 0x30) && gUnk_0202EF00[2] != 0)
                sub_080100B0();
            if ((gKeysPressed & 0x30) && gUnk_0202EF00[2] == 0)
                sub_08010094();
        }
        sub_08000458();
    } while (sel == 0x40);
    if (gUnk_0202EF00[3] != 0)
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return sel;
}
