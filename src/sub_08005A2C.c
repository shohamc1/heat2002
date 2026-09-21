#include "global.h"

extern u8 gUnk_08338720[];
extern u8 gUnk_08338788[];
extern u16 gUnk_0202522C;

u32 *sub_0800754C(u32 a);
s32 sub_08007714(u32 a);
u32 sub_080044A4(u32 a, u32 b);

void sub_08005A2C(u32 a1)
{
    u16 arr[2];
    u32 *p;
    u32 attr;
    u32 t;

    arr[0] = 0xC8;
    arr[1] = 0x78;
    p = sub_0800754C((u32)gUnk_08338720);
    if (p != 0) {
        attr = (arr[1] & 0xFF) | ((arr[0] & 0x1FF) << 16) | 0x80000000;
        t = *(u32 *)((u32)p + 0x10) | ((u8)sub_08007714((u32)gUnk_08338788) << 12);
        attr |= 0x100;
        sub_080044A4(attr, t);
    }
    gUnk_0202522C = (a1 + 0xA0) & 0xFF;
}
