/* sub_080112E0 (156 bytes @ 0x080112E0) -- MISMATCH after ~30 source variants.
 * Structure fully solved (both loops, exact instruction sequence modulo
 * register names); remaining diff is a pairwise register permutation:
 *
 *   target: i(r5) p(r6) swapped(r7) | AC->sl, EFC0->r9, off(0x16C)->ip,
 *           inner-loop AC copy: r8 (=sl), 0x16C remat `movs r2,#0xB6;
 *           lsls r2,#1; mov ip,r2` placed AFTER the `n != 1` guard.
 *   ours:   i(r6) p(r5) swapped(r7) | AC->r9, EFC0->sl, off->r8 hoisted
 *           OUTSIDE the outer loop (before the AC read), AC copy: ip (=r9).
 *
 * The three pairwise swaps:
 *   1. high homes AC<->EFC0 (sl<->r9): every declaration order of
 *      locals/cast-locals tried (both orders, pointer vs u32-cast vs
 *      direct-global, 2- and 3-local combos) yields either AC->r9 or
 *      EFC0->sl, never both target assignments together.
 *   2. low homes i<->p (r5<->r6): invariant across declaration order.
 *   3. off local: plain `u32 off = 0x16C` gives swapped->ip + off->r8 with
 *      the remat hoisted above the guard; the sub_080078E4 idiom
 *      (`u32 one = 1` -> `mov r0,#1; mov ip,r0`) shows ip materialization
 *      is reachable, but not inside the guarded region here.
 *
 * Shapes tried: for/while/do-while inner and outer, != and < conditions,
 * a/b as block vs function scope, ka/kb compare temps, off as local,
 * cast-local, function-scope assignment; volatile gUnk_080020AC and
 * volatile-cast; two-locals ac/ac2 (guard read vs tail read); base-pointer
 * local for EFC0; declaration-order sweep of all 6 permutations of
 * {i, p, swapped}; nested if(n!=1) guard with do-while; register asm()
 * hints (degrade codegen with extra lsls/lsrs).
 */
#include "global.h"

extern u8 gUnk_020020AC;
extern u32 gUnk_0202EFC0[];
extern u8 gUnk_0202A550[][0x190];

void sub_080112E0(void)
{
    u8 i;
    u32 swapped;

    for (i = 0; i != gUnk_020020AC; i++)
        gUnk_0202EFC0[i] = (u32)&gUnk_0202A550[i][0];

    do {
        u32 *p = gUnk_0202EFC0;
        u32 off = 0x16C;
        i = 0;
        swapped = 0;
        while (i != (u32)gUnk_020020AC - 1) {
            u32 a = p[0];
            u32 b = p[1];
            if (*(u32 *)(a + off) > *(u32 *)(b + off)) {
                p[0] = b;
                p[1] = a;
                swapped = 1;
            }
            p++;
            i++;
        }
    } while (swapped);
}
