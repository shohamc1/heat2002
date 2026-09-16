#include "global.h"
#include "gba/defines.h"

extern u32 gUnk_083671F0[];
extern u32 gUnk_083671F8[];
extern u32 gUnk_08367228[];
extern u32 gUnk_08367268[];
extern u32 gUnk_08367290[];
extern u32 gUnk_083672B0[];
extern u32 gUnk_02025DB0[];
extern u32 gUnk_02025400[];
extern u32 gUnk_020255E0[];
extern u32 gUnk_02025AE0[];
extern u32 gUnk_02025C70[];
extern u32 gUnk_02025860[];
extern u32 gUnk_02025E00[];

void sub_08007304(u32 a, u16 *b, u32 *c);

void sub_08007344(void)
{
    u32 i;
    u32 color;
    u32 *q;

    {
        u16 *b = gUnk_083671F0;
        u32 *c = gUnk_02025DB0;
        sub_08007304(4, b, c);
    }
    {
        u16 *b = gUnk_083671F8;
        u32 *c = gUnk_02025400;
        sub_08007304(0x18, b, c);
    }
    {
        u16 *b = gUnk_08367228;
        u32 *c = gUnk_020255E0;
        sub_08007304(0x20, b, c);
    }
    {
        u16 *b = gUnk_08367268;
        u32 *c = gUnk_02025AE0;
        sub_08007304(0x14, b, c);
    }
    {
        u16 *b = gUnk_08367290;
        u32 *c = gUnk_02025C70;
        sub_08007304(0x10, b, c);
    }
    {
        u16 *b = gUnk_083672B0;
        u32 *c = gUnk_02025860;
        sub_08007304(0x20, b, c);
    }
    i = 0;
    color = OBJ_PLTT;
    q = gUnk_02025E00;
    for (; i != 0x10; q += 3, i++) {
        sub_080072F4((void *)q);
        *(u32 *)((u8 *)q + 8) = color;
        color += 0x20;
    }
}
