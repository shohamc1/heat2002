/*
 * sub_08011B08 — SESSION 4 (2026-09-23): 312 -> 316 bytes, 18 diff lines.
 * EVERYTHING MATCHES except the two state ops + their pool offsets.
 *
 * LANDED THIS SESSION (all verified by match.py):
 *  - v1 = ef40[0] raw-local: the nest's `- 1` reads the SAME ldrh the t1
 *    shift came from (target keeps r3 across the branch). A direct
 *    re-mention re-loads narrowed to ldrb (stores kill the alias).
 *  - tail: direct global mentions, not the pointer: gUnk_0202EF40[i][0]=0
 *    (pool reload at c00) and gUnk_020020AC = gUnk_0202EEF4 (one ldrb,
 *    CSE-shared by the (u8)<=1 test). The nest reads stay via ef40 (r4).
 *  - end KEYINPUT read: direct cast (fresh pool load to r0), NOT a
 *    re-assignment of the key local (that remats into r7).
 *  - `ef40 = &gUnk_0202EF40[0];` AFTER `*eef4 = zero;` (order in ROM).
 *  - IntrWait/VBlankIntrWait are the matched syscall names now.
 *  - ff natural r9 + key natural r7 via the V5 3-use tie (unchanged).
 *
 * THE WALL (both twins): the state ops. Target: `mov r0,r8; +/-1; lsls
 * #24; lsrs #24; mov r8,r0` (mask-on-write, promoted-SImode discipline).
 * Three dead ends, all root-caused:
 *  (a) u8 pin (this draft): promote-on-read — `mov r1,r8; lsls; lsrs;
 *      subs` — same 5-insn multiset, wrong order. convert_move on a
 *      (reg:QI 8) ALWAYS extends; no spelling avoids it (~30 tried:
 *      --/++/-=/int-temps/shift-masks/casts — all fold or extend).
 *  (b) u32 pin: the DEC comes out PERFECT (`mov r0,r8; subs; lsls; lsrs`)
 *      but the INC's mask is fold-deleted — `((state+1)<<24)>>24`
 *      collapses to a bare in-place `add r8,r7` (Thumb has add-hi-reg
 *      but no sub-hi-reg; that asymmetry is why minus survives). Also
 *      rotates the entry (key pseudo takes r8's tie).
 *  (c) unpinned u8 (PROMOTED pseudo — the right discipline, both ops
 *      perfect): needs key PINNED r7 or the key pseudo eats r8 and state
 *      spills to stack (sub sp,#4). With key pinned + ff natural r9 +
 *      state r8: the early block scrambles — EFA0 base lands r3 not r2,
 *      cascading v1->r7, nest temps, ed copy r0. EFA0 pick is invariant
 *      under every OR spelling (|=, operand swap, embedded assign,
 *      c80/u16/u32 typing: all byte-identical). Post-call block alloc
 *      order; the permuter cannot run (key pin unparseable, and without
 *      it the allocation collapses).
 *  (d) pinning the EFA0 base r2 (call-clobbered, no calls in its span —
 *      legal) fixes that pick but the remaining clusters each rotate
 *      (0x80-temp r2, ed copy r0, v1 r7, zero-store sinks below ldr r4):
 *      192 lines. Multi-rooted cascade; pins fix one cluster and perturb
 *      the next ("pins cascade", see parked.md).
 * Next lever if resumed: reload-pass tracing on the W2/W7 build around
 * the post-call block's pseudo allocation order; the 4A20 twin shares
 * this wall exactly.
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
extern void VBlankIntrWait(void);
extern void IntrWait(u32 a, u32 b);
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
    u16 v1;
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
            VBlankIntrWait();
        else
            IntrWait(1, 0x80);
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
        *eef4 = zero;
        ef40 = &gUnk_0202EF40[0];
        v1 = ef40[0];
        t1 = v1 >> 12;
        if (t1 == 1) {
            gUnk_0202EFA0[2] = t1;
            *eef4 = t1;
            if ((*(u8 *)key & 0x30) != 0)
                *edd0 = v1 - 1;
            t2 = ef40[4] >> 12;
            if (t2 == 2) {
                gUnk_0202EFA0[6] = t1;
                *eef4 = t2;
                t3 = ef40[8] >> 12;
                if (t3 == 3) {
                    gUnk_0202EFA0[10] = t1;
                    *eef4 = t3;
                    t4 = ef40[12] >> 12;
                    if (t4 == 4) {
                        gUnk_0202EFA0[14] = t1;
                        *eef4 = t4;
                    }
                }
            }
        }
        gUnk_0202EF90 = ((*(volatile u32 *)0x04000128) << 26) >> 30;
        gUnk_020020AC = gUnk_0202EEF4;
        if ((u8)gUnk_0202EEF4 <= 1) {
            int s = state;
            state = s - 1;
        }
        gUnk_0202EF40[0][0] = 0;
        gUnk_0202EF40[1][0] = 0;
        gUnk_0202EF40[2][0] = 0;
        gUnk_0202EF40[3][0] = 0;
        state++;
    } while (state != 5);
}
