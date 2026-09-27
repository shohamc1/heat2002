#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_0833CCD4(u8 idx)
{
    u32 off;
    u8 *base;
    u8 *p;

    base = (u8 *)gUnk_020251BC;
    off = idx * 100;
    p = base + 4;
    sub_08344B64(*(u32 *)(p + off), 0x06000000, 0x4000);
    sub_08344B64(*(u32 *)(base + off), 0x06008000, 0x2000);
    gUnk_02039294 = 0;
    gUnk_02039248 = 0;
    gUnk_020392A4 = 0;
}
