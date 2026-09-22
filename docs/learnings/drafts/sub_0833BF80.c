/*
 * sub_0833BF80 — 2026-09-23 session 2 final: ratio 0.9263, 565/739
 * positional. Every structural wall cracked (details in parked.md and the
 * draft history): dead t++;t--; kills for the PRE wall, r4 pin for
 * gUnk_020390F0, camera mul operand swap, rrret block via goto INTO the
 * D5F4 then-arm, the r-region as a goto net (r_ext shared pair, s32 rt
 * for the signed ble, r_zero falling into the dispatch, case bodies in
 * ROM order 1/2/0x27), and the chained store
 * gUnk_020250EC = t2 = gUnk_020390AC / 256 (loads the store address
 * const BEFORE the division like the ROM).
 * Remaining (~220 diff lines): tail register cascades — the rr extension
 * flavor (ROM asrs vs ours lsrs; every type/cast/order lever tried, it is
 * reload's coin-flip on sign-agnostic uses), the busy-wait preload order
 * (r4/r2/r3/r5 vs ours r2/r5/r3/r4), the EC-test byte in r1 vs r0, a
 * 2-insn pair duplication in the DCB0 arm, and downstream pool order.
 * Permuter restarted from this file.
 */
#include "global.h"

/*
 * 2026-09-23 update: honest similarity 0.8765 (shift-insensitive stream);
 * permuter relaunched from this base (4070 after ~100 iters). New dead ends:
 * t -= 3 moved into/before the busy-wait (H1a/H1b) keeps both PRE inserts;
 * s32 prototype + (s8) cast does NOT force asrs (extension flavor is reload's
 * coin-flip when all uses are sign-agnostic); pre-gcse .cse dump shows both
 * (u8)t sites already carry independent pairs — the merge is purely gcse PRE
 * on (ashift (reg/v:SI 32) 24), dump insns 678/817 (bb 46/51), reaching reg 590.
 * sub_0833BF80 draft state (2026-09-22, evening session) — 1310B, 655 insns.
 * NOT matched; improved from the previous banked draft. Normalized-stream
 * match ~640/737; the remaining deltas are precisely known:
 *
 *   1. gcse PRE fires on expr (ashift (reg/v t) 24) (dump: expression 87,
 *      PRE at bb 46 + bb 51, reaching reg 590): emits two `lsls r6,r6,#24`
 *      inserts and turns both `(u8)t` sites into `lsrs r0,r6,#24` extracts.
 *      The ROM has NO inserts and a `lsls r0,r6,#24; lsrs r0,r0,#24` pair at
 *      each site. Levers tried and DEAD: u8 t (renormalizes + direct cmp),
 *      (u8)(arg1-3) at site 2 (recomputes via a callee-saved arg1 copy),
 *      deep casts (u8)(s16)/(u8)(u8)/(u8)(s8) (folded in the front end),
 *      dead-store count shifts (deleted before gcse), pad[]/first/arg s8
 *      perturbations (table stays 349 buckets, inserts persist). Next idea:
 *      split t into two pseudos gcse cannot canonicalize, or change the bb
 *      structure feeding bb 46's predecessors.
 *   2. r3/r4 swap at the top (&gUnk_020390F0 const vs the &gUnk_0203916C
 *      copy): target puts the POOL CONSTANT in r4, the copy in r3.
 *   3. ent/camera region: ours loads ent->unk40 early and muls
 *      (unk40 * gUnk_020251A4[..]); target loads gUnk_02025190[..] first,
 *      then gA4[..], then unk40 LAST, and muls (gA4 * unk40).
 *   4. busy-wait tail: register shuffle (r0/r1) and ours merges the
 *      `gUnk_02039154 = 1; return 1` block into the epilogue region instead
 *      of the ROM's out-of-line block at 0x833c19c (reached by b.n from the
 *      rr!=0 path at 0x833c51a).
 * Fixed this session (verified in the diff): s32 gUnk_020390AC (signed
 * /256: bge/adds#255/asrs), s16 third param of sub_0833B81C (asrs #19, no
 * zero-extend), gUnk_02039218[3..0] stores as four separate descending
 * statements, ent-selection arms inverted ((u8)t > 1 first), the r-switch
 * restructured as `if ((u8)r != 1) { if ((u8)r > 1) switch ((u8)r)
 * { case 2: ... case 0x27: ... } } else { sub_0833A8C8(0x38); }` — the
 * ROM's dispatch `cmp#1;beq / cmp#1;ble / cmp#2;beq / cmp#39;beq` is NOT a
 * plain 3-case switch (gcc 2.95 always re-roots a 3-case AVL at the
 * median); see parked.md for the full derivation.
 *
 * 2026-09-23 BREAKTHROUGH: the gcse PRE wall is SOLVED. hoist_code needs
 * hoistable > 1 (two dominated computing blocks with no intervening kill);
 * dead `t++; t--;` pairs before EACH (u8)t site give gcse a kill on t, and
 * DCE deletes the arithmetic completely (len 737, both ROM pairs present,
 * ratio 0.8874). Note: `t += 256; t -= 256;` leaves residue (the shared
 * 256 constant tangles between kills); ++/-- shares no constant.
 */

