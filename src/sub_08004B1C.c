#include "global.h"
#include "functions.h"

extern u32 gUnk_0202A540[];
extern u32 gUnk_0202CB20[];
extern u16 gKeysPressed;
extern s32 gUnk_08365308[];
extern s32 gUnk_083652B8[];
extern s32 gUnk_083652E0[];
extern u32 gUnk_0202CB00[];


void sub_08004B1C(u8 arg)
{
    s32 val;
    u32 sel = arg;
    u32 *p;
    u32 idx;
    u32 j;

    if (sel <= 4) {
        val = gUnk_0202A540[idx];
        p = gUnk_0202CB20;
    } else {
        val = gUnk_0202CB20[idx - 5];
        p = gUnk_0202CB20;
    }
    if (gKeysPressed & 0x20) {
        val = val - gUnk_08365308[sel];
        if (val < gUnk_083652B8[sel])
            val = gUnk_083652B8[sel];
    }
    if (gKeysPressed & 0x10) {
        val = val + gUnk_08365308[sel];
        if (val > gUnk_083652E0[sel])
            val = gUnk_083652E0[sel];
    }
    if (sel <= 4)
        gUnk_0202A540[idx] = val;
    else
        *(p + (j = idx - 5)) = val;
    sub_0800830C((u16 *)p,(u16 *)gUnk_0202CB00);
}
