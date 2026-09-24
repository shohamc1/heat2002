#include "global.h"
#include "data.h"

extern u16 gUnk_0202522C;
extern u16 gUnk_02025398;
extern u16 gUnk_020251F0;
extern u8 gUnk_020253C8;
extern u8 gUnk_0202523C;

extern void FlushSortedSprites(void);

typedef struct {
    u32 a;
    union {
        u32 w;
        struct { u16 lo; u16 hi; } h;
    } u;
} Ent;

extern Ent gUnk_02024830[];

void sub_080046D0(void)
{
    s16 *tbl;
    u16 *pa;
    register Ent *p asm("r4");
    register u32 msk asm("r6");
    register s32 c0 asm("r5");
    register u32 cur asm("r0");
    s32 j;
    u16 idx;
    register u32 idx3 asm("r0");
    register u16 *idx3p asm("r1");
    u32 idx3copy;
    register s32 v0 asm("r2");
    register s32 n asm("r3");
    u32 sv, sn, s1;
    u16 v1;
    s32 c3;
    u32 m0, m1, m2, m3;
    u32 t0, t1, t2, t3;

    FlushSortedSprites();
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

    idx3p = &gUnk_020251F0;
    idx3 = *idx3p;
    if (idx3 != 0) {
        idx3copy = idx3;
        idx3 += 0x40;
        c0 = tbl[idx3];
        v0 = tbl[idx3copy];
        n = -v0;
        c3 = c0;
        if (gUnk_020253C8 != 0) {
            c0 = -c3;
            n = v0;
        }
        if (gUnk_0202523C != 0) {
            v0 = -v0;
            c3 = -c3;
        }
        m0 = c0 & msk;
        m1 = v0 & msk;
        m2 = n & msk;
        m3 = c3 & msk;
        t0 = m0 << 16;
        t1 = m1 << 16;
        t2 = m2 << 16;
        t3 = m3 << 16;
        cur = p[8].u.w;
        cur &= msk;
        cur |= t0;
        p[8].u.w = cur;
        cur = p[9].u.w;
        cur &= msk;
        cur |= t1;
        p[9].u.w = cur;
        cur = p[10].u.w;
        cur &= msk;
        cur |= t2;
        p[10].u.w = cur;
        cur = p[11].u.w;
        cur &= msk;
        cur |= t3;
        p[11].u.w = cur;
    }
}
