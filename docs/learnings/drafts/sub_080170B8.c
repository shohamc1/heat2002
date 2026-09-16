#include "global.h"

struct UnkF240 {
    u8 filler0[4];
    u16 unk4;
    u8 filler6[8 - 6];
    u8 unk8;
};

extern volatile u32 gUnk_0202F240;
#define Q ((struct UnkF240 *)*(volatile u32 *)0x0202F240)
#define QN ((struct UnkF240 *)*(u32 *)0x0202F240)
extern u8 gUnk_02000498;
extern u16 gUnk_08339404[];
extern void sub_08016F80(u32 a, u32 b, u32 c);
extern void sub_08016ED8(u16 *a);
extern void sub_08016F3C(void);

u16 sub_080170B8(u16 a, u16 *b)
{
    u16 buf[0x52];
    u16 *p;
    u16 v;
    u8 j;
    u8 k;
    u8 i;
    u16 ret;

    if (a >= ((struct UnkF240 *)gUnk_0202F240)->unk4)
        return 0x80FF;
    p = buf + Q->unk8 + 0x42;
    *p-- = 0;
    j = 0;
    do {
        v = *b++;
        k = 0;
        do {
            *p-- = v;
            v >>= 1;
        } while (++k < 0x10);
    } while (++j < 4);
    for (i = 0; i < Q->unk8; i++) {
        *p-- = a;
        a >>= 1;
    }
    *p-- = 0;
    *p = 1;
    sub_08016F80((u32)buf, 0x0D000000, (((u32)Q->unk8 << 16) + 0x430000) >> 16);
    sub_08016ED8(gUnk_08339404);
    ret = 0;
    while ((*(volatile u16 *)0x0D000000 & 1) == 0) {
        if (gUnk_02000498 != 0) {
            if ((*(volatile u16 *)0x0D000000 & 1) == 0)
                ret = 0xC001;
            break;
        }
    }
    sub_08016F3C();
    return ret;
}

/* QUARANTINED — sub_080170B8 (228b) — MISMATCH after ~18 iterations.
 * Structure fully mapped; remaining diffs are register allocation and
 * block-ordering artifacts:
 *
 * 1. gUnk_0202F240 (pointer-holding global) access strategy: target loads
 *    `ldr rX,=0x0202F240` fresh in all 4 regions (its own pool entry per
 *    region, pool entries NOT deduped: 3 copies of 0x0202F240 in pool);
 *    GCC CSEs the address into one pseudo pinned across regions
 *    (callee-saved r6 with symbol extern; r1 with *(cast) form).
 *    Best split found: region1 via symbol extern, region2 via
 *    (volatile u32*)0x0202F240 cast → both fresh ✓, but then region3
 *    (i-loop) has no distinct form left that avoids a CSE with one of them.
 * 2. i-loop preheader: target emits `movs r1,#0; ldr r0,=F240;
 *    adds r2,r0,#0 (fork move idiom); ldr r0,[r0]; b .test` — address
 *    copied to r2 (loop home), value pre-loaded, test block split so the
 *    backedge block does `ldr r0,[r2]` and falls into shared `ldrb/cmp`.
 *    Our for-loop with volatile Q instead: `ldr r3,=F240; b .reloadblk`
 *    with the value reload block at loop head (no preheader value load,
 *    no r0→r2 copy).
 * 3. Outer j-loop: GCC hoists `j++` into the inner-loop preheader
 *    (adds rX,#1 before first strh of k-loop body) in EVERY form tried
 *    (for/for, for/do-while++k, do-while++j/do-while++k); target keeps it
 *    after the inner loop.
 * 4. `p = &buf[Q->unk8] + 0x42` produces an extra `adds r2,r1,#0` copy;
 *    `&buf[x+0x42]` folds the 0x84 into the scaled index too early
 *    (adds r0,#0x84 before the sp add). Target: `lsls r0,#1;
 *    mov r1,sp; adds r3,r0,r1; adds r3,#0x84`.
 * 5. (u32) cast needed on `(Q->unk8 << 16) + 0x430000) >> 16` else GCC
 *    emits asrs (signed) instead of lsrs — fixed in the draft.
 *
 * Matched so far: prologue, a/b homes (adds r5,r1; lsrs r4,r0), the two
 * fill loops' bodies, the *p-- = 0 / *p = 1 stores, the sub_08016F80 call
 * with synthesized 0x0D000000 and ((x<<16)+0x430000)>>16, sub_08016ED8
 * call, and the whole busy-wait tail incl. sub_08016F3C + return.
 */
