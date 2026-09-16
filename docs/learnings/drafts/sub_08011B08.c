/*
 * sub_08011B08 — QUARANTINED wave 5e (2026-09-15, J2). COMPILES now; one
 * allocation-race cluster left. Fresh verification (rm .o; make .o; match.py):
 * MISMATCH, 324 bytes (target 324) — same size, diff runs at words 9-82
 * (0x08011b1a-0x08011baa: whole-loop register ripple) + stragglers at 150-161.
 *
 * BREAKTHROUGHS vs prior draft (all now byte-true in the region they cover):
 *  - NO register-asm pins for state/ff: plain `u8 state; u32 ff;` locals let
 *    global alloc home them r8/r9 NATURALLY, giving the exact target forms:
 *      state-1: mov r0,r8 / subs r0,#1 / lsls#0x18 / lsrs#0x18 / mov r8,r0
 *    (pins had produced `movs r0,#1; negs r0,r0; add r8,r0` — GCC 2.95 treats
 *    full-word asm-reg pins as raw storage and combine rewrites minus->add-neg,
 *    skipping the u8 narrowing).
 *  - `gUnk_0202EFA0[i].unk2 = ff | gUnk_0202EFA0[i].unk2;` (ff FIRST, not |=)
 *    gives the copy-before-load: mov r0,r9 / ldrb r1,[r2,#2] / orrs r0,r1.
 *    `x |= ff` (ff as op1) puts the reload copy AFTER the load — expand order.
 *  - No `key` local: plain casts (*(u32 *)0x04000128 / *(u8 *)0x04000128)
 *    CSE into ONE address pseudo that crosses the sub_0800F818 call.
 *  - `| 0x100` chain (movs r3,#0x80/lsls/adds r0,r3,#0/orrs r1,r0) matches.
 *
 * REMAINING DIFF (greg dump analysis, -dg): the callee-saved allocation race.
 * Ours:   r6=HOISTED const-0 pseudo — greg stats: reg74 "11 refs across 252
         insns, crosses 4 calls" (LICM hoists it to function entry), EDD0addr
         pushed out, KEYaddr pseudo (6 refs/96 insns, wins tie-break vs ed's
         6/92 by lower pseudo number) takes r10, ed(ED78) rematerializes per
         use (ldr =ED78 at each ed[0] access), prologue `ldr r1,=ED78; mov sl,r1`
         missing. Everything from 0x08011b1a on ripples from these homes.
         (reg66 = 26 refs/118 insns = EFA0 walker; reg120 = 10/74 = EF40;
         reg118 = 12/94 = EEF4.)
 * the ED78 pseudo from rematerializing (it has REG_EQUIV to a const so reload
 * remats it whenever unallocated). The const-0 hoist may also be attackable
 * by splitting the QImode EEF4-store zero from the HImode EF40-clears zero.
 */

#include "global.h"

extern volatile u16 gUnk_0202ED78[];
extern u8 gUnk_0202EDD0;
struct UnkEFA0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};
extern struct UnkEFA0 gUnk_0202EFA0[];
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
    u8 state;
    u32 ff;
    volatile u16 *ed;
    u16 v;
    u16 t;

    sub_08011A50();
    state = 0;
    ed = gUnk_0202ED78;
    ff = 0xFF;
    do {
        if ((*(u8 *)0x04000128 & 0x30) == 0)
            sub_08016E30();
        else
            sub_08016E14(1, 0x80);
        sub_0800048C();
        t = (((*(u32 *)0x04000128 << 26) >> 30) + 1) << 12 | 0x100;
        t |= (gUnk_0202EDD0 + 1) & ff;
        ed[0] = t;
        sub_0800F818(ed[0]);
        gUnk_0202EFA0[0].unk2 = ff | gUnk_0202EFA0[0].unk2;
        gUnk_0202EFA0[1].unk2 = ff | gUnk_0202EFA0[1].unk2;
        gUnk_0202EFA0[2].unk2 = ff | gUnk_0202EFA0[2].unk2;
        gUnk_0202EFA0[3].unk2 = ff | gUnk_0202EFA0[3].unk2;
        gUnk_0202EEF4 = 0;
        v = gUnk_0202EF40[0][0];
        if ((v >> 12) == 1) {
            gUnk_0202EFA0[0].unk2 = v >> 12;
            gUnk_0202EEF4 = v >> 12;
            if ((*(u8 *)0x04000128 & 0x30) != 0)
                gUnk_0202EDD0 = v - 1;
            if ((gUnk_0202EF40[1][0] >> 12) == 2) {
                gUnk_0202EFA0[1].unk2 = v >> 12;
                gUnk_0202EEF4 = gUnk_0202EF40[1][0] >> 12;
                if ((gUnk_0202EF40[2][0] >> 12) == 3) {
                    gUnk_0202EFA0[2].unk2 = v >> 12;
                    gUnk_0202EEF4 = gUnk_0202EF40[2][0] >> 12;
                    if ((gUnk_0202EF40[3][0] >> 12) == 4) {
                        gUnk_0202EFA0[3].unk2 = v >> 12;
                        gUnk_0202EEF4 = gUnk_0202EF40[3][0] >> 12;
                    }
                }
            }
        }
        gUnk_0202EF90 = (*(u32 *)0x04000128 << 26) >> 30;
        gUnk_020020AC = gUnk_0202EEF4;
        if (gUnk_0202EEF4 <= 1)
            state = state - 1;
        gUnk_0202EF40[0][0] = 0;
        gUnk_0202EF40[1][0] = 0;
        gUnk_0202EF40[2][0] = 0;
        gUnk_0202EF40[3][0] = 0;
        state = state + 1;
    } while (state != 5);
}
