/* sub_0800EEFC — QUARANTINED DRAFT (188 of 192 bytes match).
 *
 * EXACT remaining diff (4 bytes at 0x0800EFAA):
 *   target: movs r2, #0x7F / negs r2, r2 / adds r1, r2, #0 / orrs r0, r1
 *   ours:   movs r1, #0x7F / negs r1, r1 /                 orrs r0, r1
 * i.e. retail materializes -127 into scratch r2 and then emits a reg-reg
 * movsi copy (add r1, r2, #0) into the orrs operand; we synthesize directly
 * into r1. Everything else — prologue, ||/comma gate layout, jump table with
 * biased dispatch ((a5 << 24) + (4 << 24)) >> 24, case bodies, mask tail,
 * both stores — is byte-identical.
 *
 * What was swept for the tail constant (all fail to produce the r2+copy):
 *  - `| -0x7F` literal: GCC 2.95 folds (u8)(x | -127) to (x | 0x81) at tree
 *    level -> movs #0x81. Same for | ~0x7E, | 0xFFFFFF81, (s8)0x81 casts,
 *    and *(s8 *) store target.
 *  - u32 m = -0x7F local (blocks the fold, gives movs/negs) but synthesis
 *    lands directly in r1: tried with/without `u32 t = v << 1` first,
 *    `t |= m`, `m = -m` after `m = 0x7F`, `0 - 0x7F`, u32/s32 m.
 *  - register asm pins: m@r2 -> orrs r0, r2 (no copy); m@r2 + n@r1 with
 *    `n = m` -> pins elided, synthesis back into r1.
 *  - operand order `-0x7F | (v << 1)`: folds to 0x81 (and reorders).
 *  - assignment-expression operand `(v << 1) | (m = -0x7F)`: elided.
 * Hypothesis (unproven): the copy is a reload input-reload that only fires
 * when reload's scratch order picks r2; our pseudo structure always lets it
 * synthesize into the operand reg directly. Next lever if revisited: find a
 * source shape where force_reg'd const pseudo is homed r2 while the ior
 * operand pseudo is r1 (e.g. something keeping a second pseudo live), or
 * check whether retail used a wider-typed field store that hides the
 * truncation from fold-const.
 *
 * Everything else in this file is verified byte-true except that one idiom.
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
            u32 t = v << 1;
            u32 m = -0x7F;
            a1[0x1C] = t | m;
        }
        a1[0x18] = 0xD0;
    }
}
