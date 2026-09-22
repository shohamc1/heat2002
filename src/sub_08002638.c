#include "global.h"

extern u8 gUnk_020020B4;
extern u16 gUnk_02002124;
extern u8 gUnk_0800306D[];

void RegisterRamReset(u32 r0);
void sub_08000380(void);
void sub_0800048C(void);
void sub_080003F8(u32 r0);
void sub_08003F4C(u16 color);
void sub_0800420C(u32 r0, u32 r1);
void sub_08000458(void);
u32 sub_08015364(void);

void sub_08002638(void)
{
    register u8 z1 asm("r9");
    u32 z2;
    u32 eight;
    volatile u16 *p128;
    volatile u16 *ie;
    volatile u16 *ds;
    register volatile u16 *p asm("r1");

    RegisterRamReset(1);
    p128 = (volatile u16 *)0x04000128;
    z1 = 0;
    z2 = 0;
    p128[1] = z2;
    sub_08000380();
    ie = (volatile u16 *)0x04000200;
    *ie = z2;
    *(volatile u16 *)0x04000208 = 1;
    ds = (volatile u16 *)0x04000004;
    eight = 8;
    *ds = eight;
    sub_0800048C();
    gUnk_020020B4 = z1;
    sub_080003F8((u32)gUnk_0800306D);
    *ie = 0x2001;
    *ds = eight;
    sub_08003F4C(0x7FFF);
    sub_0800420C(0, 0x32);
    sub_08000458();
    p = (volatile u16 *)0x0400000E;
    *p = 0x3D0B;
    p -= 1;
    *p = 0x1E01;
    p -= 1;
    *p = 0x1F02;
    p -= 1;
    *p = 0x1C0C;
    p += 0x25;
    *p = 0x808;
    p -= 1;
    *p = 0x740;
    p -= 0x28;
    *p = 0x1D40;
    gUnk_02002124 = z2;
    for (;;)
        sub_08015364();
}
