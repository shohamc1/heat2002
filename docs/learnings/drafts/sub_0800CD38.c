/*
 * sub_0800CD38 quarantine notes (2026-09-14, F4 + retry wave)
 * Best build: 572/580 bytes (this file: s32 return + original pins).
 * SOLVED since last quarantine:
 *  - Epilogue: ROM has `pop {r1}; bx r1` — thumb_exit() picks ARG_2 for ANY
 *    function whose return size <= 4. Return type must be s32/u32, not void.
 *  - p0y reload hunk (was #2) already fixed in this state.
 * Remaining diffs (4 classes, all one allocation web):
 *  a. g480 pool ldr is 2 insns LATE (after `mov sl,r0`); ROM loads &g480
 *     BEFORE the dz computation.
 *  b. cross lands r7 (collides with a=r7 pin!); ROM has cross=r6. NOTE:
 *     GCC 2.95 local register variables DO NOT create alloc conflicts —
 *     with a pinned r7, local-alloc also gave cross r7, so our build's
 *     first __divsi3 divides by `a`, not cross (silent miscompile class).
 *  c. 488/484 stores: we hold ONE CSE'd address pseudo in r4 across the
 *     div call; ROM reloads the pool address PER STORE (2 ldrs of the same
 *     pool entry for each global).
 *  d. a4-fill: ROM reloads a4 ([sp,#0x1C]) before each field store and
 *     copies wall `mov r0,r8`/`mov r2,r8` twice; we hold one copy of each.
 *
 * MECHANISM (verified against agbcc source + experiments):
 *  - Every global store creates an address pseudo at expand (expr.c:4802
 *    change_address -> memory_address -> force_reg) with (set P (symbol_ref)).
 *  - cse.c invalidate_for_call() only invalidates HARD regs; pseudo constant
 *    entries survive calls, so CSE unifies both stores' pseudos -> nrefs=2
 *    pseudo -> wins callee-saved r4 -> single ldr (ours).
 *  - ROM shape = TWO nrefs=1 address pseudos (no CSE unify): priority
 *    floor_log2(1)*1*... = 0 -> never allocated a reg -> spilled with
 *    REG_EQUIV constant -> reload RE-MATERIALIZES `ldr rX,[pc]` per use.
 *    add_constant() dedups pool entries by rtx, so one entry, loaded twice.
 *  - `*(s32 *)0x02000488 = nx;` literal on 2nd store ONLY: reproduces the
 *    per-store reloads AND cross=r6, nx=r4, a4 per-store reloads (568B),
 *    but cascades: wall falls to r7 (ROM keeps r8 + mov copies), t gets
 *    spilled around the first store, inner loop strength-reduces cur1 into
 *    r8 (`movs r0,#24; add r8,r0`), j moves to [sp,#0x34]. Net -12B.
 *  - Literal casts on ALL FOUR stores: CSE folds 0x02000484 = 0x02000488-4
 *    (`ldr r4,pool; subs r4,#4`) — wrong shape, 556B.
 *  - Literal on 1st store + extern 2nd: same cascade class, 564B.
 *  - Folding dz into the store RHS (`g480 = (cross = (dz = z1-z0)*...)`)
 *    and `pg=&g480` BEFORE dz + `*pg=` store both hoist the &g480 ldr
 *    correctly BUT rotate early allocation (next r4->r5, wall-copy r6->r2,
 *    dz scratch r0->r5). 580B size, wrong regs everywhere.
 *  - `register struct Wall *w asm("r8")` pin: every wall use emits its own
 *    `mov rX,r8` copy (612B). ROM copies only at region boundaries.
 *  - Unpinning a/b (natural alloc): whole frame restructures (0x4C frame,
 *    wall=r7 from function start, t spilled, 548-560B). The pins ARE
 *    load-bearing for the outer loop; they only misbehave for cross.
 * NEXT LEVERS if revisited:
 *  - Find a source form that yields two nrefs=1 symbol_ref address pseudos
 *    with the SAME symbol_ref rtx (CSE must not unify): e.g. both stores
 *    through one extern but with CSE blocked structurally between them
 *    (the bhi continue-check sits AFTER both stores in ROM, so no EBB break
 *    available), or make the 1st store's pseudo die before CSE records it.
 *  - sub_0800D124 (next function, asm/rom_0800CD38.s:575+) shows the SAME
 *    double-load idiom for 0x02000488/0x02000484 — matching it first may
 *    reveal the original source convention shared by both.
 * Pins used: z0=r12, dz=r10, dx16=r9, a=r7, b=r5 (all assignment-exprs).
 */
