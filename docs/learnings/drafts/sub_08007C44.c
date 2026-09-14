/*
 * sub_08007C44 — MISMATCH (700/700 bytes, register+slot allocation only).
 *
 * All instructions, pool contents AND pool order match. The remaining diff is
 * purely register/stack-slot assignment in the loop-entry region:
 *
 * TARGET:  xs->r0 (in place from px), ys->r2 (moved off py's r1),
 *          yBase->r2 (callee... caller-saved, saved to [sp,#52] across the
 *          sub_0800CBB8 call by caller-save), xBase SPILLED to [sp,#60],
 *          reload at EVERY use (x=xBase-1, xBase+2 recomputed per y-iter
 *          into r9, x==xBase reloads).  mask->r3 ([sp,#56] caller-save),
 *          0const->r4, &unk171->r3, &unk172->r5, count->r8, y->r5.
 * OURS:    xs->r2, ys->r1 (in place), yBase SPILLED to [sp,#60],
 *          xBase->r3 + stash [sp,#56] across call, mask->r2/[sp,#52].
 *          Extra 8 bytes: mov r8,r7 (&unk172), yBase+2 recomputed from spill
 *          twice; CSE folds xBase+2 to xs+3 (xs+3 = adds r2,#3) so xs stays
 *          live (global) and eats r2.
 *
 * Tried (all still MISMATCH):
 *  - decl order swaps (xBase/yBase, xs/ys, mask s32): inert.
 *  - px/py removal (B): xs in-place r0 OK but ys stays r0, yBase still spilled.
 *  - `volatile s32 xBase` + manual per-y-iter hoist `xl = xBase + 2` (keeps
 *    while-test cached in r9 like target, `x == xBase` reloads like target):
 *    structure right (696b) BUT volatile slot lands FIRST ([sp,#40] not #60)
 *    and ys->r1 not r2.  Volatile yBase: loop test reloads per-iter (wrong).
 *  - register pins: `yBase asm("r2")` sticks (asrs r2/adds r2) but GCC 2.95
 *    does NOT caller-save pinned regs across the bl -> r2 clobbered =
 *    miscompile.  Same for r3.
 *  - w/w2 dead-temp games: global alloc ignores block-local occupancy.
 *
 * Root cause (from -da RTL dumps): global-alloc priority contest.  In our
 * build pri(mask)=4*14/120=0.467 > pri(yBase)=3*10/83=0.362, so mask wins
 * r2, yBase loses and spills; in the target's build yBase won r2 and xBase
 * was the spill victim (slot #60, after caller-save slots #52/#56).  Need a
 * source shape where yBase's refs/live beat mask's, with xBase the spillee.
 * Qty tie-break by number is inert to declaration order here.
 */
#include "global.h"

struct Unk0202A550
{
    s32 unk0;
    s32 filler4;
    s32 unk8;
    u8 fillerC[0x170 - 0xC];
    u8 unk170;
    u8 unk171;
    u8 unk172;
    u8 unk173;
    u8 filler174;
    u8 unk175;
    u8 filler176[0x182 - 0x176];
    u16 unk182;
    u8 filler184[400 - 0x184];
};

extern struct Unk0202A550 gUnk_0202A550[];
extern u8 gUnk_0200215C;
extern u8 gUnk_020020CC;
extern u8 gUnk_020020DC;
extern u8 gUnk_0202EF90;
extern u8 gUnk_0202ED70;
extern u8 gUnk_0202EF00[];
extern u8 gUnk_020020E0;
extern u8 gUnk_020021E0;
extern u8 gUnk_02001FA0[];
extern u8 gUnk_02002030[];
extern u8 gUnk_02001FE0[];

extern void sub_0800930C(struct Unk0202A550 *p, u8 a);
extern u8 sub_0800CBB8(s32 x, s32 y);
extern void sub_08001208(u16 a);
extern u8 sub_080025FC(void);
extern void sub_080019B4(void *a);

void sub_08007C44(struct Unk0202A550 *work)
{
    u8 unused[40];
    u32 idx;
    s32 px;
    s32 py;
    s32 xs;
    s32 ys;
    s32 xBase;
    s32 yBase;
    s32 x;
    s32 y;
    u8 mask;
    u8 count;
    u8 flag;
    u8 result;

    work->unk170 = 0;
    work->unk173 = work->unk171;
    work->unk171 = 0;
    work->unk172 = 0;
    if (gUnk_0200215C == 4)
        return;
    if (gUnk_020020CC == 7)
        return;
    idx = 0;
    if (gUnk_020020DC != 0)
        idx = gUnk_0202EF90;
    px = work->unk0;
    py = work->unk8;
    xs = px >> 19;
    ys = py >> 19;
    yBase = ys + 2;
    xBase = xs + 1;
    work->unk170 = 0;
    work->unk171 = 0;
    work->unk172 = 0;
    count = 0;
    for (y = yBase - 1; y != yBase + 2; y++)
    {
        x = xBase - 1;
        if (x != xBase + 2)
        {
            mask = 1;
            do
            {
            result = sub_0800CBB8(x, y);
            if (result & mask)
                work->unk172 = mask;
            if ((u8)(result - 2) <= 1 && x == xBase && y == yBase)
                work->unk170 = mask;
            if ((u8)(result - 4) <= 1 && x == xBase && y == yBase)
                work->unk171 = mask;
            if (result == 6)
                count++;
            if ((u8)(result - 8) <= 1 && work->unk175 == 6)
                work->unk182 = 0;
            x++;
            } while (x != xBase + 2);
        }
    }
    if (count > 4 || (count != 0 && (gUnk_020020CC == 3 || gUnk_020020CC == 5
        || gUnk_020020CC == 8 || gUnk_020020CC == 0xB || gUnk_020020CC == 2)))
    {
        if (gUnk_020020DC == 0 && work == &gUnk_0202A550[0])
            sub_0800930C(work, 0);
    }
    flag = 0;
    if ((u8)(gUnk_0200215C - 0xF) <= 1 && gUnk_0202ED70 == 0xC)
        flag = 1;
    if (work == &gUnk_0202A550[idx] && work->unk171 != 0 && work->unk173 == 0
        && flag == 0 && gUnk_0202EF00[3] != 0 && gUnk_020020E0 == 0
        && gUnk_020021E0 == 0)
        sub_08001208(0x1C);
    if (work == &gUnk_0202A550[idx] && work->unk171 != 0
        && (sub_080025FC() & 0x1F) == 0 && gUnk_0202EF00[3] != 0
        && gUnk_020020E0 == 0 && gUnk_020021E0 == 0 && flag == 0)
        sub_08001208(0x1D);
    if (work == &gUnk_0202A550[idx] && (*(u32 *)&work->unk170 & 0xFF00FF00) == 0x10000000)
    {
        sub_080019B4(gUnk_02001FA0);
        sub_080019B4(gUnk_02002030);
        sub_080019B4(gUnk_02001FE0);
    }
    if (gUnk_0200215C == 0x10 && gUnk_0202ED70 == 0xC)
        work->unk171 = 0;
}
