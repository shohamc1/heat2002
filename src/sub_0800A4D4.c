/*
 * sub_0800A4D4 -- SOLVED: MATCH, 230 bytes @ 0x0800A4D4 (2026-09-24, second
 * attempt; 232-byte window = 230 code + 2 linker pad bytes). Campaign notes,
 * ordered by which wall each lever closed:
 *
 *  1. `e = e + 1` in the else arm (ONE pointer variable, not b = e + 1 with a
 *     second local). With a second local, cse's path reprocessing (cse_main's
 *     TAKEN->NOT_TAKEN path evolution; the reprocess block runs from the
 *     function start through the fallthrough arm) hoists the +24 above the
 *     branch -- a speculated if/else -- and store-forwards p->unk00/p->unk08
 *     into the dx/dy subtraction (keeps two extra values alive, push grows to
 *     {r4,r5,r6,r7}). e = e + 1 cannot be hoisted above the e->unk10 test, so
 *     the branchy if/else, the real ldr [r4,#0/8] reloads and push {r4,r5,lr}
 *     all fall out. -O1 gives the branchy shape for both spellings; this
 *     separates -O2's cse path following.
 *
 *  2. gTrackSegs declared `struct TrackSeg * volatile` (pointer OBJECT
 *     volatile): every read re-derefs, which the ROM shows three times (top,
 *     if-arm, tail with its own pool word at 0x0800A5A8). A plain decl
 *     forward-stores the base value across the struct stores (cse's
 *     symbol-keyed entries are never invalidated by mem/s stores -- verified
 *     with minimal testcases) and the if-arm degenerates to `adds rX, rY`
 *     (that is UpdateLapProgress's real ROM shape, not this one's).
 *
 *  3. `pt`, a register struct TrackSeg * volatile * pt asm("r0") initialized at
 *     the top ONLY. cse never records a pool-load set whose destination is a
 *     hard register, so the top read leaves NO table entry and the if-arm's
 *     `e = gTrackSegs` keeps its own fresh `ldr r0,[pc,#8]; ldr r2,[r0]`
 *     (sharing the top's pool word). Without the pin the arm ties to the
 *     top's address pseudo and reuses it (`ldr rX,[rY]`, one insn). Same
 *     trick as SioTransferIntr's r5/r4 pins ("cse never substitutes a hard
 *     register").
 *
 *  4. Mode byte (0x020020CC, read twice, first read's value discarded): pv is
 *     `register volatile u8 *pv asm("r5")` assigned from the soft `w = &...`;
 *     the copy `adds r5, r0, #0` survives because its destination is hard.
 *     w's liveness through reload is provided by the t3 load/store-back pair
 *     through w (MPlayFadeOut's dead write-back globalizer): reload_cse_regs_1
 *     deletes the store as a no-op after reload (same hard-reg address,
 *     unpromoted value), so the pair emits nothing but keeps w homed. The
 *     head read is volatile so delete_trivially_dead_insns keeps the dead
 *     ldrb; `m` (register u8 asm("r5"), disjoint range) puts the compare's
 *     value in the dying pv register: `ldrb r5,[r5]; cmp r5,#7`.
 *
 *  5. Tail: re-take the address through pt2 (register ... asm("r1"), block
 *     scope) so the pool load lands in r1 and pool-first order, and reuse e.
 *     ny is split into f4t (register, r0) / fCt / s so the ny loads take
 *     r0/r1 and the shift lands in ny's r1.
 *
 * Residual none. The permuter (output-90-1) supplied the nx/dx shuffle and
 * the register base; the last three register swaps were hand-pinned.
 */

#include "global.h"
#include "variables.h"

struct Car {
    s32 unk00;                          /* 0x00 */
    u8 pad04[0x08 - 0x04];
    s32 unk08;                          /* 0x08 */
    s32 unk0C;                          /* 0x0C */
    u8 pad10[0x14 - 0x10];
    s32 unk14;                          /* 0x14 */
    u8 pad18[0x34 - 0x18];
    u16 unk34;                          /* 0x34 */
    u16 respawnHeading;                          /* 0x36 */
    u16 respawnWaypoint;                          /* 0x38 */
    u8 pad3A[0x3C - 0x3A];
    u16 unk3C;                          /* 0x3C */
    u8 pad3E[0x4D - 0x3E];
    u8 unk4D;                           /* 0x4D */
    u8 unk4E;                           /* 0x4E */
    u8 pad4F[0x128 - 0x4F];
    s32 unk128;                         /* 0x128 */
    s32 steerHeading;                         /* 0x12C */
    s32 unk130;                         /* 0x130 */
    u8 pad134[0x13C - 0x134];
    s32 engineForce;                         /* 0x13C */
    u8 pad140[0x148 - 0x140];
    s32 unk148;                         /* 0x148 */
};

/* The 0x18-byte track segment record gTrackSegs points at; local
   twin of sub_08006A34.c's struct TrackSeg. It shares its old tag name
   with include/structs.h's 0x64-byte struct Track but not its layout or
   stride, so it keeps a local tag. The gTrackSegs extern
   (variables.h) is typed struct Track *; the casts on it below are
   pointer casts only and emit nothing. */
struct TrackSeg {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u16 unk10;
    u8 pad12[0x18 - 0x12];
};


s32 Atan2(s32 a, s32 b);

void sub_0800A4D4(struct Car *p)
{
    struct TrackSeg *e;
    register struct TrackSeg *volatile *pt asm("r0");
    register u8 m asm("r5");
    register s32 f4t asm("r0");
    s32 fCt;
    s32 s;
    s32 nx;
    register s32 ny asm("r1");
    s32 dx;
    s32 dy;
    register volatile u8 *pv asm("r5");
    u8 *w;
    u32 t3;
    u8 v;

    w = &gTrackId;
    pv = w;
    t3 = *(u32 *)w;
    *(u32 *)w = t3;
    v = *pv;
    pt = (struct TrackSeg *volatile *)&gTrackSegs;
    e = &(*pt)[p->respawnWaypoint];
    p->unk00 = (e->f0 + e->f8) << 15;
    p->unk08 = (e->f4 + e->fC) << 15;
    if (e->unk10 == 1) {
        e = (struct TrackSeg *)gTrackSegs;
    } else {
        e = e + 1;
    }
    dx = (e->f0 + e->f8) << 15;
    nx = dx;
    f4t = e->f4;
    fCt = e->fC;
    s = f4t + fCt;
    ny = s << 15;
    dx = nx - p->unk00;
    dy = ny - p->unk08;
    m = *pv;
    if (m != 7) {
        p->unk34 = -0x7C00 - (Atan2(dx >> 4, dy >> 4) << 8);
    } else {
        p->unk34 = p->respawnHeading;
    }
    p->unk3C = 0;
    p->engineForce = 0;
    p->unk148 = 0;
    p->unk0C = 0;
    p->unk14 = 0;
    p->steerHeading = p->unk34;
    p->unk128 = p->unk34;
    p->unk130 = 0;
    p->unk4E = 1;
    {
        register struct TrackSeg *volatile *pt2 asm("r1") = (struct TrackSeg *volatile *)&gTrackSegs;
        e = &(*pt2)[p->respawnWaypoint];
    }
    if (e->unk10 == 1) {
        p->unk4D = 0;
    } else {
        p->unk4D = p->respawnWaypoint + 1;
    }
}
