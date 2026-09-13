/* QUARANTINE DRAFT — does not match. Remaining diff vs ROM (2 insn-shape issues):
 *
 * ROM loop body:      ldrh r2,[r0]; adds r4,r2 (v-copy); movs r0,#31;
 *                     ands r2,r0 (x in v's reg); asrs r5,r4,#5 (y->r5);
 *                     ands r5,r0; asrs r4,r4,#10 (z reuses v's r4); ands r4,r0
 * this draft emits:   movs r2,#31; ands r2,r0 (x destroys mask scratch);
 *                     asrs r4,r0,#5; movs r1,#31 (2nd remat); ands r4,r1;
 *                     asrs r5,r0,#10; ands r5,r1  -> y/z regs swapped (r4<->r5),
 *                     no v-copy, mask rematerialized twice not once.
 * What is already right: prologue/order/i-in-r10/no spill/in-loop mask remat/
 *   asrs field shifts/*3/2 rounding (x needs split stmts x=x*3; x=x/2)/
 *   <<16 shifting/__divsi3 calls/loop tail/tail globals. Size 196 vs 200.
 * Swept: v u16 vs s32 (s32 required for asrs); mask literal vs user var
 *   u32 m=0x1F (user var required: m loses r10 to i only in `m & v` order);
 *   all 4 commutes of the ANDs; x=*src++ with v=x copy structure; y/z split
 *   divs; declaration orders. The `m & v` commute demotes m off r10 (i gets
 * r10, correct) but makes the ands DEST the mask scratch -> second remat and
 * y/z swap. The `v & m`/`x & m` commutes give the right dest shape but m then
 * WINS r10 and i spills to [sp]. Next lever: find a source where operand0 is
 * the value AND m still loses the register — e.g. more/fewer live pseudos
 * around the extraction block (local-alloc 3-qty buggy sort is in play).
 */
#include "global.h"

extern s32 gUnk_02022E20[];
extern s32 gUnk_02023A20[];
extern u16 gUnk_02022E18;
extern u8 gUnk_02022E14;

void sub_08004018(s32 arg0, u16 *src)
{
    s32 *base;
    s32 *out;
    u32 m = 0x1F;
    s32 i;
    s32 v;
    s32 x, y, z;

    i = 0;
    base = gUnk_02022E20;
    out = gUnk_02023A20;
    do {
        v = *src++;
        x = m & v;
        y = m & (v >> 5);
        z = m & (v >> 10);
        x = x * 3;
        x = x / 2;
        if (x > 31)
            x = 31;
        y = y * 3 / 2;
        if (y > 31)
            y = 31;
        z = z * 3 / 2;
        if (z > 31)
            z = 31;
        x <<= 16;
        y <<= 16;
        z <<= 16;
        out[0] = (x - base[0]) / arg0;
        out[1] = (y - base[1]) / arg0;
        out[2] = (z - base[2]) / arg0;
        base += 3;
        out += 3;
        i++;
    } while (i != 256);

    gUnk_02022E18 = arg0;
    gUnk_02022E14 = 1;
}
