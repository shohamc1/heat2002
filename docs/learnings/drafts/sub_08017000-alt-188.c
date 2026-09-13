/* QUARANTINE DRAFT -- does not match (188/184 bytes). Verified-correct pieces and
 * the one remaining blocker:
 *
 * RIGHT ALREADY: return type u16 (forces `pop {r1}; bx r1` -- old_agbcc pops the
 * return address into ARG_2=r1 whenever the function returns a value <= 4 bytes,
 * ARG_1=r0 only for void; see tools/agbcc/gcc/thumb.c thumb_exit).
 * The n+3 third argument must be written `((gUnk_0202F240->f8 << 16) + 0x30000) >> 16`
 * (old_agbcc decomposes 0x30000 as movs #0xC0; lsls #10 -- verified; a plain
 * `f8 + 3` to a u16 param gets combined away to `adds #3`).
 * Loop tail must re-read the field every iteration (store in body kills CSE):
 *   `for (i = 0; i < gUnk_0202F240->f8; i++)` gives `ldr r0,[r6]; ldrb r0,[r0,#8]`.
 * Read phase: p = &buf[4]; dest += 3; nested do { } while (k <= 0xF)/(j <= 3) with
 * `acc = (acc * 2) | (*p++ & 1);` (u16 mult pair lsls#17/lsrs#16) and *dest-- = acc.
 * DMA calls: sub_08016F80((u32)buf, 0x0D000000, ...); sub_08016F80(0x0D000000,
 * (u32)buf, 0x44); 0x0D000000 as plain literal (movs #0xD0; lsls #20 emerges).
 *
 * BLOCKER: ROM block 1 (the `if (v >= ...) return 0x80FF` check) keeps its whole
 * chain transient in r0 -- `ldr r0,=g; ldr r0,[r0]; ldrh r0,[r0,#4]` -- and block 2
 * (bcc target) RELOADS `ldr r0,=g; adds r6,r0; ldr r0,[r0]; ldrb r1,[r0,#8]`, with
 * r6 = the loop-invariant address pseudo born IN BLOCK 2. Every C shape tried
 * instead lets the check's obj/address pseudos SPAN the branch: we emit
 * `ldr r5,[r0]; ldrh r1,[r5,#4]; mov ip,r0` and block 2 does `ldrb r1,[r5,#8]`
 * reusing the check's obj, with the address hoisted to ip at the top (extra
 * push {r7} as a result). The sharing is created before allocation (visible in
 * the -dl local-alloc dump: one obj pseudo set in block 0, used in block 2).
 * Tried: volatile cast on the field ((volatile struct RegInfo*)g->f4) -- moves the
 * `mov ip` later but obj still spans; `*(volatile struct RegInfo**)&g` -- folded
 * away by the front end, identical output; u16 lim local (worse: v moves to r2);
 * pp = &gUnk_0202F240 local used by the loop (same span). NOT tried: beating the
 * CSE unit-extension threshold (cse.c continues a unit through labels while
 * nsets*2+next_qty <= max_qty -- adding/removing pseudos in blocks 0-2 may flip
 * it), and re-checking whether the original declared gUnk_0202F240 differently
 * (e.g. extern u32 + casts, as docs/learnings/drafts/sub_08016F80.c does).
 */
#include "global.h"

struct RegInfo
{
    u32 pad0;
    u16 f4;
    u16 pad6;
    u8 f8;
};

extern struct RegInfo *gUnk_0202F240;

void sub_08016F80(u32 a, u32 b, u16 c);

u16 sub_08017000(u16 v, u16 *dest)
{
    u16 buf[0x44];
    u16 *p;
    struct RegInfo **pp;
    u8 i, j, k;
    u16 acc;

    if (v >= (*(volatile struct RegInfo **)&gUnk_0202F240)->f4)
        return 0x80FF;
    pp = &gUnk_0202F240;
    p = &buf[(*pp)->f8 + 1];
    for (i = 0; i < (*pp)->f8; i++) {
        *p-- = v;
        v >>= 1;
    }
    *p-- = 1;
    *p = 1;
    sub_08016F80((u32)buf, 0x0D000000, ((gUnk_0202F240->f8 << 16) + 0x30000) >> 16);
    sub_08016F80(0x0D000000, (u32)buf, 0x44);
    p = &buf[4];
    dest += 3;
    j = 0;
    do {
        acc = 0;
        k = 0;
        do {
            acc = (acc * 2) | (*p++ & 1);
            k++;
        } while (k <= 0xF);
        *dest-- = acc;
        j++;
    } while (j <= 3);
    return 0;
}
