#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"



void sub_08009FA0(u32 a1, u32 a2, u32 a3)
{
    u32 *p = (u32 *)gLinkMarkerFrameLists[a3];
    u32 attr;
    u32 *q;
    u32 t;

    p += sub_080172C8(gFrameCounter >> 1, 7);
    attr = (a2 & 0xFF) | ((a1 & 0x1FF) << 16) | 0x40000000;
    q = RequestObjTiles4(*p);
    if (q != 0) {
        t = *(u32 *)((u32)q + 0x10);
        t |= (u8)RequestObjPalette((u32)gLinkMarkerPalette) << 12;
        AddOamEntry(attr, t);
    }
}
