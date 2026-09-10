#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_0202EF00[];
extern void sub_08011C9C(u32 a, void *b);
extern void sub_080134E8(u8 a, u8 b, u8 c);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern u8 sub_08011D38(u16 keys, s8 v, u32 lo, u32 hi);
extern void sub_08000458(void);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);
s8 sub_08013570(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(6, buf);
    sub_080134E8(0, a, b | a);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_080134E8(v, a, b);
        if ((gKeysPressed & 9) && (b == 0 || v != 0) && (a == 0 || v != 1))
            sel = v;
        if (gKeysPressed & 2)
            sel = 0xFF;
        v = sub_08011D38(gKeysPressed, v, 0, 4);
again:
        if ((v == 0 && (a != 0 || b != 0)) || (v == 1 && a != 0)) {
            if (gKeysPressed & 0xC0)
                v = sub_08011D38(gKeysPressed, v, 0, 4);
            else
                v = sub_08011D38(0x80, v, 0, 4);
            goto again;
        }
        sub_08000458();
    } while (sel == 0x40);
    if (gUnk_0202EF00[3] != 0)
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return sel;
}
