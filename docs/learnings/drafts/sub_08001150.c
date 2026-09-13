/* sub_08001150 (32 bytes @ 0x08001150) — MISMATCH after ~20 source variants.
 * Remaining diff (only 2 instructions, register allocation of the u16-narrowed
 * param vs the tag load):
 *   target: 08001154: lsrs r1, r1, #16      08001156: ldr r3, [r2, #0x34]
 *   ours:   08001154: lsrs r3, r1, #16      08001156: ldr r1, [r2, #0x34]
 * i.e. the narrowed u16 must stay in its incoming register r1 while the tag
 * load takes r3. Every C shape tried either (a) puts the narrowed value in a
 * fresh pseudo that grabs r3 (when the pointer copy `adds r2, r0` is emitted
 * first), or (b) narrows in place in r1 but then the pointer copy lands in r3
 * and the tag in r2 (when the tag load is scheduled before the narrowing).
 * The `u32 c = 0x80 << 1;` local fixed the tail (movs r0/lsls r0/strh r0
 * without the `adds r0, r1, #0` copy). Sweep tried: u16/u32/s16 params,
 * (void*) param, v/t/c/r2 locals in all declaration+assignment orders,
 * casts at use vs local copies, direct global compare vs tag local,
 * if/return vs if/body, volatile stores, struct-field access, store order
 * swap. This is the 3-quantity block case from parked.md's block_alloc note
 * (qty_order sort is non-monotonic); the next lever is shaping pseudo birth
 * order so the allocator's hand-rolled 3-qty sequence lands r1/r2/r3 as the
 * ROM has them.
 */
#include "global.h"

void sub_08001150(u32 r0, u32 r1)
{
    u32 r2 = r0;
    u16 v = r1;
    u32 t = *(u32 *)(r2 + 0x34);
    u32 c = 0x80 << 1;

    if (t == 0x68736D53)
    {
        *(u16 *)(r2 + 0x26) = v;
        *(u16 *)(r2 + 0x24) = v;
        *(u16 *)(r2 + 0x28) = c;
    }
}