#include "global.h"

struct Wall {
    u16 unk00;
    u16 unk02;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
};

struct Pt {
    s32 unk00;
    s32 unk04;
};
struct Corner {
    s16 v[8];
    s32 unk10;
    s32 unk14;
};

struct Box {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
};

struct Result {
    u8 pad00[4];
    s32 unk04;
    s32 unk08;
    u8 unk0C;
    u8 unk0D;
    u8 unk0E;
    u8 unk0F;
    s32 unk10;
};

extern u8 *gUnk_0202CC40;
extern u8 *gUnk_0202CC44;
extern s32 gUnk_02000460;
extern s32 gUnk_02000464;
extern s32 gUnk_02000468;
extern s32 gUnk_0200046C;
extern s32 gUnk_02000470;
extern s32 gUnk_02000474;
extern s32 gUnk_02000478;
extern s32 gUnk_0200047C;
extern s32 gUnk_02000480;
extern s32 gUnk_02000484;
extern s32 gUnk_02000488;

s32 sub_0800CD38(struct Corner *a1, struct Box *a2, struct Box *a3,
                 struct Result *a4, u16 *a5, s32 *a6)
{
    u8 unused[0x10];
    s32 p0x, p0y, p1x, p1y;
    struct Corner *cur1;
    struct Box *cur3;
    s32 j;
    u16 *list;
    u16 *next;
    struct Wall *w;
    struct Pt *pts;
    register s32 z0 asm("r12");
    s32 x0, z1, x1;
    register s32 dz asm("r10");
    register s32 dx16 asm("r9");
    register s32 a asm("r7");
    register s32 b asm("r5");
    s32 cross, t;
    s32 *pg;
    s32 nx, val;
    s32 v1;
    s32 v2;

    for (list = a5; *list != 0xFFFF; list = next) {
        w = (struct Wall *)(gUnk_0202CC40 + (*list << 5));
        v1 = a2->unk00;
        v2 = w->unk10;
        next = list + 1;
        if (v1 > v2 || a2->unk08 > w->unk18
            || a2->unk04 < w->unk0C || a2->unk0C < w->unk14)
            continue;
        pts = (struct Pt *)gUnk_0202CC44;
        p0x = pts[w->unk00].unk00;
        p0y = pts[w->unk00].unk04;
        p1x = pts[w->unk02].unk00;
        p1y = pts[w->unk02].unk04;
        cur1 = a1;
        cur3 = a3;
        for (j = 0; j != 4; j++, cur1++, cur3++) {
            if (cur3->unk00 > w->unk10 + 1 || cur3->unk08 > w->unk18 + 1
                || cur3->unk04 < w->unk0C - 1 || cur3->unk0C < w->unk14 - 1)
                continue;
            if ((cur1->unk10 >> 8) * w->unk04 + (cur1->unk14 >> 8) * w->unk08 > 0)
                continue;
            gUnk_02000470 = p0x;
            gUnk_02000474 = p0y;
            gUnk_02000478 = p1x;
            gUnk_0200047C = p1y;
            gUnk_02000460 = (z0 = cur1->v[1]);
            gUnk_02000464 = (x0 = cur1->v[3]);
            gUnk_02000468 = (z1 = cur1->v[5]);
            gUnk_0200046C = (x1 = cur1->v[7]);
            dz = z1 - z0;
            pg = &gUnk_02000480;
            gUnk_02000480 = (cross = dz * (p1y - p0y) - (dx16 = x1 - x0) * (p1x - p0x));
            if (cross == 0)
                continue;
            t = ((a = x0 - p0y) * (p1x - p0x) - (b = z0 - p0x) * (p1y - p0y)) << 8;
            gUnk_02000488 = t;
            nx = t / cross;
            gUnk_02000488 = nx;
            if ((u32)nx > 0x100)
                continue;
            t = (dz * a - dx16 * b) << 8;
            gUnk_02000484 = t;
            val = t / cross;
            gUnk_02000484 = val;
            if ((u32)val > 0x100)
                continue;
            if (nx < *a6) {
                *a6 = val;
                a4->unk04 = w->unk04 * 260 >> 8;
                a4->unk08 = w->unk08 * 260 >> 8;
                a4->unk0D = w->unk1C;
                a4->unk0E = w->unk1D;
                a4->unk0F = w->unk1E;
                a4->unk10 = *list;
                a4->unk0C = j;
            }
        }
    }
}
