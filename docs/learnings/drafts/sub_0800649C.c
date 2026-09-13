#include "global.h"

extern u16 *gUnk_08364B08;
extern u16 gUnk_08335A8C[];
extern u16 gUnk_0833553C[];

void sub_0800649C(u8 *str, u32 x, u32 y)
{
    u16 *dest;
    u32 color;
    u32 c;
    u32 v;

    dest = gUnk_08364B08;
    dest += (y << 5) + x;
    color = 0xE0 << 8;
    c = *str++;
    while (c != 0) {
        if (c == 0x20)
            v = 0x47;
        else {
            v = color;
            v |= gUnk_08335A8C[gUnk_0833553C[(u8)(c - 0x21)]];
        }
        *dest++ = v;
        c = *str++;
    }
}
/* MISMATCH (92B, 19/92 bytes differ; size exact). sub_0800649C:
 * Everything matches except the joined value register: target keeps the
 * if/else phi value in r0 (movs r0,#0x47; strh r0), ours in r1. Prologue,
 * pool [B08, A8C, 553C], ldr r5/r2 order, lookup chain, loop shape all match.
 * Root cause (via -dl/-dg dumps): pseudo 28 (v) is born at the `v = 0x47` mov
 * in BB2 before the branch; c is live in r0 across BB3 entry, so global-alloc
 * conflict list "28 conflicts: ... 0 13" excludes r0. The goto form
 * (v=lookup; goto store; space: v=0x47; store:) gets the EXACT target
 * register pattern in BB3/BB4/BB5 (r0 join, orrs r0,r6, movhi 71 -> r0) but
 * then dest takes r1 and str stays r3 (adds r1,r4 / ldrb [r3]) - 19 bytes too.
 * Tried: chain/idx-local/u16/u32/compound/commuted OR, ternary (both polarities),
 * default-0x47 (88B, jump-threaded), two-stores (96B), block-scoped v,
 * decl-order permutations, hoisted pointer locals, in-loop pointer locals,
 * dest via u32 cast, dest[i] indexing, do-while, s8/u8 c. All 92B forms
 * settle at 19- or 22-byte diffs. Suspect the original had `if (c != 0x20)`
 * with the lookup in the THEN arm and the 0x47 store in a separate else block
 * whose mov got scheduled after the cmp (cmp-first RTL) - reachable only if
 * v is born AFTER the compare. cmpfirst/if-if forms do this but then color
 * gets bumped to r7 (push {r4..r7}) and dest to r3, also 19 bytes off.
 * Remaining diff in best (a-variant): lsls r1/adds r1/adds r1,r6/ldrh r1/
 * orrs r1 vs target r0 throughout the join.
 */
