#include "global.h"
#include "tilemap.h"
#include "gba/defines.h"
#include "functions.h"
#include "variables.h"



void UpdateTrackScroll(void)
{
    s32 x;
    s32 y;

    x = gCamera[6] - 0x78;
    y = gCamera[7] - 0x50;
    gUnk_0200BC48 = x & 0x0F;
    gUnk_0200BC4C = y & 0x1F;
    gUnk_02022DF8 = x & 0x0F;
    gUnk_0200BC2C = y & 0x1F;
    gUnk_02022DE0 = x & 0x0F;
    gUnk_02022DE8 = y & 0x1F;
    gUnk_02002218 = x & 0x10;
    x >>= 5;
    y >>= 5;
    /* sub_08003BFC: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32, u32, u8 *, u32 *, u8 *, u16))sub_08003BFC)(x, y, gUnk_02002208, (u32 *)TILEMAP_BUFFER(0), gUnk_0200221C, gUnk_02022DE4);
    ((void (*)(u32, u32, u8 *, u32 *, u8 *, u16))sub_08003BFC)(x, y, gUnk_0200BC54, (u32 *)TILEMAP_BUFFER(1), gUnk_02002210, gUnk_0200BC34);
}
