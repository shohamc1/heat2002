/* sub_0800EEFC — SOLVED 2026-09-15 (wave 5e, J2): MATCH (194 bytes).
 * The canonical source now lives in src/sub_0800EEFC.c; this file kept for
 * the learning record.
 *
 * THE FIX for the last 4 bytes (the -127 copy idiom at 0x0800EFAA):
 *   target: movs r2,#0x7F / negs r2,r2 / adds r1,r2,#0 / orrs r0,r1
 * The winning tail shape (replacing `u32 t = v<<1; u32 m = -0x7F;
 * a1[0x1C] = t | m;`):
 *
 *     s32 t = v << 1;
 *     *(s8 *)(a1 + 0x1C) = t | -0x7F;
 *
 * Why it works (verified against matched sibling sub_08004944, which has the
 * same idiom from `extern s8 gUnk_0202524C; ... gUnk_0202524C = -1;`):
 *  - The SIGNED (s8) store keeps -0x7F negative through fold-const: the u8
 *    store folds (u8)(x | -127) -> x | 0x81 (movs #0x81); the s8 narrowing
 *    distributes as (s8)x | -127 — the constant stays negative, so the movsi
 *    synthesizer emits movs #0x7F + negs.
 *  - The QI-typed store makes reload treat the ior operand as a QI input on
 *    an unallocated REG_EQUIV const pseudo: reload emits the constant into a
 *    reload reg (r2) and a QI input-reload copy (adds r1, r2, #0) into the
 *    operand reg — the exact "materialize in scratch + copy" shape. The
 *    s32 temp is required: an inline `(v << 1)` folds back to 0x81.
 * Everything else was already byte-true (prologue, ||/comma gate, biased
 * jump-table switch, case bodies, mask tail, both stores).
 */
#include "global.h"

extern void sub_0800EA64(void *a1);

void sub_0800EEFC(u8 *a1, u32 a2, u32 a3, u8 a4, u8 a5)
{
    u32 v;
    u32 size;

    if (a1[0x18] != 0 || a1[0x1E] == 0 || a1[0x4A] != 0
        || (*(u32 *)(a1 + 0x20) = a2, size = (a3 + 0xF) & ~0xF, size - 0x100 > 0x0003FF00))
    {
        sub_0800EA64(a1);
    }
    else
    {
        *(u32 *)(a1 + 0x24) = a2 + size;
        switch (((a5 << 24) + (4 << 24)) >> 24)
        {
        case 0:
        case 1:
        case 2:
        case 3:
            v = (a4 << 3) | (3 - (s8)a5);
            break;
        case 4:
            v = a4 | 0x38;
            break;
        case 5:
        case 6:
        case 7:
        case 8:
            v = (a4 << 3) | ((s8)a5 - 1);
            break;
        }
        v &= 0x3F;
        {
            s32 t = v << 1;
            *(s8 *)(a1 + 0x1C) = t | -0x7F;
        }
        a1[0x18] = 0xD0;
    }
}
