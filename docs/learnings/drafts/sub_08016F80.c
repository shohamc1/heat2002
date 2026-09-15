/* QUARANTINE DRAFT -- does not match (124 vs 124 bytes; target pool sits 4B later).
 * Solved by this round vs the old draft: size now exact; the three old blockers
 * (DISPCNT ands dest, guard [r1] folding, spin-loop CSE) are gone.
 * Remaining diff (fresh-verified 2026-09-15):
 *   0x8016fb6: target materialises the 0x8000 constant FIRST (movs r2,#0x80;
 *   lsls r2,#8; adds r0,r2,#0) then does `ldrh r1,[r1,#0]`; ours loads first.
 *   -> the guard global wants the volatile lever at this site (memory-after-
 *   constant = plain, constant-after-memory = volatile per CLAUDE.md). All
 *   pool offsets shift -4 as a consequence of the one reorder.
 * The rest of the instruction stream matches. Old 120B draft replaced by this
 * closer state.
 */

#include "global.h"

extern u32 gUnk_0202F240;
extern volatile u32 gUnk_040000D4[];
extern volatile u32 gUnk_040000D8;
extern volatile u16 gUnk_040000DC_16[];
extern volatile u16 gUnk_040000DE;

void sub_08016F80(u32 src, u32 dst, u16 cnt)
{
    u16 saved;
    volatile u16 *disp;
    register volatile u16 *p asm("r1");
    register u16 v asm("r4");

    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    disp = (volatile u16 *)0x04000204;
    v = *disp;
    v &= 0xF8FF;
    *disp = ((u16 *)gUnk_0202F240)[3] | v;
    gUnk_040000D4[0] = src;
    gUnk_040000D8 = dst;
    p = gUnk_040000DC_16;
    *(volatile u32 *)p = 0x80000000 | cnt;
    p++;
    if (0x8000 & *p) {
        do { } while (gUnk_040000DE & 0x8000);
    }
    *(volatile u16 *)0x04000208 = saved;
}
