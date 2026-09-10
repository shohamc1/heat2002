#include "global.h"

extern u16 gKeysPressed;
extern volatile u8 gUnk_020020C0;

extern void sub_080045D8(void);
extern void sub_08007344(void);
extern void sub_080073D8(void);
extern void sub_08011C9C(u8 a, void *b);
extern void sub_08004484(void);
extern void sub_08012C4C(u8 a);
extern void sub_080047DC(void);
extern void sub_08000458(void);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_0800420C(u32 a, u32 b);

u8 sub_08012D34(u8 a)
{
    u8 buf[0x200];
    s8 sel;
    u8 v;

    v = 0;
    sub_080045D8();
    sub_08007344();
    sub_080073D8();
    sub_08011C9C(6, buf);
    sub_08004484();
    sub_08012C4C(a);
    sub_080047DC();
    gUnk_020020C0 = v;
    sub_08000458();
    sub_08004238(buf, 0x0F);
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0xAA << 5;
    sel = 0x40;
    do
    {
        sub_08004484();
        sub_0800048C();
        sub_08012C4C(a);
        if (gKeysPressed & 1)
            sel = v;
        sub_080047DC();
        gUnk_020020C0 = 0;
        sub_08000458();
    } while (sel != 0);
    sub_0800420C(0, 0x0F);
    return sel;
}