struct Ent {
    u8 pad00[0x3E];
    u8 unk3E;
    u16 unk40;
    u8 pad42[0x190 - 0x42];
};

extern u8 gUnk_02039100;
extern u8 gUnk_020391CC;
extern u8 gUnk_02039154;
extern u8 gUnk_0203916C;
extern u8 gUnk_020390F0;
extern u8 gUnk_020390A0;
extern u8 gUnk_020390DC;
extern u8 gUnk_020390BC;
extern u32 gUnk_020391E0[4];
extern u32 gUnk_02039158;
extern u8 gUnk_020391D4;
extern volatile s8 gUnk_020390D0;
extern u8 gUnk_020390FC;
extern u8 gUnk_0203E120[];
extern u8 gUnk_020390D4;
extern u8 gUnk_020250EC;
extern u8 gUnk_020390B8;
extern u8 gUnk_020390EC;
extern struct Ent gUnk_0203D520[];
extern u32 gUnk_02039110[4];
extern s32 gUnk_020390AC;
extern u8 gUnk_020391F0;
extern u8 gUnk_020390C4;
extern u8 gUnk_0203921C;
extern u16 gUnk_02039134;
extern u8 gUnk_02039218[4];
extern u8 gUnk_02039160[];
extern u8 gUnk_02039170[];
extern s32 gUnk_02025190[];
extern u8 gUnk_020251A4[];
extern u8 gUnk_02038FB0[];
extern u8 gUnk_0203D6B0[];
extern u16 gUnk_0203761C;
extern u8 gUnk_020392C4;
extern u8 gUnk_02038F70[];
extern u8 gUnk_08338FB0[];
extern u8 gUnk_0203E1B0;

void sub_0833CD2C(u8);
void sub_0833D9E8(u8);
void sub_0833EE20(void);
void sub_0833BF20(void);
void sub_0833D3E4(s32);
void sub_08343504(u32);
void sub_0833F448(u32);
void sub_0833F9A8(void);
void sub_0833FF1C(void);
void sub_0833D7D4(void);
void sub_0833D680(void);
void sub_0833D9D8(void);
void sub_08339B18(void);
void sub_0833BF6C(void);
void sub_0833EDF8(void);
void sub_0833EDB8(void);
void sub_0833A8C8(u16);
void sub_083426C8(void);
void sub_08342868(void);
void sub_08342B04(void);
void sub_0833D5F4(void *);
void sub_08344878(void);
void sub_08343148(u8 *, u32, u32);
void sub_0833B81C(void *, u16, s16);
void sub_0833D448(void);
void sub_0833D5B8(void);
void sub_0833D57C(void);
void sub_0833FFC4(void);
void sub_083419D8(void);
void sub_0833DF58(void);
void sub_0833CF10(u32, u32);
void sub_08340EFC(void);
void sub_0833AA60(u32, u16);
u32 sub_0833DBC8(void);
u8 sub_0833DCB0(void);
u32 sub_0833DBF4(void);
s8 sub_0833C874(void);
void sub_0833D288(u32, u32);
void sub_0833B074(void *);
void sub_0833FA3C(void);

