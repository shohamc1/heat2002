/* DRAFT -- does not match. 376 bytes against a 396-byte target.
 *
 * Centres a string in a 32-column row and writes two tile-map rows per
 * character: pad left with *gUnk_08365340, draw the string, pad to 32.
 * gUnk_08332DC8 maps a character to its cell, gUnk_08333208 the cell to a
 * tile, and 0xF000 is the palette/priority bits.
 *
 * What is solved: the index arithmetic. The ROM works in a shifted domain
 * (`<<22`, add 0x600000, `>>16` instead of `<<6`, add 0x60), and the
 * character mask likewise stays shifted (`& 0x1F000000`, `>>24`). Writing
 * it that way took 444 bytes down to 376.
 *
 * What is left: register pressure. The ROM saves r8, r9 and r10 and keeps
 * all three table bases plus `pad` in high registers across the loops;
 * this draft saves only r8 and r9 and rematerialises one base per loop,
 * which is the whole 20-byte gap. Try naming the bases as locals before
 * the first loop so they are live across all three.
 */
#include "global.h"

extern u16 gUnk_08332DC8[];  /* 0x08332DC8 */
extern u16 gUnk_08333208[];  /* 0x08333208 */
extern u16 *gUnk_08364B08;   /* 0x08364B08 */
extern u8 *gUnk_08365340;    /* 0x08365340 */

void sub_080065A8(u8 *s)
{
    u16 *dst;
    u8 *p;
    s32 len;
    s32 pad;
    u8 i;
    u32 v;
    u16 *cell;

    dst = gUnk_08364B08 + 32;
    i = 0;
    p = s;
    len = 0;
    if (*s != 0) {
        do {
            p++;
            len++;
        } while (*p != 0);
    }
    pad = (30 - len) / 2;

    while (i < pad) {
        v = (*gUnk_08365340 - 0x20) << 24;
        cell = &gUnk_08332DC8[(((v >> 29) << 22) + 0x600000) / 0x10000 + ((v & 0x1F000000) >> 24)];
        dst[0] = 0xF000 | gUnk_08333208[cell[0]];
        dst[32] = 0xF000 | gUnk_08333208[cell[32]];
        i++;
        dst += 1;
    }

    for (p = s; *p != 0; p++) {
        v = (*p - 0x20) << 24;
        cell = &gUnk_08332DC8[(((v >> 29) << 22) + 0x600000) / 0x10000 + ((v & 0x1F000000) >> 24)];
        dst[0] = 0xF000 | gUnk_08333208[cell[0]];
        dst[32] = 0xF000 | gUnk_08333208[cell[32]];
        dst += 1;
        i++;
    }

    while (i < 32) {
        v = (*gUnk_08365340 - 0x20) << 24;
        cell = &gUnk_08332DC8[(((v >> 29) << 22) + 0x600000) / 0x10000 + ((v & 0x1F000000) >> 24)];
        dst[0] = 0xF000 | gUnk_08333208[cell[0]];
        dst[32] = 0xF000 | gUnk_08333208[cell[32]];
        i++;
        dst += 1;
    }
}
