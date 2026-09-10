#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_0202EF00[];
extern void sub_0800F3C0(void);
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08014C60(u8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_08000458(void);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_08014E28(void)
{
    u8 buf[0x200];
    s8 z;
    s8 v;
    s8 sel;
    z = 0;
    v = 0;
    sub_0800F3C0();
    sub_08011C9C(1, buf);
    sub_08014C60(0);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08014C60(v);
        if (gKeysPressed & 1)
            sel = z;
        if ((gKeysPressed & 0x40) && v != 0) {
            v = 0;
            if (gUnk_0202EF00[3])
                sub_08001208(8);
        }
        if ((gKeysPressed & 0x80) && v == 0) {
            v = 1;
            if (gUnk_0202EF00[3])
                sub_08001208(8);
        }
        sub_08000458();
    } while (sel != 0);
    sub_0800420C(0, 0x0F);
    return sel;
}
