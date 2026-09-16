/* QUARANTINE DRAFT -- does not match (190/184 bytes). Closest variant; the
 * remaining diff is ONE allocation decision plus its register fallout:
 *
 * ROM block 1 (check) is fully transient in r0:
 *   ldr r0,=g; ldr r0,[r0]; ldrh r0,[r0,#4]; cmp r3,r0; bcc block2
 * ROM block 2 (bcc target) reloads with a NEW address pseudo:
 *   ldr r0,=g; adds r6,r0; ldr r0,[r0]; ldrb r1,[r0,#8]; lsls r0,r1,#1;
 *   mov r4,sp; adds r2,r0,r4; adds r2,#2; movs r4,#0; cmp r4,r1
 * This draft: the volatile-qualified pointer read `(*(struct RegInfo * volatile
 * *)&gUnk_0202F240)->f4` successfully stops the OBJECT from spanning the branch
 * (block 2 re-loads it), but the ADDRESS constant still spans: we hoist it into
 * ip at the top (`ldr r0,=g; ldr r1,[r0]; mov ip,r0; ldrh r1,[r1,#4]`) and block
 * 2 reads `mov r0,ip; ldr r5,[r0]; ldrb r1,[r5,#8]`, costing an extra push {r7}.
 *
 * VERIFIED PIECES (all match when the address issue is ignored):
 * - return type u16: pop {r1}; bx r1 (thumb_exit pops ARG_2=r1 for any
 *   sub-4-byte return, ARG_1=r0 only for void). Same rule closed sub_08010FE4.
 * - third DMA arg: `((gUnk_0202F240->f8 << 16) + 0x30000) >> 16` reproduces
 *   lsls#16; movs #0xC0; lsls#10; adds; lsrs#16 (old_agbcc decomposes 0x30000
 *   as 0xC0<<10; plain `f8 + 3` is combined away).
 * - loop tail re-reads field each iteration (body strh kills CSE); for-loop
 *   with top pre-check cmp/bcs matches.
 * - read phase: nested do/while, acc = (acc * 2) | (*p++ & 1) gives the
 *   lsls#17/ldrh/ands/lsrs#16/orrs interleave; *dest-- = acc; k<=0xF, j<=3.
 * - 0x0D000000 literal emerges as movs #0xD0; lsls #20.
 *
 * SWEPT on the blocker: plain field access (obj+addr span), volatile field
 * cast (obj spans), volatile pointer read (addr spans via ip), pp=&gUnk local
 * for the loop (same), no-pp + direct (address hoists into block 1, worse:
 * r8 pushed), u16 lim local (v moves to r2), lim+narrowing orders. NOT tried:
 * flipping cse's unit-extension threshold (cse.c continues a unit through
 * labels while nsets*2+next_qty <= max_qty -- adding/removing early-block
 * pseudos may break the block1->block2 constant carry), extern u32 + raw
 * casts for the check (sub_08016F80 draft style).
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

    if (v >= (*(struct RegInfo * volatile *)&gUnk_0202F240)->f4)
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
