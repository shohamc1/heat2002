#include "global.h"

struct EAA0 {
    u8 filler0[0x14];
    u8 f14;
    u8 filler15;
    u16 f16;
    u8 f18;
    u8 f19[3];
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 filler1F[0x28 - 0x1F];
    u8 *f28;
    u8 filler2C[0x48 - 0x2C];
    u8 f48;
    u8 f49;
    u8 f4A;
    u8 f4B;
};

extern u16 gUnk_0200048C[];
extern u32 sub_0800EFC0(struct EAA0 *a);
extern u32 sub_0800EFD0(struct EAA0 *a);
extern void sub_0800EA64(struct EAA0 *a);
extern void sub_0800EED8(struct EAA0 *a);
extern u32 sub_0800EE8C(struct EAA0 *a, u32 v);
extern void sub_0800F0D4(u32 a);
extern u32 sub_08016E20(void);

u32 sub_0800EAA0(struct EAA0 *a)
{
    u8 *p4A;
    u32 v;

    if (sub_0800EFC0(a) != 0)
        return 0;
    p4A = a;
    p4A += 0x4A;
    if (*p4A > 0xF) {
        *p4A = *p4A - 1;
        return 0;
    }
    for (;;) {
        if (a->f48 != 0) {
            u8 *p = &a->f48;

            *p = 0;
            v = *(volatile u16 *)0x04000128 & 0xFC;
            if (v != 8) {
                sub_0800EA64(a);
                return 8 ^ v;
            }
        }
        if (a->f18 <= 0xDF) {
            switch (a->f18) {
            case 0: {
                s32 r5;
                s32 k;
                u32 p;
                u32 w;
                r5 = 0x0E;
                if (*(volatile u16 *)0x04000126 == 0xFFFF) {
                    p = 0x04000126;
                    k = 3;
                    do {
                        r5 >>= 1;
                        p -= 2;
                        k--;
                    } while (k != 0 && *(volatile u16 *)p == 0xFFFF);
                }
                a->f1D = r5 & 0x0E;
                w = *(volatile u16 *)0x04000126;
                if (((a->f1E >> 3) & 1) != 0 && w != 0x7208) {
                    r5 = 0;
                } else {
                    k = 3;
                    do {
                        w = *(volatile u16 *)(0x04000120 + 2 * k);
                        if (((a->f1E >> k) & 1) != 0 && w != ((1 << k) | 0x7200)) {
                            r5 = 0;
                            break;
                        }
                        k--;
                    } while (k != 0);
                }
                a->f1E = r5 & a->f1E;
                if (r5 == 0)
                    *p4A = 0x0F;
                if (*p4A == 0 && a->f1D != a->f1E) {
                    sub_0800EED8(a);
                    goto case1;
                }
                if (*p4A != 0)
                    *p4A = *p4A - 1;
                goto common6200;
            }
            case 1:
            case1: {
                s32 k;
                u32 v2;
                a->f49 = 0;
                k = 3;
                do {
                    v2 = *(volatile u16 *)(0x04000120 + 2 * k);
                    if ((v2 >> 8) == 0x72) {
                        gUnk_0200048C[k - 1] = v2;
                        if ((v2 & 0xFF) == (1 << k))
                            a->f49 |= v2 & 0xFF;
                    }
                    k--;
                } while (k != 0);
                if (a->f1D == a->f49) {
                    a->f18 = 2;
                    return sub_0800EE8C(a, 0x6100 | a->f49);
                }
                goto common6200;
            }
            case 2: {
                s32 k;
                u32 v2;
                k = 3;
                do {
                    if ((a->f49 & (1 << k)) != 0) {
                        v2 = *(volatile u16 *)(0x04000120 + 2 * k);
                        if (v2 != gUnk_0200048C[k - 1])
                            a->f49 &= ~(1 << k);
                    }
                    k--;
                } while (k != 0);
                goto check49;
            }
            case 0xD0: {
                s32 r5;
                s32 k;
                s32 p;
                u32 v2;
                r5 = 1;
                k = 3;
                do {
                    v2 = *(volatile u16 *)(0x04000120 + 2 * k);
                    a->f19[k - 1] = v2;
                    if ((a->f49 & (1 << k)) != 0) {
                        if ((u32)((v2 >> 8) - 0x72) > 1) {
                            sub_0800EA64(a);
                            return 0x60;
                        }
                        if (v2 == gUnk_0200048C[k - 1])
                            r5 = 0;
                    }
                    k--;
                } while (k != 0);
                if (r5 == 0)
                    return sub_0800EE8C(a, 0x6300 | a->f1C);
                a->f18 = 0xD1;
                r5 = 0x11;
                p = 2;
                k = 3;
                do {
                    r5 += a->f19[p];
                    p--;
                    k--;
                } while (k != 0);
                a->f14 = r5;
                return sub_0800EE8C(a, 0x6400 | (r5 & 0xFF));
            }
            case 0xD1: {
                s32 k;
                u32 p;
                u32 v2;
                k = 3;
                p = 0x04000126;
                do {
                    v2 = *(volatile u16 *)p;
                    if ((a->f49 & (1 << k)) != 0) {
                        if ((v2 >> 8) != 0x73) {
                            sub_0800EA64(a);
                            return 0x60;
                        }
                    }
                    p -= 2;
                    k--;
                } while (k != 0);
                if (sub_08016E20() == 0) {
                    a->f18 = 0xE0;
                    a->f16 = 0x190;
                    return 0;
                }
                sub_0800EA64(a);
                *p4A = 0x1E;
                return 0x70;
            }
            default: {
                s32 k;
                u32 v2;
                k = 3;
                do {
                    if ((a->f49 & (1 << k)) != 0) {
                        v2 = *(volatile u16 *)(0x04000120 + 2 * k);
                        if ((v2 >> 8) == 0x62 - (a->f18 >> 1)
                            && (v2 & 0xFF) == (1 << k))
                            continue;
                        a->f49 &= ~(1 << k);
                    }
                    k--;
                } while (k != 0);
                if (a->f18 == 0xC4) {
                    a->f1E = a->f49 & 0x0E;
                    a->f18 = 0;
                    goto common6200;
                }
                goto check49;
            }
            }
        } else {
            if (sub_0800EFD0(a) != 0)
                return 0;
            if (a->f4B == 1 && a->f18 > 0xE1 && sub_0800EFC0(a) == 0) {
                sub_0800F0D4(a->f4B);
                continue;
            }
        }
        if (sub_0800EFC0(a) != 0)
            return 0;
        if (a->f16 == 0) {
            sub_0800EA64(a);
            return 0x71;
        }
        a->f16 = a->f16 - 1;
        return 0;
    check49: {
        u32 v2;
        if (a->f49 == 0) {
            sub_0800EA64(a);
            return 0x50;
        }
        a->f18 = a->f18 + 2;
        if (a->f18 == 0xC4)
            goto common6200;
        v2 = (a->f28[a->f18 - 3] << 8) | a->f28[a->f18 - 4];
        if (sub_0800EE8C(a, v2) != 0)
            return 1;
        if (a->f4B == 1) {
            sub_0800F0D4(a->f4B);
            continue;
        }
        return 0;
    }
    common6200:
        return sub_0800EE8C(a, 0x6200 | a->f1E);
    }
}

