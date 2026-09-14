/* QUARANTINED — sub_08008AB0 (target 228b incl. trailing data; match.py target = 132b code).
 * Best draft compiles to 132b with IDENTICAL control flow and block layout; only the
 * register allocation differs:
 *   target: i->r4, base->r12 (head) / r6+r12 (inner), 2i kept in r7 across the body,
 *           store RECOMPUTES 25i from r7(2i)+r4(i), i+1 in r8.
 *   ours:   i->r1 (killed in place by i+1), base->r7, the head's 400i product is kept
 *           live across the bl into r6 and reused by the store.
 * Root cause: our GCSE unifies the check's gUnk[i] address chain (2i/3i/24i/25i/400i)
 * with the store's, so the whole product survives the call and i dies early. The retail
 * build instead only hoists the first chain insn (2i) into the retry-loop preheader.
 * Swept without success: continue vs nested-if vs manual for(;;)+i++/break (identical
 * output), do-while nesting (152b, extra guards), register asm("r4") pin (140b, adds a
 * top loop guard), byte-cast *(u8*)((u32)gUnk + i*400 + 0x162) on check and/or store
 * (128b), commuted & / != 0x63 / commuted loop bound, locals reordered (i last), base
 * pointer local (108b). Next lever to try: something that keeps i live across the call
 * so global alloc gives it r4 — e.g. referencing i after the store, or breaking the
 * GCSE hash between the two address chains. */
#include "global.h"

struct Unk0202A550
{
    u8 filler0[0x162];
    u8 unk162;
    u8 filler163[400 - 0x163];
};

extern struct Unk0202A550 gUnk_0202A550[];

extern u8 sub_080025FC(void);

void sub_08008AB0(void)
{
    u32 i;
    u8 v;
    u8 dup;
    u8 j;

    for (i = 1; i != 0x18; i++)
    {
        if (gUnk_0202A550[i].unk162 != 99)
            continue;
        for (;;)
        {
            v = 0x1F & sub_080025FC();
            if (v > 0x1D)
                continue;
            dup = 0;
            j = 0;
            do
            {
                if (v == gUnk_0202A550[j].unk162)
                    dup = 1;
                j++;
            } while (j != 0x18);
            if (dup != 0)
                continue;
            gUnk_0202A550[i].unk162 = v;
            break;
        }
    }
}
