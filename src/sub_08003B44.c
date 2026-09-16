#include "global.h"
#include "tilemap.h"
#include "gba/defines.h"

extern u32 gUnk_02002100[];
extern u32 gUnk_0200BC48;
extern u32 gUnk_0200BC4C;
extern u32 gUnk_02022DF8;
extern u32 gUnk_0200BC2C;
extern u32 gUnk_02022DE0;
extern u32 gUnk_02022DE8;
extern u8 gUnk_02002218;
extern u8 *gUnk_02002208;
extern u8 *gUnk_0200221C;
extern u16 gUnk_02022DE4;
extern u8 *gUnk_0200BC54;
extern u8 *gUnk_02002210;
extern u16 gUnk_0200BC34;

extern void sub_08003BFC(u32 x, u32 y, u8 *map, u32 *dest, u8 *charBase, u16 pal);

void sub_08003B44(void)
{
    s32 x;
    s32 y;

    x = gUnk_02002100[6] - 0x78;
    y = gUnk_02002100[7] - 0x50;
    gUnk_0200BC48 = x & 0x0F;
    gUnk_0200BC4C = y & 0x1F;
    gUnk_02022DF8 = x & 0x0F;
    gUnk_0200BC2C = y & 0x1F;
    gUnk_02022DE0 = x & 0x0F;
    gUnk_02022DE8 = y & 0x1F;
    gUnk_02002218 = x & 0x10;
    x >>= 5;
    y >>= 5;
    sub_08003BFC(x, y, gUnk_02002208, (u32 *)TILEMAP_BUFFER(0), gUnk_0200221C, gUnk_02022DE4);
    sub_08003BFC(x, y, gUnk_0200BC54, (u32 *)TILEMAP_BUFFER(1), gUnk_02002210, gUnk_0200BC34);
}
