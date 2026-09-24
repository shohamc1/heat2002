#include "global.h"
#include "gba/defines.h"
#include "data.h"

extern u16 gUnk_08332D88[];
extern u8 gUnk_0833338C[];
extern u8 gUnk_08332BC8[];

extern u32 *sub_0800767C(void *a);
extern u8 RequestObjPalette(u8 *a);
extern u32 AddOamEntry(u32 a, u32 b);

void DrawSpriteText(u8 *a, u32 b, u32 c)
{
    u32 *p;
    u32 pal;
    u32 x;
    u16 *q;
    register u8 *pa asm("r6");
    register u32 v asm("r1");

    pa = a;
    v = *pa++;
    if (v == 0)
        return;
    pal = 0xFF;
    pal = c & 0xFF;
loop:
    if (v != 0x20) {
        q = v + gUnk_08332D88;
        p = sub_0800767C(&gUnk_0833338C[gUnk_08333208[*q] * TILE_SIZE_4BPP]);
        if (p != 0) {
            x = ((b & 0x1FF) << 0x10) | pal;
            AddOamEntry(x, p[4] | (RequestObjPalette(gUnk_08332BC8) << 12));
        }
    }
    b += 8;
    v = *pa++;
    if (v != 0)
        goto loop;
}
