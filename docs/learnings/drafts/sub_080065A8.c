/* DRAFT v3 -- 396 bytes = exact target size, MISMATCH only in register
 * allocation (verified: 198 instructions == target's 198, same opcodes,
 * only register names differ). Structure fully solved:
 *   - strlen: if (*p) do { wp++; len++; } while (*wp)  [non-rotated guard]
 *   - pad = (30 - len) / 2;  q = p + 1;
 *   - loop1: while (i < pad), body: v/idx from *gUnk_08365340, two stores
 *     gUnk_08332DC8[idx] / [idx+32], tail i++ then dst += 1
 *   - loop2: c = *p; if (c) do { ... dst+=1; i++; c=*q; q++; } while (c)
 *   - loop3: while (i < 32), tail i++ then dst += 1
 *   - idx as plain u32 INDEX (not pointer) is what fixes the size: cell
 *     pointer form spills the shared pseudo.
 *
 * Remaining: 6-scalar register permutation. Target homes
 * s->r4, i->r5, attr->r6, tile->r7, pad->r8, q->r9, cell->sl, dst->ip.
 * We home i->r4, pad->r5, q->r6, s->r7, tile->r8, attr->r9 (roughly the
 * reverse priority). attr always lands r9 with `movs r0,#240; lsls;
 * mov r9,r0` remat-copy; target computes in place `movs r6,#240;
 * lsls r6,r6,#8`.
 *
 * Tried without success (~60 variants): declaration orders (attr at every
 * position), init statement orders, attr as u16 / 0xF0<<8 / literal at use
 * sites / non-foldable (if-guarded), volatile on every scalar (spills),
 * i as u32, idx as u16, per-loop v/idx/cell temps (spills or CSE-merges),
 * block-scoped temps (spills), cell pointer + cell32 local (wrong second-
 * store addressing), dst via **extern, dst[i] vs *(dst+i), dst++ vs +=1,
 * for-loops, q=p+1 vs wp+1, s local vs param-direct, sub_08006950 sibling
 * idioms (**v, while((c=*p++))), separate loop2 walker local (correct
 * mov r4,r9 copy achieved but scalar order still wrong).
 *
 - greg/lreg dumps show allocation order [idx, r31, cell, tile, dst, pad,
 *  attr, q, cell2, s, i, ...] and reload reassigning; the six scalars end
 *  in nearly-reverse priority order vs target. Next: instrument global.c
 *  find_reg pass-0/regs_someone_prefers interplay, or hunt a source shape
 *  where s (5 refs) outscores i (13 refs) - e.g. use p twice more before
 *  loop1 so its live length shortens below i's.
 */
#include "global.h"

extern u16 gUnk_08332DC8[];
extern u16 gUnk_08333208[];
extern u16 *gUnk_08364B08;
extern u8 *gUnk_08365340;

void sub_080065A8(u8 *p)
{
    u8 *s = p;
    u16 *dst;
    u32 attr;
    u8 i;
    u8 *wp;
    s32 len;
    s32 pad;
    u8 *q;
    u8 c;
    u32 v;
    u32 idx;

    dst = gUnk_08364B08 + 32;
    attr = 0xF000;
    i = 0;
    wp = s;
    len = 0;
    if (*s != 0) {
        do {
            wp++;
            len++;
        } while (*wp != 0);
    }
    pad = (30 - len) / 2;
    q = s + 1;

    while (i < pad) {
        v = (*gUnk_08365340 - 0x20) << 24;
        idx = (((v >> 29) << 22) + 0x600000) / 0x10000 + ((v & 0x1F000000) >> 24);
        dst[0] = attr | gUnk_08333208[gUnk_08332DC8[idx]];
        dst[32] = attr | gUnk_08333208[gUnk_08332DC8[idx + 32]];
        i++;
        dst += 1;
    }

    c = *s;
    if (c != 0) {
        do {
            v = (c - 0x20) << 24;
            idx = (((v >> 29) << 22) + 0x600000) / 0x10000 + ((v & 0x1F000000) >> 24);
            dst[0] = attr | gUnk_08333208[gUnk_08332DC8[idx]];
            dst[32] = attr | gUnk_08333208[gUnk_08332DC8[idx + 32]];
            dst += 1;
            i++;
            c = *q;
            q++;
        } while (c != 0);
    }

    while (i < 32) {
        v = (*gUnk_08365340 - 0x20) << 24;
        idx = (((v >> 29) << 22) + 0x600000) / 0x10000 + ((v & 0x1F000000) >> 24);
        dst[0] = attr | gUnk_08333208[gUnk_08332DC8[idx]];
        dst[32] = attr | gUnk_08333208[gUnk_08332DC8[idx + 32]];
        i++;
        dst += 1;
    }
}
