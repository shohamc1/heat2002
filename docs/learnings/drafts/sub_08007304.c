/* sub_08007304 (64 bytes @ 0x08007304) — MISMATCH, 12 of 64 bytes differ
 * (best shape below; was 22+ before). Progress this pass:
 *  - `register u32 f asm("r12") = 0xFFFF;` declared INSIDE the if-guard
 *    block, with the loop written as `i = 0; if (i != count) { ... do
 *    {...} while (i != count); }`, reproduces the target preheader exactly:
 *    `adds r5,r0 / movs r3,#0 / cmp r3,r5 / beq end / ldr r0,[pc] /
 *    mov ip,r0 / movs r4,#0 / ldr r6,[pc]` — the ip homing AND the
 *    init-after-guard placement are both correct in this shape.
 *  - The if-guard + do-while shape is also what places the zero-trip
 *    guard naturally (no for-loop guard scheduling).
 * Remaining diff (6 instructions):
 *   target: mov r7, ip / str r7,[r2,#8] ... ldrh r7,[r1] / lsls r0,r7,#5
 *   ours:   mov r0, ip / str r0,[r2,#8] ... ldrh r0,[r1] / lsls r0,r0,#5
 *  plus push {r4,r5,r6,r7} vs ours {r4,r5,r6} (r7 pushed iff the reload
 *  uses it). So everything reduces to reload1's choice of scratch register
 *  for the input reload of ip at the `str [r2,#8]`: order_regs_for_reload
 *  (reload1.c:1744) prefers unused caller-saved regs ascending, and r0 is
 *  unused/free at that insn in every shape tried, so we get r0. The target
 *  picked r7 => in the retail compile r0 was in bad_spill_regs there,
 *  i.e. SOME value (hard reg or pseudo in r0) was live across the first
 *  store of the loop body. The second ldrh cascades from the same choice
 *  (its qty takes whichever of r0/r7 the reload did not).
 * Natural-pressure route (no asm reg) analysed and confirmed partially:
 *  with f as a plain pseudo, f is the lowest-priority allocno (refs=3) and
 *  is allocated last; global.c find_reg pass 0 only considers
 *  regs_used_so_far (call_used + local-alloc'd) => for class HI_REGS the
 *  pass-0 candidate set is exactly {ip} (ip is call_used, r8-r11 are not),
 *  so f -> ip iff pass 1 over LO_REGS fails, i.e. iff ALL of r0-r7 are
 *  conflicted at f's turn. r0 (body qtys), r1 src, r2 e, r3 i, r4 zero,
 *  r5 count, r6 base give 7; the 8th (r7) needs one more loop-carried
 *  allocno that emits no instructions — the "9th live quantity". Every
 *  construct tried either emits extra instructions (dead stores survive
 *  to asm), gets CSE'd away, or is not a use for liveness ((void)t emits
 *  no RTL reference). volatile locals live in memory, not registers.
 * Swept this pass: plain f with for-loop, if-guard+do-while, asm r12 at
 *  function scope (init lands before the guard), asm r12 inside the
 *  if-guard (BEST), u16 vs u32 t, t declared in/outside the block.
 * Previous pass: constant local, volatile re-read with/without t local,
 * register asm("r12") hint with for-loop shape (got ip but init-order and
 * single-load wrong).
 * Next levers if revisited: find a C construct keeping a pseudo live in
 * r0 across the body's first store without emitting code (would fix the
 * reload choice), or an 8th low-reg-conflicting allocno for the natural
 * ip route (fixes reload AND t2 together, since the reload would then be
 * forced off r0 as well).
 */
#include "global.h"

struct unk_07304
{
    u32 f0;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u32 f8;
    u32 fC;
    u32 f10;
};

void sub_08007304(u32 count, volatile u16 *src, struct unk_07304 *e)
{
    u32 i;
    u32 t;

    i = 0;
    if (i != count)
    {
        register u32 f asm("r12") = 0xFFFF;
        do {
            e->f8 = f;
            e->f0 = 0;
            e->f4 = 0;
            e->f10 = *src;
            t = *src;
            e->fC = 0x06010000 + (t << 5);
            e->f6 = 0;
            i++;
            e++;
            src++;
        } while (i != count);
    }
}
