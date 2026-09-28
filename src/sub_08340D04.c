#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_Timer[];


void sub_08340D04(void)
{
    u16 *p;
    u32 *q;
    u32 *r;
    u16 *base;

    base = *(u16 **)&gModule_TextLayerMapPtr;
    p = base + 0x128;
    sub_0833EF0C(gModule_Timer, 8, 8);
    /* sub_0833E36C: this file's old prototype took
       (u16 *, u32); the matched definition narrows idx
       to u8; call through the old one. */
    ((void (*)(u16 *, u32))sub_0833E36C)(p, 0);
    p = base + 0x12A;
    ((void (*)(u16 *, u32))sub_0833E36C)(p, gUnk_0203DD04);
    p = base + 0x12D;
    q = &gUnk_0203DCFC;
    ((void (*)(u16 *, u32))sub_0833E36C)(p, sub_08344BB8(*q, 0xA));
    p = base + 0x12F;
    ((void (*)(u16 *, u32))sub_0833E36C)(p, sub_08344C50(*q, 0xA));
    p = base + 0x132;
    r = &gUnk_0203D500;
    q = r;
    ((void (*)(u16 *, u32))sub_0833E36C)(p, sub_08344C50(sub_08344BB8(*q, 0x64), 0xA));
    p = base + 0x134;
    ((void (*)(u16 *, u32))sub_0833E36C)(p, sub_08344C50(sub_08344BB8(*q, 0xA), 0xA));
}