s32 sub_0833BF80(u8 arg0, u8 arg1)
{
    u8 pad[4];
    register u8 *pf asm("r4");
    u32 t;
    u32 r;
    s32 rt;
    s32 i;
    u32 flag;
    struct Ent *ent;
    s32 t2;
    s8 rr;
    u8 first;

    t = arg1;
    gUnk_02039100 = 0;
    gUnk_020391CC = 0;
    gUnk_02039154 = 0;
    gUnk_0203916C = t;
    pf = &gUnk_020390F0;
    *pf = arg0;
    if (t != 0xF)
        gUnk_020390A0 = 5;
    if (gUnk_0203916C == 2)
        gUnk_020390A0 = 1;
    if (gUnk_0203916C == 0x11)
        gUnk_020390A0 = 1;
    if (gUnk_0203916C == 0xD)
        gUnk_020390A0 = 1;
    if (gUnk_0203916C == 0xE)
        gUnk_020390A0 = 1;
    if (*pf != 0)
        gUnk_020390A0 = 2;
    if (gUnk_020390DC > 6 && gUnk_020390DC != 8 && gUnk_020390DC != 9
        && gUnk_020390DC != 0xA && gUnk_020390DC != 0xB)
        gUnk_020390A0 = 1;
    if ((u8)(gUnk_0203916C - 3) <= 1)
        gUnk_020390A0 = gUnk_020390BC;
    gUnk_020391E0[0] = 0;
    gUnk_020391E0[1] = 0;
    gUnk_020391E0[2] = 0;
    gUnk_020391E0[3] = 0;
    sub_0833CD2C(gUnk_020390DC);
    sub_0833F448(gUnk_020390DC);
    sub_0833D9E8(gUnk_020390DC);
    sub_0833EE20();
    sub_0833BF20();
    gUnk_02039158 = 0x100;
    sub_0833D3E4(0x32);
    sub_08343504(gUnk_020390DC);
    sub_0833F9A8();
    sub_0833FF1C();
    sub_0833D7D4();
    sub_0833D680();
    sub_0833D9D8();
    gUnk_020391D4 = 1;
    gUnk_020390D0 = 0;
    first = gUnk_020390D0;
    t -= 3;
    if (first == 0) {
        do
            ;
        while (gUnk_020390D0 == 0);
    }
    sub_08339B18();
    gUnk_020390FC = 0;
    sub_0833BF6C();
    if (gUnk_0203916C == 0xE) {
        sub_0833EDF8();
    } else {
        sub_0833EDB8();
    }
    if (gUnk_020390F0 != 0) {
        if (gUnk_0203E120[2] != 0)
            sub_0833A8C8(1);
        gUnk_020390D4 = 1;
        gUnk_020250EC = 2;
        if (gUnk_020390F0 != 0) {
            for (i = 0; i != 100; i++)
                sub_083426C8();
            sub_08342868();
            goto skip42B04;
        }
    }
    if ((u8)(gUnk_0203916C - 3) <= 1)
        sub_08342B04();
skip42B04:
    if (gUnk_0203916C == 9 || gUnk_0203916C == 0xD || gUnk_0203916C == 0xE
        || gUnk_0203916C == 0xF || gUnk_0203916C == 0x11) {
        gUnk_020390B8 = 1;
        for (i = 0; i != 20; i++)
            sub_083426C8();
        gUnk_020390B8 = 0;
    }
    gUnk_020390B8 = 0;
    if (gUnk_020390EC != 0) {
        sub_0833D5F4(&gUnk_0203D520[(*(volatile u32 *)0x04000128 << 0x1A) >> 0x1E]);
        goto after_d5f4;
rrret:
        gUnk_02039154 = 1;
        return 1;
after_d5f4: ;
    } else {
        sub_0833D5F4(gUnk_0203D520);
    }
    gUnk_02039110[0] = gUnk_02039110[2];
    gUnk_02039110[1] = gUnk_02039110[3];
    gUnk_020390AC = 0;
    gUnk_020391F0 = 0;
    gUnk_020390C4 = 1;
    t++;
    t--;
    if ((u8)t <= 1)
        sub_08344878();
    sub_0833A8C8(0x38);
    t++;
    t--;
    gUnk_0203921C = 0;
    gUnk_02039134 = 0;
    flag = 0;
    gUnk_02039218[3] = 0;
    gUnk_02039218[2] = 0;
    gUnk_02039218[1] = 0;
    gUnk_02039218[0] = 0;
    while (gUnk_02039154 == 0) {
        sub_0833FA3C();
        sub_0833D680();
        sub_08343148(gUnk_02039160, 0x4B, 0x3C);
        if (gUnk_0203921C != 0)
            sub_08343148(gUnk_02039170, 0x4B, 0x5A);
        gUnk_02039134 = 0;
        if ((u8)t > 1)
            ent = gUnk_0203D520;
        else
            ent = &gUnk_0203D520[gUnk_0203E1B0];
        sub_0833B81C(gUnk_02038FB0, 1,
                    ((s16)(gUnk_02025190[ent->unk3E]
                         + ((ent->unk40 * gUnk_020251A4[ent->unk3E]) >> 6))) >> 3);
        if (gUnk_020390F0 != 0) {
            sub_0833D5F4(gUnk_0203D6B0);
            gUnk_020250EC = t2 = gUnk_020390AC / 256;
            if (t2 % 8 == 0)
                gUnk_020250EC = 4;
        } else {
            if (gUnk_020390EC != 0)
                sub_0833D5F4(&gUnk_0203D520[(*(volatile u32 *)0x04000128 << 0x1A) >> 0x1E]);
            else
                sub_0833D5F4(gUnk_0203D520);
        }
        if (gUnk_0203916C == 9 || gUnk_0203916C == 0xD || gUnk_0203916C == 0xE
            || gUnk_0203916C == 0xF || gUnk_0203916C == 0x11) {
            gUnk_02039110[0] = *(u32 *)&gUnk_0203D520[0];
            gUnk_02039110[1] = *(u32 *)((u8 *)&gUnk_0203D520[0] + 8);
        }
        sub_0833D448();
        sub_0833D5B8();
        sub_0833D57C();
        sub_0833FFC4();
        sub_083419D8();
        sub_0833DF58();
        if (gUnk_020390D4 != 0 || gUnk_0203916C == 9 || gUnk_0203916C == 0xD
            || gUnk_0203916C == 0xE || gUnk_0203916C == 0xF || gUnk_0203916C == 0x11)
            sub_083426C8();
        sub_0833CF10(gUnk_02039110[0], gUnk_02039110[1]);
        sub_0833D9D8();
        sub_08340EFC();
        gUnk_020391D4 = 1;
        if (gUnk_020390F0 != 0) {
            if (gUnk_0203761C != 0) {
                gUnk_020391CC = 1;
                gUnk_020391F0 = 2;
                sub_08339B18();
                *(volatile u16 *)0x04000000 &= 0xEFFF;
                if (gUnk_0203E120[2] != 0)
                    sub_0833AA60(gUnk_02038F70, 2);
                sub_0833D288(0x19, 0);
            }
        } else {
            if ((u8)(gUnk_0203916C - 3) > 1 && gUnk_020391F0 == 0) {
                if (gUnk_020392C4 != 0)
                    goto r_zero;
                r = sub_0833DBC8();
                goto r_ext;
            }
            if (gUnk_020392C4 != 0 || gUnk_020391F0 != 0)
                goto r_zero;
            if (gUnk_0203916C == 4)
                r = sub_0833DCB0();
            else
                r = sub_0833DBF4();
r_ext:
            rt = (u8)r;
            goto r_tests;
r_zero:
            rt = 0;
r_tests:
            if (rt == 1)
                goto r_case1;
            if (rt <= 1)
                goto r_end;
            if (rt == 2)
                goto r_case2;
            if (rt == 0x27)
                goto r_case27;
            goto r_end;
r_case1:
            sub_0833A8C8(0x38);
            goto r_end;
r_case2:
                if (gUnk_0203916C == 2 || gUnk_0203916C == 0xE || gUnk_0203916C == 0
                    || gUnk_0203916C == 7 || gUnk_0203916C == 6 || gUnk_0203916C == 9
                    || gUnk_0203916C == 5 || gUnk_0203916C == 0x11 || gUnk_0203916C == 1
                    || gUnk_0203916C == 3 || gUnk_0203916C == 0xC || gUnk_0203916C == 0xD
                    || gUnk_0203916C == 0x10 || gUnk_0203916C == 0xF
                    || gUnk_0203916C == 0x11) {
                    gUnk_020391CC = 1;
                    gUnk_020391F0 = 2;
                    sub_08339B18();
                    *(volatile u16 *)0x04000000 &= 0xEFFF;
                }
                sub_0833D288(0x19, 0);
            goto r_end;
r_case27:
            flag = 1;
r_end: ;
        }
        if (gUnk_020390EC != 0) {
            rr = sub_0833C874();
            if (rr != 0)
                goto rrret;
            gUnk_020390D0 = rr;
            do
                ;
            while (gUnk_020390D0 == 0);
        } else {
            gUnk_020390D0 = 0;
            first = gUnk_020390D0;
            if (first == 0) {
                do
                    ;
                while (gUnk_020390D0 == 0);
            }
        }
        gUnk_020390AC = gUnk_020390AC + 1;
        if (gUnk_020391F0 == 2 && gUnk_020392C4 == 0)
            gUnk_02039154 = 1;
    }
    if (flag != 0)
        return 1;
    sub_0833B074(gUnk_08338FB0);
    return 0;
}
