#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_0202EF00[];
extern void sub_0800F3A4(void);
extern void sub_0800F498(void);
extern void sub_0800F328(u32 a, void *b);
extern void sub_0800F3C0(void);
extern void sub_08013B64(u8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_08001208(u16 a);
extern u8 sub_08011D38(u16 keys, s8 v, u32 lo, u32 hi);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);

u8 sub_08013D5C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    u8 x;
    x = v = 0;
    sub_0800F3A4();
    sub_0800F498();
    sub_0800F328(0x082EE104, buf);
    sub_0800F3C0();
    sub_08013B64(0);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08013B64(x);
        if (gKeysPressed & 1)
            sel = v;
        if ((gKeysPressed & 0x40) && x == 1) {
            x = 0;
            if (gUnk_0202EF00[3] != 0)
                sub_08001208(8);
        }
        if ((gKeysPressed & 0x80) && x == 0) {
            x = 1;
            if (gUnk_0202EF00[3] != 0)
                sub_08001208(8);
        }
        v = sub_08011D38(gKeysPressed, v, 0, 0);
        sub_08000458();
    } while (sel == 0x40);
    if (gUnk_0202EF00[3] != 0)
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return sel;
}
