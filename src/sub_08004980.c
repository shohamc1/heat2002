#include "global.h"
#include "variables.h"

extern u16 gUnk_020251F8;
extern u16 gUnk_02025254;

void sub_080047E8(u8 a, u16 b);

void sub_08004980(u32 a1)
{
    u8 pad[0x28];
    u8 *p;
    u32 v;
    u32 w;

    if (gUnk_02025244 == 0)
        return;
    p = *(u8 **)(a1 + 0x17C);
    v = *(u32 *)(a1 + 0x50) & 0xFFFF;
    w = gUnk_02025254;
    if (v <= w || w == 0) {
        if (*(s8 *)&gTrackCueId != -1 && gRaceEndState == 0)
            sub_080047E8(gTrackCueId, gUnk_020251F8);
    }
    v = *(u32 *)(a1 + 0x50) & 0xFFFF;
    if (v >= *(u16 *)p) {
        do {
            gTrackCueId = p[2];
            gUnk_020251F8 = *(u16 *)(p + 4);
            gUnk_02025254 = *(u16 *)(p + 6);
            p += 8;
            *(u32 *)(a1 + 0x17C) = p;
        } while (v >= *(u16 *)p);
    }
}
