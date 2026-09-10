#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_0202EF00[];
extern void sub_0800F3C0(void);
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08013E3C(s32 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern u8 sub_08011D38(u16 keys, s8 v, u32 lo, u32 hi);
extern void sub_08000458(void);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_08014004(void)
{
    u8 buf[0x200];
    s8 v;
    s32 a;
    s8 sel;
    /* The copy and narrowed test below preserve initialization/register order. */
    a = 0;
    v = a;
    sub_0800F3C0();
    sub_08011C9C(6, buf);
    sub_08013E3C(0);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08013E3C(a);
        if (gKeysPressed & 1)
            sel = v;
        if ((gKeysPressed & 0x40) && a == 1) {
            a = 0;
            if (gUnk_0202EF00[3])
                sub_08001208(8);
        }
        if ((gKeysPressed & 0x80) && (u8)a == 0) {
            a = 1;
            if (gUnk_0202EF00[3])
                sub_08001208(8);
        }
        v = sub_08011D38(gKeysPressed, v, 0, 0);
        sub_08000458();
    } while (sel == 0x40);
    if (gUnk_0202EF00[3])
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return sel;
}
