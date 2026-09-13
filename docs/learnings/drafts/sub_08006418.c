#include "global.h"

extern u16 *gUnk_08364B08;
extern u16 gUnk_0833553C[];
extern u16 gUnk_08335A8C[];

void sub_08006418(u8 *str, u32 y)
{
    u8 *p;
    u8 len;
    u8 pad;
    u16 *dest;
    u32 color;
    u32 c;
    u32 v;

    p = str;
    len = 0;
    c = *p;
    while (c != 0) {
        p++;
        len++;
        c = *p;
    }
    pad = (u8)((0x1E - len) / 2);
    dest = gUnk_08364B08;
    dest += (y << 5) + pad;
    color = 0xE0 << 8;
    c = *str++;
    while (c != 0) {
        if (c == 0x20)
            v = 0x47;
        else
            v = color | gUnk_08335A8C[gUnk_0833553C[(u8)(c - 0x21)]];
        *dest++ = v;
        c = *str++;
    }
}
/* MISMATCH (132B target; ours 130B - 2 short). sub_08006418:
 * Same family/idiom as sub_0800649C (see its draft header). The strlen
 * preamble, (0x1E-len)/2 padding, dest split-assign, and loop all match;
 * the join value register differs r1 vs r0 and the two arms' instruction
 * mix differs slightly (target: lookup inline then b to join, movs 0x47
 * at pool label). All variants tried mirror the 649C sweep; none matched.
 */
