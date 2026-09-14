/*
 * sub_0800E008 quarantine notes (2026-09-14, wave-5a crashed agent,
 * fresh-verified: rm .o; make .o; match.py) — MISMATCH, 225 diff lines,
 * object 532 bytes @ 0x0800E008. Instruction SHAPES are parallel to the
 * target almost everywhere; the residual diffs are:
 *
 *  1. Prologue: target saves r8 AND r9 (mov r7,r9; mov r6,r8; push
 *     {r6,r7}); ours saves only r9 (mov r7,r9; push {r7}). Target homes
 *     the hoisted `r5<<2` (gUnk_02000590 index) in r8 BEFORE the loop
 *     (lsls r3,r5,#2; mov r8,r3); ours recomputes it after the loop-set
 *     (lsls r7,r5,#2 at 0x800e068). Missing r8 use = missing save.
 *  2. 16-bit loop-counter increment order: target does
 *     adds r0,r4,#1; lsls r0,#16; lsrs r4,r0,#16 (add, then truncate);
 *     ours does lsls r0,r4,#16; lsrs r0,#16; adds r4,r0,#1 (truncate,
 *     then add). Same u8 idx variable, opposite expansion order.
 *  3. Every pool ldr offset differs (e.g. first: [pc,#328] vs [pc,#220])
 *     because the literal-pool order/layout differs downstream of the
 *     above — fix 1+2 first, the pool follows.
 *
 * Also: target materialises `adds r1,r2,#0` copies for the 0x2000 orrs;
 * ours matches those. Structure (nm[2] local, 0x96 gUnk_080000B2 check,
 * 2-iteration bl 0x8016E1C loop, gUnk_02000590/gUnk_083FDA50 setup,
 * second loop with bl 0x8016E0C + sub_0800E460 tail) all looks right.
 */
#include "global.h"

extern void sub_08016E1C(u32 a1, u32 a2);
extern void sub_08016E0C(u32 a1, u32 a2, u32 a3);
extern void sub_08016E30(void);
extern void sub_0800DE9C(u32 a1, u32 a2);
extern void sub_0800DE60(u32 a1, u32 a2);
extern void sub_08006950(u8 *a1, u32 a2, u32 a3);
extern void sub_0800E3C4(u32 a1, u32 a2);
extern u32 sub_0800E460(u32 *a1);
extern void sub_0800DFCC(void);

extern u8 gUnk_080000B2;
extern u32 gUnk_080000AC;
extern u32 gUnk_0807C9E8;
extern u32 gUnk_02000590[];
extern u32 gUnk_083FDA50[];
extern u32 gUnk_0807C9CC[];
extern u8 gUnk_0807C9F0[];
extern u8 gUnk_0807CA08[];
extern u8 gUnk_0807CA20[];
extern u8 gUnk_0807CA34[];
extern u8 gUnk_0807CB58[];
extern u32 gUnk_0202E960[];

u32 sub_0800E008(void)
{
    u32 nm[2];
    u8 idx;
    u32 i;
    register u32 idx4 __asm__("r8");
    register u32 shift __asm__("r7");
    register u32 *pn __asm__("r9");
    register u32 nxt __asm__("r6");

    nm[1] = 0;
    idx = 0;
    *(volatile u16 *)0x04000200 = 1;
    if (gUnk_080000B2 == 0x96 && gUnk_080000AC == gUnk_0807C9E8)
        *(volatile u16 *)0x04000200 |= 0x80 << 6;
    *(volatile u16 *)0x04000004 = 8;
    *(volatile u16 *)0x04000208 = 1;
    gUnk_02000590[1] = 0x0800DFC1;
    gUnk_02000590[0] = 0x0800E641;
    *(volatile u16 *)0x04000000 &= 0xEFFF;
    i = 0;
    idx4 = idx * 4;
    shift = idx << 15;
    pn = &nm[1];
    nxt = idx + 1;
    do {
        sub_08016E1C(gUnk_083FDA50[i], 0x06010000 + i * 0x200);
        i = (u16)i + 1;
    } while (i <= 2);
    *(volatile u32 *)0x040000D4 = (u32)gUnk_0807CB58;
    *(volatile u32 *)0x040000D8 = 0x05000200;
    *(volatile u32 *)0x040000DC = 0x84000028;
    *(volatile u32 *)0x040000DC;
    nm[0] = 0xA0;
    *(volatile u32 *)0x040000D4 = (u32)&nm[0];
    *(volatile u32 *)0x040000D8 = (u32)gUnk_0202E960;
    *(volatile u32 *)0x040000DC = 0x85000100;
    *(volatile u32 *)0x040000DC;
    sub_08016E0C((u32)gUnk_0202E960, 0x07000000, 0x100);
    *(volatile u16 *)0x04000000 |= 0x82 << 5;
    sub_0800E3C4(1, gUnk_0807C9CC[idx]);
    i = 0;
    do {
        sub_08006950(gUnk_0807C9F0, i + 8, 1);
        i = (u16)i + 1;
    } while (i <= 3);
    do {
        u8 v = (u8)((shift + nm[1] * 4) >> 10);

        sub_0800DE9C(v, 100);
        sub_0800DE60(v, 100);
        sub_08006950(gUnk_0807CA08, 8, 1);
        sub_08006950(gUnk_0807CA20, 9, 1);
        sub_08006950(gUnk_0807CA34, 10, 1);
        if (sub_0800E460(pn) != 0)
        {
            idx = nxt;
            if (idx == 7)
                break;
            sub_0800E3C4(1, gUnk_0807C9CC[idx]);
            nm[1] = 0;
            shift = idx << 15;
            nxt = idx + 1;
        }
        sub_08016E0C((u32)gUnk_0202E960, 0x07000000, 0x100);
        sub_08016E30();
    } while (1);
    nm[0] = 0xA0;
    *(volatile u32 *)0x040000D4 = (u32)&nm[0];
    *(volatile u32 *)0x040000D8 = (u32)gUnk_0202E960;
    *(volatile u32 *)0x040000DC = 0x85000100;
    *(volatile u32 *)0x040000DC;
    sub_08016E0C((u32)gUnk_0202E960, 0x07000000, 0x100);
    sub_0800DFCC();
    return 0;
}
