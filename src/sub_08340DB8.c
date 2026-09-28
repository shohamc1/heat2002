#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_MPH[];


void sub_08340DB8(u32 a1)
{
    u16 *base;
    u16 *p;

    base = (u16 *)*(u32 *)&gModule_TextLayerMapPtr;
    p = base + 0x1CA;
    /* sub_0833E36C: this file's old prototype took
       (u16 *, u32); the matched definition narrows idx
       to u8; call through the old one. */
    ((void (*)(u16 *, u32))sub_0833E36C)(p, sub_08344C50(sub_08344BB8(a1, 0x64), 0x0A));
    p = base + 0x1CC;
    ((void (*)(u16 *, u32))sub_0833E36C)(p, sub_08344C50(sub_08344BB8(a1, 0x0A), 0x0A));
    p = base + 0x1CE;
    ((void (*)(u16 *, u32))sub_0833E36C)(p, sub_08344C50(a1, 0x0A));
    sub_0833EF0C(gModule_MPH, 0x10, 0x0F);
}
