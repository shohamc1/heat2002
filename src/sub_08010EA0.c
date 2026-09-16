#include "global.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
extern u16 gKeysPressed;
extern volatile u8 gUnk_020020C0;
extern u8 gUnk_0202EF00[];
extern void sub_080045D8(void);
extern void sub_08007344(void);
extern void sub_080073D8(void);
extern void sub_08004484(void);
extern void sub_080047DC(void);
extern void sub_08000458(void);
extern void sub_0800F3A4(void);
extern void sub_0800F4FC(void);
extern void sub_0800F328(u32 a, void *b);
extern void sub_08010E04(u8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern u8 sub_08011E00(u16 keys, s8 v, u32 lo, u32 hi);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);

u8 sub_08010EA0(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    u8 t;
    v = 0;
    sub_080045D8();
    sub_08007344();
    sub_080073D8();
    sub_08004484();
    sub_080047DC();
    gUnk_020020C0 = 0;
    sub_08000458();
    sub_0800F3A4();
    sub_0800F4FC();
    sub_0800F328(0x082E4328, buf);
    sub_08010E04(0);
    sub_08004238(buf, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    sub_08000458();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    do {
        sub_08004484();
        t = v;
        sub_08010E04(t);
        sub_0800048C();
        if (gKeysPressed & 1)
            sel = t;
inner:
        v = sub_08011E00(gKeysPressed, v, 0, 0x0B);
        if (v == 6 || v == 7 || v == 10 || v == 11) {
            if ((gKeysPressed & 0x30) == 0)
                gKeysPressed |= 0x10;
            goto inner;
        }
        if (gKeysPressed & 2)
            sel = 0;
        sub_080047DC();
        gUnk_020020C0 = 0;
wait:
        if (gUnk_020020C0 == 0)
            goto wait;
        sub_08000458();
        sub_08000458();
    } while (sel == 0x40);
    sub_08000458();
    REG_DISPCNT = 0xA8 << 3;
    sub_08000458();
    if (gUnk_0202EF00[3] != 0)
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return sel != 0 ? v : 0;
}
