#include "global.h"

struct Unk0202A550 {
    u8 filler0[0x164];
    u16 unk164;
    u8 filler166[400 - 0x166];
};

extern struct Unk0202A550 *gUnk_0202EFC0[];
extern struct Unk0202A550 gUnk_0202A550[];

void sub_08013AFC(void)
{
    u8 i;
    u8 j;
    u8 swapped;
    struct Unk0202A550 **p;
    struct Unk0202A550 *a;
    struct Unk0202A550 *b;
    u32 off;

    i = 0;
    do {
        gUnk_0202EFC0[i] = &gUnk_0202A550[i];
        i++;
    } while (i != 0x18);
    do {
        off = 0x164;
        j = 0;
        p = gUnk_0202EFC0;
        swapped = 0;
        do {
            a = p[0];
            b = p[1];
            if (*(u16 *)((u8 *)a + off) < *(u16 *)((u8 *)b + off)) {
                p[0] = b;
                p[1] = a;
                swapped = 1;
            }
            p++;
            j++;
        } while (j != 0x17);
    } while (swapped != 0);
}

/* QUARANTINED — sub_08013AFC (104b) — MISMATCH, one preheader block.
 * Loop 1 (fill gUnk_0202EFC0[i] = &gUnk_0202A550[i]) MATCHES byte-exact.
 * Loop 2 differs only in register allocation/order of the inner-loop
 * preheader:
 *
 *   target:                              ours:
 *   movs r7, #0        (swapped)         movs r7, #0xB2; lsls r7,r7,#1 (0x164)
 *   mov  r5, ip        (p)               movs r6, #0     (swapped)
 *   movs r2, #0        (j)               mov  r4, ip     (p)
 *   movs r6, #0xB2                       movs r5, #0     (j)
 *   lsls r6, r6, #1    (0x164, LAST)     [0x164 materialized FIRST, r7]
 *   ldr r4,[r5]; ldr r3,[r5,#4]          ldr r3,[r4]; ... (a=r3,b=r2 vs r4,r3)
 *
 * i.e. GCC hoists the loop-invariant 0x164 (field offset of unk164 in the
 * 400-byte car struct) to the TOP of the outer-loop body; target has it
 * after the swapped/p/j inits, with swapped in r7 and j in r2 (reused from
 * loop 1's i).
 *
 * Swept: 3 declaration orders; single reused loop counter for both loops
 * (flips loop-1 counter r2->r5: REG_N_REFS loop-depth weighting, breaks
 * loop 1); block-local a/b decls; reversed compare/swap operand order;
 * p[0]/p[1] direct indexing without a/b; s32/u32 swapped; explicit
 * `u32 off = 0x164` local placed before/after the inits (const still
 * materialized first in every variant).
 */
