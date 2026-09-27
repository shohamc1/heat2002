#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_0200CF74[];
extern u8 gUnk_0200CF84[];


void sub_0833E7FC(s32 a, s32 b)
{
    u8 *q;
    u8 *base;
    u8 *p;

    if (a == 999) {
        q = gUnk_0200CF74;
        sub_0833EF0C((u8 *)((u32)q), 0, 1);
        sub_0833EF0C((u8 *)((u32)q), 0, 0);
        return;
    }
    if (a > b)
        a = b;
    sub_0833EF0C((u8 *)((u32)gUnk_0200CF84), 0, 1);
    base = (u8 *)gModule_TextLayerMapPtr[0];
    p = base + 8;
    if (a > 99) {
        sub_0833E36C((u16 *)p, sub_08344BB8(a, 100));
        p += 4;
        sub_0833E36C((u16 *)p, sub_08344C50(sub_08344BB8(a, 10), 10));
        p += 4;
        sub_0833E36C((u16 *)p, sub_08344C50(a, 10));
        p += 4;
    } else if (a > 9) {
        sub_0833E36C((u16 *)p, sub_08344C50(sub_08344BB8(a, 10), 10));
        p = base + 12;
        sub_0833E36C((u16 *)p, sub_08344C50(a, 10));
        p += 4;
    } else {
        sub_0833E36C((u16 *)p, sub_08344C50(a, 10));
        p = base + 12;
    }
    p += 0x40;
    sub_0833E3C8((u16 *)p, 11);
    p += 2;
    if (b > 99) {
        sub_0833E3C8((u16 *)p, (u8)sub_08344BB8(b, 100));
        p += 2;
        sub_0833E3C8((u16 *)p, (u8)sub_08344C50(sub_08344BB8(b, 10), 10));
        p += 2;
        sub_0833E3C8((u16 *)p, (u8)sub_08344C50(b, 10));
    } else if (b > 9) {
        sub_0833E3C8((u16 *)p, (u8)sub_08344C50(sub_08344BB8(b, 10), 10));
        p += 2;
        sub_0833E3C8((u16 *)p, (u8)sub_08344C50(b, 10));
    } else {
        sub_0833E3C8((u16 *)p, (u8)sub_08344C50(b, 10));
    }
}
