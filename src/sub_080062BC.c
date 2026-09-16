#include "global.h"

extern u8 gUnk_020020E0;
extern u8 gCallback_08006095[];   /* Thumb entry: function address | 1 */
extern u8 gUnk_0806C784[];

u32 sub_080078E4(void);
void sub_0800793C(u32 a);
void sub_08006214(void);
void sub_0800649C(u32 r0, u32 r1, u32 r2);
extern void sub_08016E10(u32 src, u32 dest, u32 control);
void sub_080055B0(void);

void sub_080062BC(void)
{
    u32 *r;
    u32 src;
    u32 dst;

    if (gUnk_020020E0 != 0)
        return;
    r = (u32 *)sub_080078E4();
    if (r != 0) {
        r[3] = (u32)gCallback_08006095;
        sub_0800793C((u32)r);
    }
    sub_08006214();
    sub_0800649C((u32)gUnk_0806C784, 0, 0x13);
    src = 0x08331FC8;
    dst = 0x06016280;
    sub_08016E10(src, dst, 0xC0);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    sub_08016E10(src, dst, 0xC0);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    sub_08016E10(src, dst, 0xC0);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    sub_08016E10(src, dst, 0xC0);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    sub_08016E10(src, dst, 0xC0);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    sub_08016E10(src, dst, 0xC0);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    sub_08016E10(src, dst, 0xC0);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    sub_08016E10(src, dst, 0xC0);
    sub_080055B0();
}
