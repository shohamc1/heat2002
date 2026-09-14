/*
 * sub_08016ED8 — QUARANTINED wave 5e (2026-09-15, J2 re-verified).
 * Fresh verification (rm .o; make .o; match.py): MISMATCH, 100 bytes,
 * exactly one cluster of 4 register-swapped instructions at 0x08016eea:
 *   target: ldrb r1,[r1,#0] / movs r2,#8 / lsls r2,r1 / ldrh r1,[r4,#0]
 *   ours:   ldrb r2,[r1,#0] / movs r1,#8 / lsls r1,r2 / ldrh r2,[r4,#0]
 * (the (1<<bit) mask chain is homed in r2 in target vs r1 in ours, then
 * orrs r1,r2 consumes it; everything else byte-exact).
 *
 * WAVE 5e CONFIRMED MECHANICS (lldb on old_agbcc, breakpoint at
 * qty_compare_1 0x100149c60, dereferencing the heap qty_* arrays —
 * dump tables live there, dump_local_alloc is AFTER the arrays are freed):
 *  - local-alloc PRI = floor_log2(nrefs)*nrefs*qty_size*10000/(death-birth).
 *  - Live qty table for the current source: qty8 = the const-8 CHAIN pseudo
 *    (movs#8;lsls — it is one pseudo: movsi set(1) + ashift out+in(2) +
 *    ior out+in(2) + strh in(1) = nrefs 6, birth 22 death 30, PRI 15000).
 *    qty7 = the ldrb byte pseudo (QImode, nrefs 2, [20..24], PRI 5000).
 *    Const chain always allocated first -> takes r1 (free after the 94-addr
 *    dies at ldrb), byte pushed to r2. Byte CANNOT win PRI: nrefs would need
 *    4 (impossible: it appears in exactly 2 insns) or the chain's span would
 *    need >24 units (its death is the strh — no later use exists).
 *  - The thumb 2-operand lsls/orrs patterns ("=l,l"/"l,0" constraints) FORCE
 *    the const->shift->ior->store into ONE chained pseudo; any attempt to
 *    split const from result (user var m, comma exprs, casts) either folds,
 *    adds a copy insn, or reorders the movs before the volatile ldrb.
 *  - WHY THE MATCHED SIBLING sub_08016F3C (`REG &= ~(8 << gUnk_02000494)`)
 *    GETS THE FLIP: the BICS form SPLITS the mask chain from the value
 *    chain — mask qty nrefs 4/[30..36] PRI 13333, value chain (ldrh->bics->
 *    strh) nrefs 4/[34..38] PRI 20000. The value chain takes r0 FIRST, the
 *    mask chain then takes r1, and the byte qty [28..32] (no overlap with
 *    the value chain) still gets r0's freed slot via the 94-addr reuse:
 *    ldr r0,=94 / ldrb r0,[r0] / movs r1,#8 / lsls r1,r0. The |= form
 *    cannot split (thumb orrs chains op0=op1=op2), so this path is closed
 *    for the |= at 0x04000200.
 * Ruled out this wave: 8*(1<<x), 2*(4<<x), 4*(2<<x) (combine normalizes to
 * identical RTL/qty table), (u32) cast on shift operand, |= vs = (mask |
 * REG) forms, u32/u16/s32 temp x = gUnk_02000494 (load stays QImode — no
 * zero_extendqisi2 pattern exists in this port, so the byte pseudo can
 * never reach qty_size/nrefs parity), late-assigned pointer local p94 =
 * &gUnk_02000494 (wrong pool order, same r1/r2 swap).
 * NEXT LEVER if revisited: find a source shape whose RTL puts a THIRD
 * high-PRI pseudo (like F3C's value chain) live across [movs..strh] so it
 * takes r1 first, e.g. an extra simultaneously-live u32 in that window
 * without adding insns — none is known. Or verify via lldb which qty table
 * the retail compiler would have needed (byte PRI must exceed 15000).
 */

#include "global.h"

extern u16 gUnk_020004A0;
extern volatile u8 gUnk_02000494;
extern u8 gUnk_02000498;
extern u16 gUnk_02000496;
extern u16 *volatile gUnk_0200049C;
void sub_08016ED8(u16 *a)
{
    u16 *p;

    gUnk_020004A0 = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000200 |= 8 << gUnk_02000494;
    *(volatile u16 *)0x04000208 = 1;
    gUnk_02000498 = 0;
    gUnk_02000496 = *a++;
    p = gUnk_0200049C;
    *p = *a;
    p++;
    gUnk_0200049C = p;
    *p = a[1];
    p--;
    gUnk_0200049C = p;
}

/* Earlier wave-5d notes (still valid):
 * `a` (param) lives in r0 across the whole prologue in both, so the free
 * pool is {r1,r2}. Swept: volatile/non-volatile extern for gUnk_02000494
 *   (non-volatile hoists `movs #8` ahead of the ldrb — wrong order,
 *    though it then reuses the address reg: ldrb r2,[r2]);
 * *(volatile u8 *)0x02000494 cast; volatile-qualified access of a
 * non-volatile extern; u8/u16/s32/s8 temp locals (each shifts the early
 * REG_208 address reg r3->r4 and breaks the matching prologue);
 * extern volatile u8 gUnk_02000490[] + [4] indexing (gives ldrb r2,[r1,#4]
 * with a 0x02000490 pool entry — wrong bytes); volatile u8 *q pointer
 * local (pushes an extra callee-saved reg).
 */
