/*
 * sub_08011B08 — NEAR-MISS UPDATE 2026-09-22 (session 2): 312/316 bytes.
 * Structure COMPLETE (prologue, ed-hoist, keyaddr sharing, per-use ff
 * copies all present); the only remaining delta is ONE ALLOCATION SWAP:
 * target {ff=r9 (mov r0,r9 copies), keyaddr=r7 (direct ldr, ldrb [r7])}
 * vs ours {ff=r7 (adds r0,r7 copies + ands r0,r7), keyaddr=r9 (ldr r2 +
 * mov r9,r2 stash)}. ff type changes (u16/u32/s8/int) all identical;
 * pinning key to r7 loses to REG_EQUIV substitution (cse2 rewrites later
 * *key uses to fresh pool loads, ff steals r7); a volatile-poisoned key
 * derivation (`(*(volatile u8*)0x4000131 & 0) + 0x04000128`) keeps the
 * pseudo alive across the call but costs 2 extra insns the ROM doesn't
 * have. KEY SHAPE on this file: pins state=r8, edd0=r6, eef4=r5,
 * ef40=r4; NO v local; all-direct volatile casts for KEYINPUT; head
 * test non-volatile; per-use ff copies come from ff being an UNPINNED
 * homed local (a PIN coalesces the copies to one -- see probe).
 */
#include "global.h"

extern volatile u16 gUnk_0202ED78[];
extern u8 gUnk_0202EDD0;
extern u8 gUnk_0202EFA0[];
extern u8 gUnk_0202EEF4;
extern u16 gUnk_0202EF40[4][4];
extern u8 gUnk_0202EF90;
extern u8 gUnk_020020AC;
extern void sub_08011A50(void);
extern void sub_08016E30(void);
extern void sub_08016E14(u32 a, u32 b);
extern void sub_0800048C(void);
extern void sub_0800F818(u16 a);

void sub_08011B08(void)
{
    register u8 state asm("r8");
    volatile u16 *ed;
    register u8 *edd0 asm("r6");
    register u8 *eef4 asm("r5");
    register u16 *ef40 asm("r4");
    u16 t;
    u16 ff;
    u32 t1;
    u32 t2;
    u32 t3;
    u32 t4;
    int zero;

    sub_08011A50();
    state = 0;
    zero = 0;
    ed = gUnk_0202ED78;
    ff = 0xFF;
    do {
        if ((*(u8 *)0x04000128 & 0x30) == 0)
            sub_08016E30();
        else
            sub_08016E14(1, 0x80);
        sub_0800048C();
        t = ((((*((volatile u32 *)0x04000128) << 26) >> 30) + 1) << 12) | (0x80 << 1);
        edd0 = &gUnk_0202EDD0;
        t |= ff & (*edd0 + 1);
        ed[0] = t;
        sub_0800F818(ed[0]);
        gUnk_0202EFA0[2] = ff | gUnk_0202EFA0[2];
        gUnk_0202EFA0[6] = ff | gUnk_0202EFA0[6];
        gUnk_0202EFA0[10] = ff | gUnk_0202EFA0[10];
        gUnk_0202EFA0[14] = ff | gUnk_0202EFA0[14];
        eef4 = &gUnk_0202EEF4;
        ef40 = &gUnk_0202EF40[0];
        *eef4 = zero;
        t1 = ef40[0] >> 12;
        if (t1 == 1) {
            gUnk_0202EFA0[2] = t1;
            *eef4 = t1;
            if ((*(volatile u8 *)0x04000128 & 0x30) != 0)
                *edd0 = ef40[0] - 1;
            t2 = gUnk_0202EF40[1][0] >> 12;
            if (t2 == 2) {
                gUnk_0202EFA0[6] = t1;
                *eef4 = t2;
                t3 = gUnk_0202EF40[2][0] >> 12;
                if (t3 == 3) {
                    gUnk_0202EFA0[10] = t1;
                    *eef4 = t3;
                    t4 = gUnk_0202EF40[3][0] >> 12;
                    if (t4 == 4) {
                        gUnk_0202EFA0[14] = t1;
                        *eef4 = t4;
                    }
                }
            }
        }
        gUnk_0202EF90 = (*((volatile u32 *)0x04000128) << 26) >> 30;
        gUnk_020020AC = *eef4;
        if (((u8) *eef4) <= 1)
            state--;
        ef40[0] = 0;
        ef40[4] = 0;
        ef40[8] = 0;
        ef40[12] = 0;
        state++;
    } while (state != 5);
}
