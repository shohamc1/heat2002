#include "global.h"
extern u16 gUnk_020020A0[];
extern u8 gUnk_020020AC;
extern volatile u8 gUnk_020020C0;
extern u8 gUnk_0202EF90;
extern u8 gUnk_082B8710[], gUnk_082E4328[], gUnk_0829F30C[];
struct Car
{
    u8 pad[0x162];
    u8 choice;
    u8 rest[400 - 0x163];
};
extern struct Car gUnk_0202A550[];
extern void sub_08011A50(void);
extern void sub_08016E10(u32 src, u32 dst, u32 ctrl);
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
extern u32 sub_08003330(void);
extern u8 sub_080116D4(u16 a, u8 b, u32 c, u32 d, u8 *e, u8 f);
extern u32 sub_08016558(u32 a);
extern void sub_08006950(u32 a, u32 b, u32 c);

/* Near-miss: 720 bytes versus 724. The input loop strength-reduces b[i]
   into a running pointer; the ROM recomputes its address each iteration.
   Signed-load selection and later register/pool placement also differ. */
s8 sub_0801177C(void)
{
    u8 buf[0x200];
    u8 a[4];
    u8 b[4];
    u16 c[4];
    u16 d[4];
    s8 sel;
    s8 e;
    s32 i;
    s32 n;
    u8 count;
    u8 *p;

    sub_08011A50();
    i = 3;
    p = &a[3];
    do {
        *p-- = i;
        i--;
    } while (i >= 0);
    e = a[(*(volatile u32 *)0x04000128 << 26) >> 30];
    sub_08016E10((u32)gUnk_082B8710, 0x06016000, 0x80 << 5);
    sub_080045D8();
    sub_08007344();
    sub_080073D8();
    sub_08004484();
    sub_080047DC();
    gUnk_020020C0 = 0;
    sub_08000458();
    sub_0800F3A4();
    sub_0800F4FC();
    sub_0800F328((u32)gUnk_082E4328, buf);
    sub_08010E04(a[(*(volatile u32 *)0x04000128 << 26) >> 30]);
    sub_08004238(buf, 0x0F);
    *(volatile u16 *)(0x80 << 19) = 0xA8 << 3;
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0xAA << 5;
    sel = 0x40;
    for (i = 0; i < gUnk_020020AC; i++)
        b[i] |= 0xFF;
    while (sel == 0x40) {
        sub_08004484();
        sub_08010E04(a[gUnk_0202EF90]);
        n = gUnk_020020AC;
        for (i = 0; i < n; i++)
            d[i] = gUnk_020020A0[i];
        if (sub_08003330() != 0) {
            sel = -1;
            break;
        }
        for (i = 0; i < gUnk_020020AC; i++) {
            c[i] = (gUnk_020020A0[i] ^ d[i]) & gUnk_020020A0[i];
            if ((s8)b[i] == -1)
                a[i] = sub_080116D4(c[i], a[i], 0, 0x1D, a, i);
            if (c[i] & 1)
                b[i] = a[i];
            if (c[i] & 2) {
                if (i == 0) {
                    if ((s8)b[0] != -1) {
                        b[0] = 0xFF;
                    } else {
                        sel = -2;
                        break;
                    }
                } else {
                    b[i] = 0xFF;
                }
            }
        }
        count = 0;
        for (i = 0; i < gUnk_020020AC; i++) {
            if ((s8)b[i] != -1)
                count++;
        }
        if ((s8)b[gUnk_0202EF90] != -1) {
            sub_08006950(sub_08016558(0x58), 0x11, 1);
            if (count == gUnk_020020AC) {
                for (i = 0; i < gUnk_020020AC; i++) {
                    gUnk_0202A550[i].choice = b[i];
                    sel = b[i];
                }
            }
        } else {
            sub_08006950((u32)gUnk_0829F30C, 0x11, 1);
        }
        sub_080047DC();
        gUnk_020020C0 = 0;
spin:
        if (gUnk_020020C0 == 0)
            goto spin;
    }
    if (sel == -2)
        return sel;
    if (sel == -1)
        return sel;
    if (sel == 0)
        return 0;
    return e;
}
