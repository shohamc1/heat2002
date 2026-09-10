#include "global.h"
extern u16 gUnk_020020A0;
extern volatile u8 gUnk_020020C0;
extern u16 gUnk_0202EF40[];
extern s8 gUnk_0202EF8C;
extern u8 gUnk_0202EF90;
extern u8 gUnk_083FDE78[];
extern void sub_08011A50(void);
extern void sub_08000458(void);
extern void sub_080045D8(void);
extern void sub_08007344(void);
extern void sub_080073D8(void);
extern void sub_08004484(void);
extern void sub_080047DC(void);
extern void sub_0800F3A4(void);
extern void sub_0800F4FC(void);
extern void sub_0800F328(u32 a, void *b);
extern void sub_08010FE4(s8 a, u8 b);
extern void sub_08004238(void *a, u32 b);
extern u32 sub_08003330(void);
extern void sub_08001208(u16 a);

u8 sub_080107E0(void)
{
    u8 buf[0x200];
    s32 sel;
    u16 k;
    u16 prev;

    sub_08011A50();
    gUnk_0202EF40[0] = 0;
    gUnk_0202EF40[4] = 0;
    gUnk_0202EF40[8] = 0;
    gUnk_0202EF40[12] = 0;
    sub_08000458();
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
    sub_08010FE4(0, 1);
    sub_08004238(buf, 0x0F);
    *(volatile u16 *)(0x80 << 19) = 0xA8 << 3;
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0xAA << 5;
    sel = 0x40;
    gUnk_0202EF8C = 0;
    prev = 0;
    do {
        sub_08004484();
        sub_080073D8();
        k = gUnk_020020A0;
        if (sub_08003330() != 0) {
            sel = 3;
            continue;
        }
        k = (k ^ gUnk_020020A0) & gUnk_020020A0;
        if (k & 0x10) {
            gUnk_0202EF8C++;
            if (gUnk_0202EF8C == 7)
                gUnk_0202EF8C = 8;
            if (gUnk_0202EF8C > 0x0B)
                gUnk_0202EF8C = 0x0B;
        }
        if (k & 0x20) {
            gUnk_0202EF8C--;
            if (gUnk_0202EF8C == 7)
                gUnk_0202EF8C = 6;
            if (gUnk_0202EF8C == -1)
                gUnk_0202EF8C = 0;
        }
        if (gUnk_0202EF8C != prev) {
            sub_08001208(8);
            prev = gUnk_0202EF8C;
        }
        sub_08000458();
        if (gUnk_0202EF90 == 0)
            sub_08010FE4(gUnk_0202EF8C, 1);
        else
            sub_08010FE4(gUnk_0202EF8C, 1);
        if (k & 1) {
            sub_08001208(9);
            gUnk_0202EF8C = gUnk_083FDE78[gUnk_0202EF8C];
            sel = 1;
        }
        if (k & 2)
            sel = 2;
        sub_080047DC();
        gUnk_020020C0 = 0;
    spin:
        if (gUnk_020020C0 == 0)
            goto spin;
        sub_08000458();
    } while (sel == 0x40);
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0xA8 << 3;
    sub_08000458();
    if (sel == 2)
        return 0;
    if (sel == 3)
        return 2;
    return 1;
}
