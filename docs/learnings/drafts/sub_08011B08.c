/*
 * sub_08011B08 — NEAR-MISS UPDATE 2026-09-22 (session 3, V5): 312/316 bytes.
 * THE ALLOCATION SWAP IS FIXED: a `volatile u32 *key` local, assigned inside
 * the loop right before the `t = ...` line (pool load into r7 at exactly the
 * ROM's point) and RE-ASSIGNED before the gUnk_0202EF90 read, flips ff into
 * r9 (movs r2,#255; mov r9,r2) and key into r7 (ldr r7,[pc] direct). The
 * re-assignment is what wins the tie (3 uses beats ff's refs) while its
 * remat reproduces the ROM's second pool load; a key local with only 2 uses
 * (dying at the & 0x30 read) LOSES the tie again — V4 proved it.
 * Remaining deltas (all downstream of scratch allocation):
 *   - 0x80<<1 temp: target r3, ours r6 (ours then reloads r6 for edd0).
 *   - ed copy `mov r3,sl` vs ours `mov r0,sl`; EFA0 base r2 vs ours r3.
 *   - nest: target keeps ef40[0]'s full ldrh value (r3) for the `- 1` and
 *     keeps r4 = ef40 through the nest; ours re-loads both (pressure).
 *   - line-74 read: target `ldrb r7,[r7,#0]` lets the byte take the dying
 *     key home; ours `ldrb r1,[r7,#0]`.
 *   - line-92 remat lands in r7 (ours) vs r0 (target).
 *   - state--/++: target normalizes on write (mov r0,r8; +/-; lsls/lsrs;
 *     mov r8,r0), ours adds directly (negs/add r8). Explicit (u8) casts
 *     fold identically (V7 — no change).
 * Pins (state=r8, edd0=r6, eef4=r5, ef40=r4) remain load-bearing: removing
 * them (V6) loses 4 bytes of shape.
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
    volatile u32 *key;
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
        key = (volatile u32 *)0x04000128;
        t = (((key[0] << 26) >> 30) + 1) << 12 | (0x80 << 1);
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
            if ((*(volatile u8 *)key & 0x30) != 0)
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
        key = (volatile u32 *)0x04000128;
        gUnk_0202EF90 = (key[0] << 26) >> 30;
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