/* QUARANTINED — sub_0800EAA0 (1004b) — MISMATCH after ~12 iterations.
 * The full control-flow transcription above is believed correct
 * (verified block-by-block against asm/rom_0800EAA0.s):
 *  - prologue pushes, p4A local (r10) with two-statement init
 *    (`p4A = a; p4A += 0x4A;` — matches target adds r0,r6,#0/adds r0,#0x4A
 *    shape when not CSE-folded),
 *  - for(;;) loop = the `b _0800EACA` tail-loop; f48 check + KEYINPUT
 *    u16 read & 0xFC; switch (a->f18) with cases 0/1/2/0xD0/0xD1/default
 *    (GCC emits the target's binary switch tree),
 *  - case 0: two channel scans over 0x04000120-based regs; the peeled
 *    k=3 iteration (asrs #3, 0x7208 literal) + k=2..1 loop with
 *    exit-on-mismatch; f1D/f1E updates; f4A==0 && f1D!=f1E -> EED8 ->
 *    jump into case 1 (goto case1 = target `bl sub_0800EED8; b _0800EC28`),
 *  - case 1: f49 channel scan vs 0x72xx, gUnk_0200048C[k-1] stores,
 *    f1D==f49 -> f18=2, return EE8C(a, 0x6100|f49);
 *  - case 2, 0xD0 (checksum sum 0x11 + f19[0..2] -> f14, 0x6400|sum),
 *    0xD1 (0x73 check, sub_08016E20, f18=0xE0/f16=0x190 or f4A=0x1E
 *    + 0x70), default (0x62-(f18>>1) compare, f18==0xC4 -> f1E=f49&0xE,
 *    f18=0), check49 tail (f49==0 -> 0x50; f18+=2; f28[f18-3/4]
 *    big-endian pair -> EE8C; f4B==1 -> F0D4 continue), common6200
 *    return EE8C(a, 0x6200|f1E).
 *
 * BLOCKER: the loop-top `a->f48` load+store address. Target computes
 * `adds r1,r6,#0; adds r1,#0x48` ONCE per iteration in caller-saved r1
 * (looks like reload materialization + reload inheritance across the
 * beq, no hoisting). Our GCC (fork) always CSEs the shared address into
 * a SET insn, hoists it to the loop preheader (confirmed by minimal
 * probes with/without nested loops), and since the pseudo then spans
 * the loop's calls it needs a callee-saved register; in the full
 * function all callee-saved are taken, so it gets a STACK slot
 * (`str r2,[sp]; ldr r3,[sp]` + `sub sp,#4`) — a guaranteed mismatch
 * that also shifts every later register assignment.
 * Tried: no local (plain a->f48 twice); u8 *p48 local with one- and
 * two-statement inits inside and outside the loop; conditional init
 * inside the if-block (GCC force-hoists it anyway); block-scoped
 * working locals (k/v/w/r5 per case) to free callee-saved regs.
 * The fork's patch (calls.c precompute_register_parameters, address
 * constants) does not cover loop-invariant address sets, so this is a
 * genuine old-GCC loop.c/cse behavior to work around at the source
 * level if anyone resumes; the probes in git history of this file show
 * the isolated repro.
 */
