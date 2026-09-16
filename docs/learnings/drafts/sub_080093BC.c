/*
 * sub_080093BC — RESOLVED 2026-09-14 wave 7: MATCH (1000 bytes).
 * The fix: the case-4 division is 0x6400 / (*p >> 8) (dividend is the
 * constant in r0, accumulator the divisor in r1) — the accumulator home
 * follows the divisor arg register; the old (*p >> 8) / 0x6400 had them
 * swapped. Prior quarantine notes below for history:
 *
 * QUARANTINED wave 6 (2026-09-14; budget reached at 22 diff
 * lines / 1000-of-1000 bytes — down from 358 (fresh re-verified from the
 * saved draft). This file IS the best state:
 * fresh-verified rm .o; make .o; match.py = MISMATCH with ONLY the case-4
 * register pair left, see below).
 *
 * WAVE-6 FIXES (all verified, cumulative):
 * 1. THREE branch-polarity/layout inversions fixed by swapping if/else
 *    order in the source (ROM puts the "else" body in fallthrough and
 *    branches on the == / ==0 condition):
 *      - l_big `a1->unk184 +=`: if (a1 != gUnk_0202A550) unk184 += 0x100
 *        else unk184 += gUnk_0202CAE0  (was swapped; ROM: bne to the 0x100
 *        block? NO - beq to the CaE0 block, 0x100 first in layout);
 *      - l_big tail: if (a1 == gUnk_0202A550) {A53C checks...} else
 *        {unk9C=0xB400 reset block} (ROM: bne away to the reset block,
 *        == path falls through);
 *      - case 6 head: if (a1->unk182 == 0) {else-body} else {C534 body}
 *        (ROM: bne away to the C534 body, ==0 path falls through).
 * 2. unk182 CSE-reload killed by hoisting: `v = a1->unk182;` before the
 *    case-6 head test, then using v for unk175 store + CBC8 store (the
 *    strb to unk175 kills CSE of the u16 otherwise -> extra ldrh + the
 *    0x182-offset reg died -> fresh 0x178 materialization; with the
 *    hoist ROM's `subs r1,#0xa` offset reuse appears for free).
 * 3. TWO WRONG SYMBOLS (pool words were 0x0202CAD0 / 0x020020E0 /
 *    0x020021E0): gUnk_0200CAD0 -> gUnk_0202CAD0 (symbols.ld has both;
 *    the 0200 spellings are decoys), gUnk_0202E0E0/gUnk_0202E0E1 ->
 *    gUnk_020020E0/gUnk_020021E0. This alone removed 3 pool-region
 *    diff hunks and the jump-over-pool branch surplus.
 *
 * Remaining diff (22 diff lines = 11 instructions, ONE web in case 4):
 *   ROM:  ldr r1,[r4](*p) ; ldr r0,[r2](gUnk_0202A520) ; adds r1,r1,r0
 *         lsls r0,r3,#2 ... ldr r0,[r0](table) ; adds r1,r1,r0 ; asrs r1
 *   ours: same insns with *p in r0 and both addends in r1 (asrs r0).
 *   Priority math says the gUnk_0202A520 value qty (2 refs / 2-insn span
 *   = 10000) should beat the *p value qty (6 refs / 15-insn span = 8000)
 *   and take r0 first - ours allocates *p first. Not yet found why.
 *   Try next: declaration order of p vs the += spelling, a dummy use to
 *   extend *p's live length past the asrs, or `*p = *p + gUnk_0202A520`
 *   with the str hoisted into a temp.
 * Earlier converged items (from wave 5, still true): struct Car s32
 * unk184/unk188/unk9C; gUnk_08368124/gUnk_08368134 as u32 VALUE arrays;
 * case 5 head `if (A && (B || C) && D) goto l_big;` with else first;
 * & 15 / & 3 masks; s32 *p pointer local for the unk188 accumulation.
 */

#include "global.h"

struct Car {
    u8 pad00[0x88];
    u32 unk88;
    u32 unk8C;
    u32 unk90;
    u32 unk94;
    u32 unk98;
    s32 unk9C;
    u8 padA0[0x175 - 0xA0];
    u8 unk175;
    u8 pad176[0x178 - 0x176];
    u32 unk178;
    u8 pad17C[0x181 - 0x17C];
    u8 unk181;
    u16 unk182;
    s32 unk184;
    s32 unk188;
    u8 pad18C[0x18F - 0x18C];
    u8 unk18F;
};

extern u8 gUnk_0202CAD0;
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202A53C;
extern struct Car gUnk_0202A550[];
extern u8 gUnk_0806C918[];
extern u8 gUnk_0806C924[];
extern u8 gUnk_0806C934[];
extern u32 gUnk_08368124[];
extern u32 gUnk_08368134[];
extern s32 gUnk_0202A520;
extern s32 gUnk_0202CAE0;
extern u8 gUnk_0202CBC0[];
extern u8 gUnk_0202CBC8[];
extern u8 gUnk_0202EF00[];
extern u8 gUnk_020020E0;
extern u8 gUnk_020021E0;

