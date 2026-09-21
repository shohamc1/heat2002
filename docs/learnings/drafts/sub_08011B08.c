/*
 * sub_08011B08 — NEAR-MISS (2026-09-21 session: 316/316 bytes, was 324).
 * BEST FORM = this banked source (v2): twin-shape rewrite with
 *   `u32 v` local + `int zero` var for the EEF4 store + t1..t4 locals +
 *   `volatile u16 *ed` + `(0x80 << 1)` spelling + `ff & (EDD0+1)` order.
 * Prologue and the whole entry half now MATCH byte-for-byte; remaining
 * diff is a 4-register ripple (target: KEYaddr=r7 homed across
 * sub_0800F818, EDD0=r6, EEF4=r5, EF40=r4; ours: v=r4 steals the slot,
 * KEYaddr left as per-use scratch r0, EDD0=r7, EEF4=r6, EF40=r5) plus
 * two t1-region shapes (ours reuses v -> `ands r4,r0`; target re-reads
 * a BYTE `ldrb r7,[r7]`; and the head test's const-vs-load order).
 *
 * Session findings (the allocation is a knife edge on cse table state):
 *  - `zero` (int var for gUnk_0202EEF4 = 0) is REQUIRED: it forces the
 *    QI-store zero to rematerialize per use (REG_EQUIV spill->remat,
 *    `movs r0,#0` at the site) and keeps it separate from the HI-clear
 *    zeros — the same QI/HI cse mode-split as sub_080047E8. Without it
 *    (literal 0), cse merges ALL five zero stores into ONE pseudo that
 *    LICM-hoists to a callee-saved home and state spills to [sp].
 *  - replacing `(v & 0x30)` with the byte-cast `(*(u8*)0x04000128 &
 *    0x30)` gives the right `ldrb [r7]` shape BUT adds an 8th global
 *    allocno (the KEYaddr pseudo) -> state spills; combining it with
 *    zero-var, with no zero-var, or with an in-loop `u16 zh` for the
 *    HI clears all re-shuffle the race badly (324-332 bytes).
 *  - The target has EXACTLY 7 global allocnos: state,ff,ed,KEYaddr,
 *    EDD0,EEF4,EF40 — with const-0 rematerialized. Getting KEYaddr to
 *    home r7 WITHOUT an 8th allocno is the closing move.
 *  - Permuter run (55k iters) on v2: floor 850, no improvement — its
 *    error count suggested misconfigured scoring for this file.
 *  - Swapped-AND spelling (0x30 & KEYbyte) fixes const-vs-load order
 *    but also reshuffles the prologue — apply only together with a
 *    winning allocno set.
 * Twin sub_08344A20: port THIS v2 shape; its banked draft is close but
 * predates the t1..t4/zero/v combination verified here.
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
    u8 state;
    volatile u16 *ed;
    u32 v;
    u16 t;
    u8 ff;
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
        if ((*(volatile u8 *)0x04000128 & 0x30) == 0)
            sub_08016E30();
        else
            sub_08016E14(1, 0x80);
        sub_0800048C();
        v = *((volatile u32 *)0x04000128);
        t = ((((v << 26) >> 30) + 1) << 12) | (0x80 << 1);
        t |= ff & (gUnk_0202EDD0 + 1);
        ed[0] = t;
        sub_0800F818(ed[0]);
        gUnk_0202EFA0[2] |= ff;
        gUnk_0202EFA0[6] |= ff;
        gUnk_0202EFA0[10] |= ff;
        gUnk_0202EFA0[14] |= ff;
        gUnk_0202EEF4 = zero;
        t1 = gUnk_0202EF40[0][0] >> 12;
        if (t1 == 1) {
            gUnk_0202EFA0[2] = t1;
            gUnk_0202EEF4 = t1;
            if ((v & 0x30) != 0)
                gUnk_0202EDD0 = gUnk_0202EF40[0][0] - 1;
            t2 = gUnk_0202EF40[1][0] >> 12;
            if (t2 == 2) {
                gUnk_0202EFA0[6] = t1;
                gUnk_0202EEF4 = t2;
                t3 = gUnk_0202EF40[2][0] >> 12;
                if (t3 == 3) {
                    gUnk_0202EFA0[10] = t1;
                    gUnk_0202EEF4 = t3;
                    t4 = gUnk_0202EF40[3][0] >> 12;
                    if (t4 == 4) {
                        gUnk_0202EFA0[14] = t1;
                        gUnk_0202EEF4 = t4;
                    }
                }
            }
        }
        gUnk_0202EF90 = (*((volatile u32 *)0x04000128) << 26) >> 30;
        gUnk_020020AC = gUnk_0202EEF4;
        if (((u8) gUnk_0202EEF4) <= 1)
            state--;
        gUnk_0202EF40[0][0] = 0;
        gUnk_0202EF40[1][0] = 0;
        gUnk_0202EF40[2][0] = 0;
        gUnk_0202EF40[3][0] = 0;
        state++;
    } while (state != 5);
}
