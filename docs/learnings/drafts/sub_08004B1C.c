#include "global.h"

extern u32 gUnk_0202A540[];
extern u32 gUnk_0202CB20[];
extern volatile u16 gKeysPressed;
extern s32 gUnk_08365308[];
extern s32 gUnk_083652B8[];
extern s32 gUnk_083652E0[];
extern u32 gUnk_0202CB00[];

void sub_0800830C(u32 *a, u32 *b);

/* NEAR-MISS: everything matches except the first keys-test block, where the
 * compiler homes (kp, mask, value) as (r5, r1, r0); retail has (r1, r0, r5)
 * plus an `adds r5, r1` address-preservation copy that only appears when the
 * keys address is homed in a caller-saved register. Every register-pin
 * combination flips other homes (sel r3, val r2, p r6) instead. */

void sub_08004B1C(u8 arg)
{
    register u32 idx asm("r4");
    u32 sel = arg;
    s32 val;
    u32 *p;
    volatile u16 *kp;
    u32 m;

    if (sel <= 4) {
        val = gUnk_0202A540[idx];
        p = gUnk_0202CB20;
    } else {
        val = gUnk_0202CB20[idx - 5];
        p = gUnk_0202CB20;
    }
    kp = &gKeysPressed;
    m = 0x20;
    if (m & *kp) {
        val = val - gUnk_08365308[sel];
        if (val < gUnk_083652B8[sel])
            val = gUnk_083652B8[sel];
    }
    m = 0x10;
    if (m & *kp) {
        val = val + gUnk_08365308[sel];
        if (val > gUnk_083652E0[sel])
            val = gUnk_083652E0[sel];
    }
    if (sel <= 4)
        gUnk_0202A540[idx] = val;
    else
        p[idx - 5] = val;
    sub_0800830C(p, gUnk_0202CB00);
}