extern void sub_080080B4(void);
extern void sub_08006418(u8 *str, u32 y, u32 z);
extern void sub_0800C534(struct Car *a, u8 b);
extern void sub_0800A5BC(void *p);
extern void sub_080091F8(void);
extern u8 sub_080025FC(void);
extern void sub_08001208(u16 idx);
extern void sub_0800920C(u8 a);
extern void sub_0800649C(u32 a, u32 b, u32 c);
extern void sub_0800BE00(void *base, s32 arg);

void sub_080093BC(struct Car *a1, u8 a2)
{
    u32 v;
    s32 *p;

    if (gUnk_0202CAD0 != 0 && a1 == gUnk_0202A550)
        sub_080080B4();
    if (a1 == gUnk_0202A550 && gUnk_0202EEB0 == 0)
        sub_08006418(gUnk_0806C918, 10, 1);
    switch (a1->unk175) {
    case 0:
        break;
    case 1:
    case 2:
    case 3:
        sub_0800C534(a1, a2);
        break;
    case 4:
        if (gUnk_0202CAD0 == 0 && gUnk_0202A53C == 0)
            a1->unk175 = 5;
        else if (gUnk_0202EEB0 != 0)
            sub_0800A5BC(a1);
        else
            a1->unk175 = 5;
        if (gUnk_0202CAD0 != 0 && a1 == gUnk_0202A550) {
            sub_0800A5BC(a1);
            break;
        }
        a1->unk184 = 0;
        a1->unk188 = 0x6400;
        a1->unk175 = 5;
        if (a1 != gUnk_0202A550)
            break;
        a1->unk188 = gUnk_08368124[gUnk_0202CBC0[0]];
        if (gUnk_0202CBC0[1] == 2)
            gUnk_0202A520 = 0;
        if (gUnk_0202CBC0[1] == 1) {
            if (a1->unk9C > 0x8200)
                gUnk_0202A520 = 0xB400 - a1->unk9C;
            else
                gUnk_0202A520 = 0x3200;
        }
        if (gUnk_0202CBC0[1] == 0)
            gUnk_0202A520 = 0xB400 - a1->unk9C;
        p = &a1->unk188;
        *p += gUnk_0202A520;
        *p += gUnk_08368134[gUnk_0202CBC0[2]];
        gUnk_0202CAE0 = 0x6400 / (*p >> 8);
        *p = 0x6400;
        break;
    case 5:
        if (gUnk_0202EEB0 != 0)
            sub_0800A5BC(a1);
        if (a1->unk184 < a1->unk188
            && (a1 != gUnk_0202A550 || gUnk_0202A53C != 0)
            && gUnk_0202EEB0 != 0)
            goto l_big;
        if (a1 == gUnk_0202A550) {
            sub_080091F8();
            a1->unk182 = 1;
        } else {
            a1->unk182 = 1;
        }
        a1->unk175 = 6;
        break;
l_big:
        if (a1 == gUnk_0202A550) {
            if (gUnk_0202A53C != 0) {
                if (gUnk_0202EF00[3] != 0) {
                    if (gUnk_020020E0 == 0 && gUnk_020021E0 == 0
                        && (sub_080025FC() & 15) > 13) {
                        v = sub_080025FC() & 3;
                        if (v == 0)
                            sub_08001208(25);
                        if (v == 1)
                            sub_08001208(26);
                        if (v == 2)
                            sub_08001208(24);
                        if (v == 3)
                            sub_08001208(24);
                    }
                }
                sub_0800920C((a1->unk184 >> 8) % 100);
            }
        }
        if (a1 != gUnk_0202A550)
            a1->unk184 += 0x100;
        else
            a1->unk184 += gUnk_0202CAE0;
        if (a1 == gUnk_0202A550) {
            if (gUnk_0202A53C == 0)
                break;
            if (gUnk_0202A520 > 0) {
                gUnk_0202A520 -= 0x100;
                a1->unk9C += 0x100;
            }
            if (gUnk_0202CBC0[0] != 3) {
                a1->unk8C = 0;
                a1->unk90 = 0;
                a1->unk94 = 0;
                a1->unk98 = 0;
            }
            if (gUnk_0202CBC0[2] == 0)
                a1->unk88 = 0;
        } else {
            a1->unk9C = 0xB400;
            a1->unk8C = 0;
            a1->unk90 = 0;
            a1->unk94 = 0;
            a1->unk98 = 0;
            a1->unk88 = 0;
        }
        break;
    case 6:
        v = a1->unk182;
        if (v == 0) {
            a1->unk175 = v;
            if (a1 != gUnk_0202A550) {
                sub_0800BE00(a1, a1->unk178);
                a1->unk18F = 1;
            }
            gUnk_0202CBC8[a1->unk181] = v;
            if (a1 == gUnk_0202A550)
                sub_0800649C(gUnk_0806C924, 9, 10);
        } else {
            sub_0800C534(a1, a2);
            if (a1 == gUnk_0202A550 && gUnk_0202EEB0 != 0)
                sub_0800649C(gUnk_0806C934, 10, 10);
        }
        break;
    }
}
