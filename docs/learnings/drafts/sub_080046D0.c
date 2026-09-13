/* sub_080046D0 QUARANTINE - remaining diff (batches 1&2, flag logic, masks, all 12 RMWs MATCH):
 * batch3 register permutation only. Target:
 *   ldr r1,=0x020251F0; ldrh r0,[r1]      (address scratch r1, idx3 value r0)
 *   cmp r0; beq end; adds r1,r0           (copy of idx3 -> r1 INSIDE branch)
 *   adds r0,#0x40; lsls r0; adds r0,r7    (j in r0 in-place) ; ldsh r5 (c0=r5 ok)
 *   lsls r1; adds r1,r7; ldsh r2 (B=r2); negs r3 (c2=r3); adds r1,r5 (c3=r1)
 * Mine: address scratch r0, idx3 pin r0 gives value/addr both r0; j lands r1;
 *   B=r1, c2=r2, c3=r3 (rotate). Swept: unpinned idx3 -> value lands r2 (addr r0);
 *   pin idx3 u32 r0 -> copy correctly post-branch, but j stays r1 (target r0);
 *   pin j also r0 -> GCC 2.95 MISCOMPILES (treats same-reg pins as same value,
 *   B loaded from tbl[j] not tbl[idx]); u16 pins -> wrong load widths/copies;
 *   v0 s16 pin r2 -> ldsh becomes ldrh + extra copies; extern-direct table ->
 *   address pool load emitted late (fork behavior); shared idx*2 CSE ->
 *   distributes (idx+0x40)*2 into idx*2+0x80 (needs j-as-variable to block).
 * Pins that WORK (batches 1/2 exact): p=r4, msk=r6, c0=r5, v0(s32)=r2, n=r3.
 * Next idea: find source shape where natural alloc puts idx3 pseudo in r0 so
 * the reload scratch goes r1; j then coalesces r0 after the adds r1,r0 copy.
 */
#include "global.h"

extern u16 gUnk_0202522C;
extern u16 gUnk_02025398;
extern u16 gUnk_020251F0;
extern u8 gUnk_020253C8;
extern u8 gUnk_0202523C;

extern void sub_0800464C(void);

typedef struct {
    u32 a;
    union {
        u32 w;
        struct { u16 lo; u16 hi; } h;
    } u;
} Ent;

extern Ent gUnk_02024830[];
extern s16 gUnk_0801CD08[];

void sub_080046D0(void)
{
    s16 *tbl;
    u16 *pa;
    register Ent *p asm("r4");
    register u32 msk asm("r6");
    register s32 c0 asm("r5");
    s32 j;
    u16 idx;
    register u32 idx3 asm("r0");
    register s32 v0 asm("r2");
    register s32 n asm("r3");
    u32 sv, sn, s1;
    u16 v1;
    s32 B, c1, c2, c3;
    u32 m0, m1, m2, m3;
    u32 t0, t1, t2, t3;

    sub_0800464C();
    tbl = gUnk_0801CD08;
    idx = gUnk_0202522C;
    j = idx + 0x40;
    pa = (u16 *)&tbl[j];
    v0 = tbl[idx];
    n = -v0;
    sv = v0 << 16;
    sn = n << 16;
    v1 = *pa;
    s1 = v1 << 16;
    p = gUnk_02024830;
    p[0].u.w = s1 | p[0].u.h.lo;
    p[1].u.w = sv | p[1].u.h.lo;
    p[2].u.w = sn | p[2].u.h.lo;
    p[3].u.w = s1 | p[3].u.h.lo;

    idx = gUnk_02025398;
    j = idx + 0x40;
    pa = (u16 *)&tbl[j];
    v0 = tbl[idx];
    n = -v0;
    sv = v0 << 16;
    sn = n << 16;
    v1 = *pa;
    s1 = v1 << 16;
    p[4].u.w = s1 | p[4].u.h.lo;
    p[5].u.w = sv | p[5].u.h.lo;
    p[6].u.w = sn | p[6].u.h.lo;
    msk = 0xFFFF;
    p[7].u.w = s1 | p[7].u.h.lo;

    idx3 = gUnk_020251F0;
    if (idx3 != 0) {
        j = idx3 + 0x40;
        c0 = tbl[j];
        B = tbl[idx3];
        c1 = B;
        c2 = -B;
        c3 = c0;
        if (gUnk_020253C8 != 0) {
            c0 = -c3;
            c2 = c1;
        }
        if (gUnk_0202523C != 0) {
            c1 = -c1;
            c3 = -c3;
        }
        m0 = c0 & msk;
        m1 = c1 & msk;
        m2 = c2 & msk;
        m3 = c3 & msk;
        t0 = m0 << 16;
        t1 = m1 << 16;
        t2 = m2 << 16;
        t3 = m3 << 16;
        p[8].u.w = (p[8].u.w & msk) | t0;
        p[9].u.w = (p[9].u.w & msk) | t1;
        p[10].u.w = (p[10].u.w & msk) | t2;
        p[11].u.w = (p[11].u.w & msk) | t3;
    }
}
